#include "parlex/detail/job.hpp"

#include "parlex/detail/parser.hpp"
#include "parlex/detail/state_machine_base.hpp"
#include "parlex/detail/terminal.hpp"
#include "parlex/detail/token.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/subjob.hpp"
#include "parlex/detail/grammar_base.hpp"
#include <stack>

//#include "logging.hpp"

namespace parlex {
namespace detail {

class producer_table {
public:
	typedef std::atomic<producer *> t;

	size_t const document_length;
	size_t const recognizer_count;

private:
	t * const storage;
	size_t compute_offset(size_t const documentPosition, size_t const recognizerIndex) const {
		throw_assert(documentPosition < document_length);
		throw_assert(recognizerIndex < recognizer_count);
		return documentPosition * recognizer_count + recognizerIndex;
	}

public:
	producer_table(size_t const documentLength, size_t const recognizerCount) : document_length(documentLength), recognizer_count(recognizerCount), storage(static_cast<t *>(malloc(sizeof(t) * documentLength * recognizerCount))) {
		auto const elementCount = document_length * recognizer_count;
		for (size_t i = 0; i < elementCount; ++i) {
			new (storage + i) t();
		}
	}

	~producer_table() {
		auto const elementCount = document_length * recognizer_count;
		for (size_t i = 0; i < elementCount; ++i) {
			storage[i].~t();
		}
		free(storage);
	}

	t & operator()(size_t const documentPosition, size_t const recognizerIndex) const {
		return storage[compute_offset(documentPosition, recognizerIndex)];
	}

	t & operator()(match_class const matchClass) const {
		return operator()(matchClass.document_position, matchClass.recognizer_index);
	}
};

job::job(parser & owner, std::u32string const & document, grammar_base const & g, size_t const rootRecognizerIndex, progress_handler_t const & progressHandler) :
	document(document),
	g(g),
	progress(0),
	owner(&owner),
	producer_table_ptr(new producer_table(document.size(), g.get_recognizer_count())),
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	//because parser::mutex is already locked
	match_class const matchClass(0, rootRecognizerIndex, 0);
	auto & storage = (*producer_table_ptr)(matchClass);
	auto const & root = g.get_recognizer(rootRecognizerIndex);
	if (root.is_terminal()) {
		auto const t = static_cast<terminal const *>(&root);  // NOLINT
		storage = new token(*this, 0, rootRecognizerIndex, *t);
	} else {
		auto const machine = static_cast<state_machine_base const *>(&root);  // NOLINT
		auto result = new subjob(*this, 0, rootRecognizerIndex, *machine);
		storage = result;
		//seed the parser with the root state
		result->begin_work_queue_reference();
		owner.work.emplace_back(&result->construct_start_state_context(0), 0);
		result->finish_creation();
		++owner.active_count;
		// start when parser::mutex is unlocked
		owner.work_cv.notify_one();
	}
}

void job::connect(match_class const & matchClass, context const & c, int const nextDfaState, leaf const * leaf) {
	get_producer(matchClass).add_subscription(c, nextDfaState, leaf);
}

producer & job::get_producer(match_class const & matchClass) {
	auto & storage = (*producer_table_ptr)(matchClass);
	auto resultPtr = static_cast<producer *>(storage);
	if (resultPtr != nullptr) {
		return *resultPtr;
	}
	auto const & r = g.get_recognizer(matchClass.recognizer_index);
	if (r.is_terminal()) {
		auto const t = static_cast<terminal const *>(&r);  // NOLINT
		auto const newTokenPtr = new token(*this, matchClass.document_position, matchClass.recognizer_index, *t);
		if (storage.compare_exchange_strong(resultPtr, newTokenPtr)) {
			return *newTokenPtr;
		}
		delete newTokenPtr;
		return *resultPtr;
	}
	auto const machine = static_cast<state_machine_base const *>(&r);  // NOLINT
	auto newSubjobPtr = new subjob(*this, matchClass.document_position, matchClass.recognizer_index, *machine);
	if (storage.compare_exchange_strong(resultPtr, newSubjobPtr)) {
		newSubjobPtr->start();
		return *newSubjobPtr;
	}
	delete newSubjobPtr; //womp womp womp
	return *resultPtr;
}


void job::update_progress(size_t const completed)
{
	if (progress_handler) {
		size_t oldProgress = progress.load();
		while (!progress_counter.compare_exchange_weak(oldProgress, completed) && oldProgress < completed) {}
		if (oldProgress < completed) {
			progress_handler(completed, document.length());
		}
	}
}

bool job::handle_deadlocks() const {
	//perf_timer timer("handle_deadlocks");

	//build a dependency graph and detect cyclical portions that should be halted
	//if no subjobs remain, return true
	//otherwise return false (still work to be done)

	std::stack<std::pair<match_class, match_class>> s;

	//Examine subscriptions from one subjob to another to construct the graph
	std::map<match_class, std::set<match_class>> directSubscriptions;
	std::map<match_class, std::set<match_class>> allSubscriptions;
	for (size_t documentPosition = 0; documentPosition < producer_table_ptr->document_length; ++documentPosition) {
		for (size_t recognizerIndex = 0; recognizerIndex < producer_table_ptr->recognizer_count; ++recognizerIndex) {
			match_class const matchClass(documentPosition, recognizerIndex, 0);
			auto const & storage = (*producer_table_ptr)(matchClass);
			if (!storage) {
				continue;
			}
			auto const & producer = *storage;
			auto const & recognizer = g.get_recognizer(producer.recognizer_index);
			if (recognizer.is_terminal() || producer.completed) {
				continue;
			}
			for (auto const & subscription : producer.consumers) {
				auto const & c = subscription.c;
				match_class temp(c.owner.document_position, c.owner.recognizer_index, 0);
				allSubscriptions[matchClass].insert(temp);
				directSubscriptions[matchClass].insert(temp);
				s.push(std::pair<match_class, match_class>(matchClass, temp));
			}
		}
	}

	//Apply transitivity to the graph
	while (!s.empty()) {
		auto entry = s.top();
		s.pop();
		for (auto const & next : directSubscriptions[entry.first]) {
			if (allSubscriptions[entry.first].insert(next).second) {
				s.push(std::pair<match_class, match_class>(entry.first, next));
			}
		}
	}

	auto anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & i : allSubscriptions) {
		auto const & matchClass = i.first;
		auto & p = *(*producer_table_ptr)(matchClass);
		if (i.second.count(matchClass) > 0) {
			p.terminate();
			anyHalted = true;
		}
	}
	return !anyHalted;
}

//Construct an ASS, and if a solution was found, prunes unreachable nodes
abstract_syntax_semilattice job::construct_result(match const & m) {
	//perf_timer timer("construct_result");
	auto result = abstract_syntax_semilattice(m);
	for (size_t documentPosition = 0; documentPosition < producer_table_ptr->document_length; ++documentPosition) {
		for (size_t recognizerIndex = 0; recognizerIndex < producer_table_ptr->recognizer_count; ++recognizerIndex) {
			match_class const matchClass(documentPosition, recognizerIndex, 0);
			auto const & storage = (*producer_table_ptr)(matchClass);
			if (!storage) {
				continue;
			}
			auto const & producer = *storage;
			for (auto const & pair2 : producer.match_to_permutations) {
				auto const & n = match(pair2.first);
				auto const & permutations = pair2.second;
				result.permutations_of_matches[n] = permutations;
			}
		}
	}

	delete producer_table_ptr;
	producer_table_ptr = nullptr;

	if (result.is_rooted()) {
		result.prune_detached();
		parser::apply_precedence_and_associativity(g, result);
		result.prune_detached();
	}
	return result;
}


abstract_syntax_semilattice job::construct_result_and_postprocess(size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document) {
	auto result = construct_result(match(match_class(0, overrideRootRecognizerIndex, 0), document.size()));
	if (!posts.empty()) {
		for (auto const & post : posts) {
			post(result);
		}
		if (result.is_rooted()) {
			result.prune_detached();
		}
	}
	return result;
}

}
}
