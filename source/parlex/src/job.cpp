#include "parlex/detail/job.hpp"

// ReSharper disable once CppUnusedIncludeDirective
#include "perf_timer.hpp"
#include "tarjan.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/match_class.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/producer_table.hpp"
#include "parlex/detail/state_machine.hpp"
#include "parlex/detail/subjob.hpp"
#include "parlex/detail/terminal.hpp"
#include "parlex/detail/token.hpp"

//#include "logging.hpp"

namespace parlex {
namespace detail {

job::job(parser & owner, std::u32string const & document, grammar const & g, uint16_t const rootRecognizerIndex, progress_handler_t const & progressHandler) :
	document(document),
	g(g),
	progress(0),
	owner(&owner),
	producer_table_ptr(new producer_table(uint32_t(document.size()), g.get_recognizer_count())),
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	//because parser::mutex is already locked
	match_class const matchClass(0, rootRecognizerIndex);
	auto const rootProducerId = producer_table_ptr->compute_id(matchClass);
	auto & storage = (*producer_table_ptr)(rootProducerId);
	auto const & root = g.get_recognizer(rootRecognizerIndex);
	if (root.is_terminal()) {
		auto const t = static_cast<terminal const *>(&root);  // NOLINT
		storage = new token(*this, matchClass, *t);
	} else {
		auto const machine = static_cast<state_machine const *>(&root);  // NOLINT
		auto result = new subjob(*machine);
		storage = result;
		//seed the parser with the root state
		result->begin_work_queue_reference();
		owner.work.emplace_back(rootProducerId, &result->construct_start_state_context(0), machine->get_start_state());
		result->finish_creation(*this, rootProducerId);
		++owner.active_count;
		// start when parser::mutex is unlocked
		owner.work_cv.notify_one();
	}
}

void job::connect(match_class const & matchClass, uint32_t const subscriber, context const & c, uint8_t const nextState, leaf const * l) {
	get_producer(matchClass).add_subscription(*this, matchClass, subscriber, c, nextState, l);
}

match_class job::get_match_class(uint32_t const id) const {
	return producer_table_ptr->get_match_class(id);
}

producer & job::optimized_get_producer(uint32_t const & id, match_class const & matchClass) {
	auto & storage = (*producer_table_ptr)(id);
	auto resultPtr = static_cast<producer *>(storage);
	if (resultPtr != nullptr) {
		return *resultPtr;
	}
	auto const & r = g.get_recognizer(matchClass.recognizer_index);
	if (r.is_terminal()) {
		auto const & t = *static_cast<terminal const *>(&r);  // NOLINT
		auto const newTokenPtr = new token(*this, matchClass, t);
		if (storage.compare_exchange_strong(resultPtr, newTokenPtr)) {
			return *newTokenPtr;
		}
		delete newTokenPtr;
		return *resultPtr;
	}
	auto const machine = static_cast<state_machine const *>(&r);  // NOLINT
	auto newSubjobPtr = new subjob(*machine);
	if (storage.compare_exchange_strong(resultPtr, newSubjobPtr)) {
		newSubjobPtr->start(*this, id, matchClass.document_position);
		return *newSubjobPtr;
	}
	delete newSubjobPtr; //womp womp womp
	return *resultPtr;
}

producer & job::get_producer(match_class const & matchClass) {
	return optimized_get_producer(producer_table_ptr->compute_id(matchClass), matchClass);
}

producer & job::get_producer(uint32_t const & id) {
	auto & storage = (*producer_table_ptr)(id);
	auto const resultPtr = static_cast<producer *>(storage);
	if (resultPtr != nullptr) {
		return *resultPtr;
	}
	return optimized_get_producer(id, producer_table_ptr->get_match_class(id));
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

bool job::handle_deadlocks() {
	perf_timer perf(__func__);
	using iterator_t = std::atomic<producer *> const *;

	struct transition_function {
		producer_table const & table;
		job const & j;

		explicit transition_function(detail::producer_table const & producerTable, job const & j) : table(producerTable), j(j) {}

		std::vector<iterator_t> operator()(iterator_t const & i) const {
			std::vector<iterator_t> results;
			producer const * producerPtr = i->load();
			if (producerPtr != nullptr) {
				for (auto const & subscription : producerPtr->consumers) {
					iterator_t subscribedProducerPtrAtomicPtr = &table(subscription.id);
					producer * subscribedProducerPtr = *subscribedProducerPtrAtomicPtr;
					if (subscribedProducerPtr != nullptr) {
						throw_assert(!subscribedProducerPtr->completed);
						//auto const & r = j.g.get_recognizer(subscribedProducerPtr->recognizer_index);
						//throw_assert(!r.is_terminal());
						results.push_back(subscribedProducerPtrAtomicPtr);
					}
				}
			}
			return results;
		}
	};

	transition_function const f(*producer_table_ptr, *this);
	auto stronglyConnectedComponents = tarjan(producer_table_ptr->cbegin(), producer_table_ptr->cend(), f, true);

	auto anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & stronglyConnectedComponent : stronglyConnectedComponents) {
		for (auto ptr : stronglyConnectedComponent) {
			size_t const producerIdId = ptr - producer_table_ptr->cbegin(); // pointer arithmetic
			auto const producerId(producerIdId);
			ptr->load()->terminate(*this, get_match_class(producerId));
			anyHalted = true;
		}
	}

	return !anyHalted;
}

//Construct an ASS, and if a solution was found, prunes unreachable nodes
abstract_syntax_semilattice job::construct_result(match const & m) {
	//perf_timer timer(__FUNCTION__);
	auto result = abstract_syntax_semilattice(m);
	{
		perf_timer timer2("consruct_result:subjobs to assl");
		for (uint32_t documentPosition = 0; documentPosition < producer_table_ptr->document_length; ++documentPosition) {
			for (uint16_t recognizerIndex = 0; recognizerIndex < producer_table_ptr->recognizer_count; ++recognizerIndex) {
				match_class const matchClass(documentPosition, recognizerIndex);
				auto const & storage = (*producer_table_ptr)(matchClass);
				if (!storage) {
					continue;
				}
				auto const & producer = *storage;
				for (auto const & pair2 : producer.match_length_to_permutations) {
					auto const matchLength = pair2.first;
					match const n(documentPosition, recognizerIndex, matchLength);
					auto const & permutations = pair2.second;
					result.permutations_of_matches[n] = permutations;
				}
			}
		}
	}

	producer_table_ptr.reset();

	if (result.is_rooted()) {
		result.prune_detached();
		parser::apply_precedence_and_associativity(g, result);
		result.prune_detached();
	}
	return result;
}


abstract_syntax_semilattice job::construct_result_and_postprocess(uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document) {
	//perf_timer perf(__func__);
	auto result = construct_result(match(0, overrideRootRecognizerIndex, document.size()));
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
