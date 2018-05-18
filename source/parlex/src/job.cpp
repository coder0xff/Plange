#include "parlex/detail/job.hpp"

// ReSharper disable once CppUnusedIncludeDirective
#include "perf_timer.hpp"
#include "tarjan.hpp"

#include "parlex/detail/configuration.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/match_class.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/producer_table.hpp"
#include "parlex/detail/acceptor.hpp"
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
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	//because parser::mutex is already locked
	match_class const matchClass(0, rootRecognizerIndex);
	auto & storage = producers[matchClass];
	auto const & root = g.get_recognizer(rootRecognizerIndex);
	if (root.is_terminal()) {
		auto const t = static_cast<terminal const *>(&root);  // NOLINT
		storage = new token(*this, matchClass, *t);
	} else {
		auto const machine = static_cast<acceptor const *>(&root);  // NOLINT
		auto result = new subjob(*machine);
		storage = result;
		//seed the parser with the root state
		result->begin_work_queue_reference();
		configuration const c = result->construct_start_state_configuration(0);
		uint8_t startState = machine->get_start_state();
		owner.work.emplace_back(matchClass, c);
		result->finish_creation(*this, matchClass);
		++owner.active_count;
		// start when parser::mutex is unlocked
		owner.work_cv.notify_one();
	}
}

void job::connect(match_class const & requestedMatchClass, subjob & subscriber, match_class const & subscriberId, uint8_t const nextState, leaf const * l, transition_record const * history) {
	get_producer(requestedMatchClass).add_subscription(nextState, l, history, subscriber, subscriberId, requestedMatchClass, *this);
}

producer & job::get_producer(match_class const & matchClass) {
	std::unique_lock<std::mutex> lock(producers_mutex);
	auto & storage = producers[matchClass];
	if (storage == nullptr) {
		auto const & r = g.get_recognizer(matchClass.recognizer_index);
		if (r.is_terminal()) {
			auto const & t = *static_cast<terminal const *>(&r);  // NOLINT
			storage = new token(*this, matchClass, t);
		} else {
			auto const machine = static_cast<acceptor const *>(&r);  // NOLINT
			auto newSubjobPtr = new subjob(*machine);
			storage = newSubjobPtr;
			lock.unlock();
			newSubjobPtr->start(*this, matchClass);
		}
	}
	return *storage;
}

void job::update_progress(uint32_t const completed)
{
	if (progress_handler) {
		uint32_t oldProgress = progress.load();
		while (!progress_counter.compare_exchange_weak(oldProgress, completed) && oldProgress < completed) {}
		if (oldProgress < completed) {
			progress_handler(completed, uint32_t(document.length()));
		}
	}
}

void job::fast_breakout() {
	for (auto & pair : producers) {
		auto const & matchClass = pair.first;
		auto & producer = *pair.second;
		if (g.is_recognizer_left_recursive(matchClass.recognizer_index)) {
			producer.terminate(*this, matchClass);
		}
	}
}

bool job::full_breakout() {
	std::vector<match_class> vertices;
	std::map<match_class, size_t> lookup;
	for (auto const & pair : producers) {
		auto const & matchClass = pair.first;
		auto const & producer = *pair.second;
		if (producer.completed) {
			continue;
		}
		lookup[matchClass] = vertices.size();
		vertices.push_back(matchClass);
	}

	std::function<std::vector<size_t> (size_t)> const edgeFunctor = [&](size_t vertexIndex){
		auto const & matchClass = vertices[vertexIndex];
		auto const & producer = producers.find(matchClass)->second;
		std::vector<size_t> results;
		for (auto const & subscription : producer->consumers) {
			if (get_producer(subscription.subscriber_id).completed) {
				continue;
			}
			results.push_back(lookup.find(subscription.subscriber_id)->second);
		}
		return results;
	};

	auto stronglyConnectedComponents = tarjan(vertices.size(), edgeFunctor, true);

	auto anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & stronglyConnectedComponent : stronglyConnectedComponents) {
		for (auto vertexIndex: stronglyConnectedComponent) {
			auto const & matchClass = vertices[vertexIndex];
			get_producer(matchClass).terminate(*this, matchClass);
			anyHalted = true;
		}
	}

	return !anyHalted;
}

bool job::handle_deadlocks() {
	//perf_timer perf(__func__);

	fast_breakout();

	// Did fast_breakout free up any nodes to do some work?
	if (!owner->work.empty()) {
		return false;
	}

	return full_breakout();
}

//Construct an ASS, and if a solution was found, prunes unreachable nodes
abstract_syntax_semilattice job::construct_result(match const & m) {
	//perf_timer timer(__FUNCTION__);
	auto result = abstract_syntax_semilattice(m);
	for (auto const & pair : producers) {
		auto const & matchClass = pair.first;
		auto const & p = *pair.second;
		for (auto const & pair2 : p.match_length_to_derivations) {
			auto const matchLength = pair2.first;
			match const n(matchClass, matchLength);
			auto const & derivations = pair2.second;
			result.derivations_of_matches[n] = derivations;
		}
	}

	for (auto entry : producers) {
		delete entry.second;
	}
	producers.clear();

	if (result.is_rooted()) {
		result.prune_detached();
		parser::apply_precedence_and_associativity(g, result);
		result.prune_detached();
	}
	return result;
}


abstract_syntax_semilattice job::construct_result_and_postprocess(uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document) {
	//perf_timer perf(__func__);
	auto result = construct_result(match(0, overrideRootRecognizerIndex, uint32_t(document.size())));
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
