#include <cassert>
#include <stack>

#include "parlex/details/subjob.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/context.hpp"
#include "parlex/permutation.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/producer.hpp"
//#include "logging.hpp"
//#include "perf_timer.hpp"

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
					if (update_progress_handler) {
						std::atomic<int> & progress = context.owner().owner.progress;
						int oldProgress;
						bool didSet = false;
						int const docPos = context.current_document_position();
						while (docPos > (oldProgress = progress)) {
							didSet = progress.compare_exchange_weak(oldProgress, docPos);
						}
						if (didSet) {
							int const docLen = context.owner().owner.document.length();
							update_progress_handler(docPos, docLen + 1);
						}
					}
					//INF("thread ", threadCount, " executing dfa state");
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

abstract_syntax_graph construct_result(details::job const & j, match const & m);

abstract_syntax_graph parser::parse(grammar const & g, recognizer const & r, std::u32string const & document) {
	//perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	details::job j(*this, document, g, r);
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
	if (update_progress_handler) {
		update_progress_handler(document.length() + 1, document.length() + 1);
	}
	return construct_result(j, match(match_class(r, 0), document.size()));
}

abstract_syntax_graph parser::parse(grammar const & g, std::u32string const & document) {
	return parse(g, g.get_main_production(), document);
}

void parser::schedule(details::context_ref const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.get_id(), " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
#ifndef FORCE_RECURSION
	++activeCount;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace(std::make_tuple(c, nextDfaState));
	work_cv.notify_one();
#else
	c.owner().machine.process(c, nextDfaState);
#endif
}

void parser::set_update_progress_handler(std::function<void(int /*done*/, int /*total*/)> func)
{
	update_progress_handler = func;
}

bool parser::handle_deadlocks(details::job const & j) const {
	assert(activeCount == 0);
	//perf_timer timer("handle_deadlocks");

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

bool matches_intersect(match const & left, match const & right) {
	return
		left.document_position < (right.document_position + right.consumed_character_count) &&
		(left.document_position + left.consumed_character_count) > right.document_position;
}

std::set<match> getChildren(abstract_syntax_graph const & asg, match const & m) {
	std::set<match> result;
	auto i = asg.permutations.find(m);
	if (i == asg.permutations.end()) {
		return std::set<match>();
	}
	for (permutation const & perm : i->second) {
		for (match const & n : perm) {
			result.insert(n);
		}
	}
	return result;
}

struct node_props_t {
	match const m;
	recognizer const & r;
	std::set<permutation> & permutations;
	std::set<match> children;
	std::map<match, std::set<permutation>> parentPermutationsByMatch;
	size_t height;
	std::set<match> allDescendents;
	std::set<match> allAncestors;
	std::set<match> allDescendentsAndAncestors;
	std::set<match> allIntersections;
	bool selected;


	inline node_props_t(abstract_syntax_graph & asg, match const & m) : m(m), r(m.r), permutations(asg.permutations[m]), children(getChildren(asg, m)), height(0), selected(false) {}
};

void prune(abstract_syntax_graph & asg, std::map<match, node_props_t> & nodes, node_props_t & props) {
	std::queue<match> toPrune;
	std::set<match> completed;
	std::function<void(match const &)> add = [&] (match const & m) {
		if (completed.insert(m).second) {
			toPrune.push(m);
		}
	};
	add(props.m);
	while (!toPrune.empty()) {
		match thisMatch = toPrune.front();
		node_props_t & thisNode = nodes.find(thisMatch)->second;
		toPrune.pop();
		for (auto const & parentMatchAndPermutations : thisNode.parentPermutationsByMatch) {
			match const & parentMatch = parentMatchAndPermutations.first;
			auto const i = nodes.find(parentMatch);
			assert(i != nodes.end());
			node_props_t & parentProps = i->second;
			std::set<permutation> const & parentPermutations = parentMatchAndPermutations.second;
			for (permutation const & perm : parentPermutations) {
				parentProps.permutations.erase(perm);
				if (parentProps.permutations.size() == 0) {
					add(parentMatch);
				}
			}
		}
		for (match const & descendentMatch : thisNode.allDescendents) {
			auto const i = nodes.find(descendentMatch);
			assert(i != nodes.end());
			node_props_t & descendent = i->second;
			descendent.allAncestors.erase(thisMatch);
			if (descendent.allAncestors.empty()) {
				add(descendentMatch);
			}
			descendent.allDescendentsAndAncestors.erase(thisMatch);
			descendent.parentPermutationsByMatch.erase(thisMatch);
		}
		for (match const & ancestorMatch : thisNode.allAncestors) {
			auto const i = nodes.find(ancestorMatch);
			assert(i != nodes.end());
			node_props_t & ancestor = i->second;
			ancestor.allDescendents.erase(thisMatch);
			ancestor.allDescendentsAndAncestors.erase(thisMatch);
			ancestor.children.erase(thisMatch);
		}
		for (match const & intersectorMatch : thisNode.allIntersections) {
			auto const i = nodes.find(intersectorMatch);
			assert(i != nodes.end());
			node_props_t & intersector = i->second;
			intersector.allIntersections.erase(thisMatch);
		}
	}

	for (match const & i : completed) {
		nodes.erase(i);
		asg.permutations.erase(i);
	}
}

void construct_nodes(abstract_syntax_graph & asg, std::map<match, node_props_t> & nodes, std::vector<std::set<node_props_t *>> & flattened) {
	for (auto const & entry : asg.permutations) {
		match const & m = entry.first;
		node_props_t & nodeProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(m), std::forward_as_tuple(asg, m)).first->second;

		for (permutation const & perm : nodeProps.permutations) {
			for (match const & child : perm) {
				node_props_t & childProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(child), std::forward_as_tuple(asg, child)).first->second;
				if (childProps.permutations.empty()) {
					childProps.height = 0;
				}
				childProps.parentPermutationsByMatch[nodeProps.m].insert(perm);
			}
		}
		size_t const afterIndex = nodeProps.m.document_position + nodeProps.m.consumed_character_count;
		for (size_t i = nodeProps.m.document_position; i < afterIndex; ++i) {
			flattened[i].insert(&nodeProps);
		}
	}
}

void resolve_nodes(std::map<match, node_props_t> & nodes) {
	//work queue for the algorithm
	std::queue<std::tuple<node_props_t *, node_props_t *, int>> propertyResolveQueue;

	for (auto & entry : nodes) {
		node_props_t & props = entry.second;
		//seed algorithm with "match A has all of match A's permutation's matches as descendants"
		propertyResolveQueue.push(std::make_tuple(&props, &props, 0));
	}

	//containment algorithm
	//match A contains all of match B's permutation's matches
	while (!propertyResolveQueue.empty()) {
		std::tuple<node_props_t *, node_props_t *, int> entry = propertyResolveQueue.front();
		propertyResolveQueue.pop();
		node_props_t & left = *std::get<0>(entry);
		node_props_t & right = *std::get<1>(entry);
		size_t const leftsHeightMinusRightsHeight = std::get<2>(entry);
		if (right.height == 0) { //if right is a leaf
			left.height = std::max(leftsHeightMinusRightsHeight, left.height);
		}
		for (permutation const & perm : right.permutations) {
			for (match const & containedMatch : perm) {
				node_props_t & childProps = nodes.find(containedMatch)->second;
				if (left.allDescendents.insert(childProps.m).second) {
					propertyResolveQueue.push(std::make_tuple(&left, &nodes.find(containedMatch)->second, leftsHeightMinusRightsHeight + 1));
				}
				childProps.allAncestors.insert(left.m);
				childProps.allDescendentsAndAncestors.insert(left.m);
				left.allDescendentsAndAncestors.insert(childProps.m);
			}
		}
	}
}

void compute_intersections(std::vector<std::set<node_props_t *>> const & flattened) {
	for (size_t i = 0; i < flattened.size(); ++i) {
		std::set<node_props_t *>::iterator iterEnd = flattened[i].end();
		for (std::set<node_props_t *>::iterator j = flattened[i].begin(); j != iterEnd; ++j) {
			node_props_t & left = **j;
			std::set<node_props_t *>::iterator k = j;
			++k;
			for (; k != iterEnd; ++k) {
				node_props_t & right = **k;
				if (left.allDescendentsAndAncestors.count(right.m) == 0) {
					left.allIntersections.insert(right.m);
					right.allIntersections.insert(left.m);
				}
			}
		}
	}
}

void prune_detached(abstract_syntax_graph & asg) {
	std::set<match> unconnecteds;
	for (auto const & entry : asg.permutations) {
		unconnecteds.insert(entry.first);
	}
	std::queue<match> pending;
	unconnecteds.erase(asg.root);
	pending.push(asg.root);
	while (!pending.empty()) {
		match m = pending.front();
		pending.pop();
		for (auto const & permutation : asg.permutations[m]) {
			for (auto const & child : permutation) {
				if (unconnecteds.erase(child) > 0) {
					pending.push(child);
				}
			}
		}
	}
	for (auto const & unconnected : unconnecteds) {
		asg.permutations.erase(unconnected);
	}
}

std::vector<std::set<match>> ordered_matches_by_height(std::map<match, node_props_t> & nodes) {
	std::vector<std::set<match>> orderedMatchesByHeight;
	for (auto & entry : nodes) {
		node_props_t & node = entry.second;
		if (orderedMatchesByHeight.size() <= node.height) {
			orderedMatchesByHeight.resize(node.height + 1);
		}
		orderedMatchesByHeight[node.height].insert(node.m);
	}
	return orderedMatchesByHeight;
}

bool precedence_test(grammar const & g, node_props_t & a, node_props_t & b)
{
	if (&a.m.r == &b.m.r) {
		return false;
	}
	return g.test_precedence(*dynamic_cast<state_machine const *>(&a.m.r), *dynamic_cast<state_machine const *>(&b.m.r));
}

bool associativity_test(node_props_t & a, node_props_t & b) {
	if (&a.m.r != &b.m.r) {
		return false;
	}
	associativity const assoc = dynamic_cast<state_machine const *>(&a.m.r)->get_associativity();
	switch (assoc) {
	case left:
	case any:
		return a.m.document_position < b.m.document_position;
	case right:
		return a.m.document_position > b.m.document_position;
	case none:
		return false;
	}
	throw std::domain_error("Invalid associativity value");
}

void select_trees(abstract_syntax_graph & asg, grammar const & g, std::map<match, node_props_t> & nodes, std::vector<std::set<match>> orderedMatchesByHeight) {
	for (size_t height = 0; height < orderedMatchesByHeight.size(); ++height) {
		std::set<match> const & matches = orderedMatchesByHeight[height];
		for (match const & m : matches) {
			bool anyPermutationSelected = false;
			node_props_t * a = nullptr;
			std::set<match> preservedIntersections; //used towards the end, but needs to be initialized before "goto matchLoop"
			auto const & i = nodes.find(m);
			if (i == nodes.end()) {
				goto matchLoop;
			}
			a = &i->second;
			if (a->r.is_terminal()) {
				a->selected = true;
				continue;
			}
			//are any of those permutations comprised of selected children?
			for (permutation const & p : a->permutations) {
				bool permutationSelected = true;
				for (match const & child : p) {
					node_props_t const & childProps = nodes.find(child)->second;
					if (!childProps.selected) {
						permutationSelected = false;
						break;
					}
				}
				if (permutationSelected) {
					anyPermutationSelected = true;
					break;
				}
			}
			if (!anyPermutationSelected) {
				goto matchLoop;
			}
			//is it possibly preempted by another match that it intersects with?
			for (match const & intersected : a->allIntersections) {
				auto pair = nodes.find(intersected);
				assert(pair != nodes.end());
				node_props_t & b = pair->second;
				if (precedence_test(g, b, *a) || associativity_test(b, *a)) {
					prune(asg, nodes, *a);
					goto matchLoop;
				}
			}

			a->selected = true;
			preservedIntersections = a->allIntersections;
			for (match const & intersected : preservedIntersections) {
				auto const & pair = nodes.find(intersected);
				if (pair == nodes.end()) {
					continue;
				}
				node_props_t & b = pair->second;
				if (precedence_test(g, *a, b) || associativity_test(*a, b)) {
					//if it must be selected, then precedence and associativity must remove preempted intersections
					prune(asg, nodes, b);
				}
			}
		matchLoop:
			;
		}
	}
}

abstract_syntax_graph & apply_precedence_and_associativity(grammar const & g, abstract_syntax_graph & asg) {
	//short circuit if no rules are given
	bool anyAssociativities = false;
	for (auto const & entry : g.get_productions()) {
		anyAssociativities = entry.second.get_associativity() != none;
	}
	if (g.get_precedences().size() == 0 && !anyAssociativities) {
		return asg;
	}

	std::map<match, node_props_t> nodes;
	//a per-character table of matches
	std::vector<std::set<node_props_t *>> flattened;
	flattened.resize(asg.root.consumed_character_count);

	construct_nodes(asg, nodes, flattened);
	resolve_nodes(nodes);
	compute_intersections(flattened);
	asg.matchesByHeight = ordered_matches_by_height(nodes);
	select_trees(asg, g, nodes, asg.matchesByHeight);
	asg.matchesByHeight = ordered_matches_by_height(nodes);
	return asg;
}

//Construct an ASG, and if a solution was found, prunes unreachable nodes
abstract_syntax_graph construct_result(details::job const & j, match const & m) {
	//perf_timer timer("construct_result");
	abstract_syntax_graph result(m);
	for (auto const & pair : j.producers) {
		details::producer const & producer = *pair.second;
		for (auto const & pair2 : producer.match_to_permutations) {
			struct match const & n = pair2.first;
			std::set<permutation> const & permutations = pair2.second;
			result.permutations[n] = permutations;
		}
	}
	if (result.is_rooted()) {
		prune_detached(result);
		return apply_precedence_and_associativity(j.g, result);
	}
	return result;
}

}
