#include <cassert>

#include "parlex/details/subjob.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/context.hpp"
#include "parlex/permutation.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/producer.hpp"
#include "parlex/details/logging.hpp"

//#define FORCE_RECURSION

namespace parlex {

parser::parser(int threadCount) : activeCount(0), terminating(false) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					DBG("THREAD ", threadCount, " POPPING ITEM");
					std::tuple<details::context_ref, int> & item = work.front();
					work.pop();
					lock.unlock();
					auto const & context = std::get<0>(item);
					auto const nextDfaState = std::get<1>(item);
					//DBG("thread ", threadCount, " executing dfa state");
					context.owner().machine.process(context, nextDfaState);
					context.owner().end_dependency(); //reference code A
					if (--activeCount == 0) {
						halt_cv.notify_one();
					}
					lock.lock();
				}
wait:
				work_cv.wait(lock, [this]() { return work.size() > 0 || terminating; });
			}
		});
	}
}

parser::~parser() {
	terminating = true;
	work_cv.notify_all();
	for (auto & thread : workers) {
		thread.join();
	}
}

abstract_syntax_graph parser::parse(recognizer const & r, std::u32string const & document) {
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	details::job j(*this, document, r);
#ifndef FORCE_RECURSION
	assert(activeCount > 0);
#endif
	while (true) {
		halt_cv.wait(lock, [this](){ return activeCount == 0; });
		DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	};
	assert(activeCount == 0);
	return construct_result(j, match(match_class(r, 0), document.size()));
}

void parser::schedule(details::context_ref const & c, int nextDfaState) {
	DBG("scheduling m: ", c.owner().machine.get_id(), " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
#ifndef FORCE_RECURSION
	activeCount++;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace(std::make_tuple(c, nextDfaState));
	work_cv.notify_one();
#else
	c.owner().machine.process(c, nextDfaState);
#endif
}

abstract_syntax_graph parser::construct_result(details::job const & j, match const & match) {
	abstract_syntax_graph result(match);
	for (auto const & pair : j.producers) {
		details::producer const & producer = *pair.second;
		for (auto const & pair2 : producer.match_to_permutations) {
			struct match const & match = pair2.first;
			std::set<permutation> const & permutations = pair2.second;
			result.table[match] = permutations;
		}
	}
	return result;
}

bool parser::handle_deadlocks(details::job const & j) {
	return true;
	assert(activeCount == 0);
	//build a dependency graph and detect cyclical portions that should be halted
	//if no subjobs remain, return true
	//otherwise return false (still work to be done)

	//Examine subscriptions from one subjob to another to construct the graph
	std::map<match_class, std::set<match_class>> all_subscriptions;
	std::set<match_class> growing;
	for (auto const & i : j.producers) {
		match_class const & matchClass = i.first;
		details::producer const & p = *i.second;
		if (p.r.is_terminal() || p.completed) {
			continue;
		}
		for (auto const & subscription : p.consumers) {
			details::context_ref const & c = subscription.c;
			match_class temp(c.owner().machine, c.current_document_position());
			all_subscriptions[matchClass].insert(temp);
		}
		growing.insert(matchClass);
	}

	//Apply transitivity to the graph
	while (growing.size() > 0) {
		std::set<match_class> nextGrowing;
		for (auto const & i : all_subscriptions) {
			match_class const & matchClassA = i.first;
			for (auto const & matchClassB : i.second) {
				for (auto const & matchClassC : all_subscriptions[matchClassB]) {
					if (all_subscriptions[matchClassA].insert(matchClassC).second) {
                        nextGrowing.insert(matchClassA);
					}
				}
			}
		}
		std::swap(growing, nextGrowing);
	}

    bool anyHalted = false;
	//halt subjobs that are subcribed to themselves (in)directly
	for (auto const & i : all_subscriptions) {
		match_class const & matchClass = i.first;
		details::subjob & sj = *(details::subjob*)&(j.producers.find(matchClass)->second);
		if (i.second.count(matchClass) > 0) {
			sj.terminate();
			anyHalted = true;
		}
	}
	return !anyHalted;
}

}
