#include <cassert>
#include <stack>

#include "parlex/details/subjob.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/context.hpp"
#include "parlex/permutation.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/producer.hpp"
#include "parlex/details/logging.hpp"
#include "parlex/details/perf_timer.hpp"

//#define FORCE_RECURSION

namespace parlex {

parser::parser(int threadCount) : activeCount(0), terminating(false) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			//DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					//DBG("THREAD ", threadCount, " POPPING ITEM");
					std::tuple<details::context_ref, int> item = work.front();
					work.pop();
					lock.unlock();
					auto const & context = std::get<0>(item);
					auto const nextDfaState = std::get<1>(item);
					////DBG("thread ", threadCount, " executing dfa state");
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
	perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	details::job j(*this, document, r);
#ifndef FORCE_RECURSION
	assert(activeCount > 0);
#endif
	while (true) {
		halt_cv.wait(lock, [this](){ return activeCount == 0; });
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	};
	assert(activeCount == 0);
	return construct_result(j, match(match_class(r, 0), document.size()));
}

void parser::schedule(details::context_ref const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.get_id(), " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
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
	perf_timer timer("construct_result");
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
	assert(activeCount == 0);
	perf_timer timer("handle_deadlocks");

	//build a dependency graph and detect cyclical portions that should be halted
	//if no subjobs remain, return true
	//otherwise return false (still work to be done)

	std::stack<std::pair<match_class, match_class>> s;

	//Examine subscriptions from one subjob to another to construct the graph
	std::map<match_class, std::set<match_class>> direct_subscriptions;
	std::map<match_class, std::set<match_class>> all_subscriptions;
	for (auto const & i : j.producers) {
		match_class const & matchClass = i.first;
		details::producer const & p = *i.second;
		if (p.r.is_terminal() || p.completed) {
			continue;
		}
		for (auto const & subscription : p.consumers) {
			details::context_ref const & c = subscription.c;
			match_class temp(c.owner().machine, c.owner().documentPosition);
			all_subscriptions[matchClass].insert(temp);
			direct_subscriptions[matchClass].insert(temp);
			s.push(std::pair<match_class, match_class>(matchClass, temp));
		}
	}

	//Apply transitivity to the graph
	while (s.size() > 0) {
		std::pair<match_class, match_class> entry = s.top();
		s.pop();
		for (auto const & next : direct_subscriptions[entry.first]) {
			if (all_subscriptions[entry.first].insert(next).second) {
				s.push(std::pair<match_class, match_class>(entry.first, next));
			};
		}
	}

    bool anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & i : all_subscriptions) {
		match_class const & matchClass = i.first;
		details::producer &p = *j.producers.find(matchClass)->second;
		if (i.second.count(matchClass) > 0) {
			p.terminate();
			anyHalted = true;
		}
	}
	return !anyHalted;
}

}
