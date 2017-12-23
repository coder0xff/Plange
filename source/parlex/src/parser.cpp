#include "parlex/detail/parser.hpp"

#include <stack>

#include "parlex/post_processor.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/grammar_base.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/permutation.hpp"
#include "parlex/detail/producer.hpp"
#include "parlex/detail/subjob.hpp"

#include "utils.hpp"
#include <iterator>

namespace parlex {
namespace detail {

void parser::start_workers(int threadCount) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			//DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					//DBG("THREAD ", threadCount, " POPPING ITEM");
					auto item = work.pop();
					lock.unlock();
					auto const & c = *std::get<0>(item);
					auto const nextDfaState = std::get<1>(item);
					update_progress(c);
					//INF("thread ", threadCount, " executing DFA state");	
					c.owner.machine.process(c, nextDfaState);
					c.owner.end_work_queue_reference();
					if (--active_count == 0) {
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

parser::parser(unsigned const threadCount) : single_thread_mode(threadCount == 1), active_count(0), terminating(false) {
	if (!single_thread_mode) {
		start_workers(threadCount);
	}
}

parser::~parser() {
	terminating = true;
	work_cv.notify_all();
	for (auto & thread : workers) {
		thread.join();
	}
}

abstract_syntax_semilattice parser::construct_result_and_postprocess(recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, job & j) {
	auto result = construct_result(j, match(match_class(overrideMain, 0), document.size()));
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

void parser::complete_progress_handler(job & j) {
	j.update_progress(j.document.length());
}

void parser::update_progress(context const & context) {
	context.owner.owner.update_progress(context.current_document_position);
}

abstract_syntax_semilattice parser::single_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> const posts, std::u32string const & document, progress_handler_t const progressHandler) {
	//perf_timer timer("parse");
	job j(*this, document, g, overrideMain, progressHandler);
	throw_assert(active_count > 0);
	while (true) {
		while (work.size() > 0) {
			auto item = work.pop();
			auto const & c = *std::get<0>(item);
			auto const nextDfaState = std::get<1>(item);
			update_progress(c);	
			//INF("thread ", threadCount, " executing DFA state");
			c.owner.machine.process(c, nextDfaState);
			c.owner.end_work_queue_reference();
			--active_count;
		}
		throw_assert(active_count == 0);
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	}
	throw_assert(active_count == 0);
	complete_progress_handler(j);
	return construct_result_and_postprocess(overrideMain, posts, document, j);
}

abstract_syntax_semilattice parser::multi_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> const posts, std::u32string const & document, progress_handler_t const progressHandler) {
	//perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	job j(*this, document, g, overrideMain, progressHandler);
	throw_assert(active_count > 0);
	while (true) {
		halt_cv.wait(lock, [this]() { return active_count == 0; });
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	}
	throw_assert(active_count == 0);
	complete_progress_handler(j);
	return construct_result_and_postprocess(overrideMain, posts, document, j);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> const posts, std::u32string const & document, progress_handler_t const progressHandler) {
	if (single_thread_mode) {
		return single_thread_parse(g, overrideMain, posts, document, progressHandler);
	}
	return multi_thread_parse(g, overrideMain, posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t const progressHandler) {
	return parse(g, overrideMain, std::vector<post_processor>(), document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, std::vector<post_processor> const posts, std::u32string const & document, progress_handler_t const progressHandler) {
	return parse(g, g.get_main_state_machine(), posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, std::u32string const & document, progress_handler_t const progressHandler) {
	return parse(g, g.get_main_state_machine(), document, progressHandler);
}

void parser::schedule(context const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.id, " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
	c.owner.begin_work_queue_reference();
	++active_count;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace(&c, nextDfaState);
	work_cv.notify_one();
}

bool parser::handle_deadlocks(job const & j) const {
	throw_assert(active_count == 0);
	//perf_timer timer("handle_deadlocks");

	//build a dependency graph and detect cyclical portions that should be halted
	//if no subjobs remain, return true
	//otherwise return false (still work to be done)

	std::stack<std::pair<match_class, match_class>> s;

	//Examine subscriptions from one subjob to another to construct the graph
	std::map<match_class, std::set<match_class>> directSubscriptions;
	std::map<match_class, std::set<match_class>> allSubscriptions;
	for (auto const & i : j.producers) {
		auto const & matchClass = i.first;
		auto const & p = *i.second;
		if (p.r.is_terminal() || p.completed) {
			continue;
		}
		for (auto const & subscription : p.consumers) {
			auto const & c = subscription.c;
			match_class temp(c.owner.machine, c.owner.document_position);
			allSubscriptions[matchClass].insert(temp);
			directSubscriptions[matchClass].insert(temp);
			s.push(std::pair<match_class, match_class>(matchClass, temp));
		}
	}

	//Apply transitivity to the graph
	while (s.size() > 0) {
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
		auto & p = *j.producers.find(matchClass)->second;
		if (i.second.count(matchClass) > 0) {
			p.terminate();
			anyHalted = true;
		}
	}
	return !anyHalted;
}

struct node_props_t {
	match const m;
	std::set<permutation> & permutations;
	std::map<match, std::set<permutation>> parent_permutations_by_match;
	size_t height;
	std::set<match> all_descendents;
	std::set<match> all_ancestors;
	std::set<match> all_descendents_and_ancestors;
	std::set<match> all_unrelated_intersections;

	node_props_t(abstract_syntax_semilattice & asg, match const & m) : m(m), permutations(asg.permutations_of_matches[m]), height(0) {
	}
};

static bool can_prune(abstract_syntax_semilattice & asg, std::map<match, node_props_t> const & nodes, node_props_t const & props) {
	if (!(props.m < asg.root || asg.root < props.m)) {
		return false;
	}
	for (auto const & parentMatchAndPermutations : props.parent_permutations_by_match) {
		auto const & parentMatch = parentMatchAndPermutations.first;
		auto const i = nodes.find(parentMatch);
		throw_assert(i != nodes.end());
		auto const & parentProps = i->second;
		auto const & parentPermutations = parentMatchAndPermutations.second;
		if (parentProps.permutations.size() == parentPermutations.size()) { //if all parent permutations depend on this, then we can only prune if the parent can be pruned
			if (!can_prune(asg, nodes, parentProps)) {
				return false;
			}
		}
	}
	return true;
}

static void prune(abstract_syntax_semilattice & asg, std::map<match, node_props_t> & nodes, node_props_t & props) {
	std::queue<match> toPrune;
	std::set<match> completed;
	std::function<void(match const &)> const add = [&](match const & m) {
		if (completed.insert(m).second) {
			toPrune.push(m);
		}
	};
	add(props.m);
	while (!toPrune.empty()) {
		auto const thisMatch = toPrune.front();
		auto & thisNode = nodes.find(thisMatch)->second;
		toPrune.pop();
		for (auto const & parentMatchAndPermutations : thisNode.parent_permutations_by_match) {
			auto const & parentMatch = parentMatchAndPermutations.first;
			auto const i = nodes.find(parentMatch);
			throw_assert(i != nodes.end());
			auto & parentProps = i->second;
			auto const & parentPermutations = parentMatchAndPermutations.second;
			for (auto const & perm : parentPermutations) {
				parentProps.permutations.erase(perm);
			}
			if (parentProps.permutations.size() == 0) {
				add(parentMatch);
			}
		}
		for (auto const & descendentMatch : thisNode.all_descendents) {
			auto const i = nodes.find(descendentMatch);
			throw_assert(i != nodes.end());
			auto & descendent = i->second;
			descendent.all_ancestors.erase(thisMatch);
			if (descendent.all_ancestors.empty()) {
				add(descendentMatch);
			}
			descendent.all_descendents_and_ancestors.erase(thisMatch);
			descendent.parent_permutations_by_match.erase(thisMatch);
		}
		for (auto const & ancestorMatch : thisNode.all_ancestors) {
			auto const i = nodes.find(ancestorMatch);
			throw_assert(i != nodes.end());
			auto & ancestor = i->second;
			ancestor.all_descendents.erase(thisMatch);
			ancestor.all_descendents_and_ancestors.erase(thisMatch);
		}
		for (auto const & intersectorMatch : thisNode.all_unrelated_intersections) {
			auto const i = nodes.find(intersectorMatch);
			throw_assert(i != nodes.end());
			auto & intersector = i->second;
			intersector.all_unrelated_intersections.erase(thisMatch);
		}
	}

	for (auto const & i : completed) {
		nodes.erase(i);
		asg.permutations_of_matches.erase(i);
	}
}

static void construct_nodes(abstract_syntax_semilattice & asg, std::map<match, node_props_t> & nodes, std::vector<std::set<node_props_t *>> & flattened) {
	for (auto const & matchAndPermutations : asg.permutations_of_matches) {
		auto const & m = matchAndPermutations.first;
		auto & nodeProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(m), std::forward_as_tuple(asg, m)).first->second;

		for (auto const & perm : nodeProps.permutations) {
			for (match const & child : perm) {
				auto & childProps = nodes.emplace(std::piecewise_construct, std::forward_as_tuple(child), std::forward_as_tuple(asg, child)).first->second;
				if (childProps.permutations.empty()) {
					childProps.height = 0;
				}
				childProps.parent_permutations_by_match[nodeProps.m].insert(perm);
			}
		}
		auto const afterIndex = nodeProps.m.document_position + nodeProps.m.consumed_character_count;
		for (auto i = nodeProps.m.document_position; i < afterIndex; ++i) {
			flattened[i].insert(&nodeProps);
		}
	}
}

static void resolve_nodes(std::map<match, node_props_t> & nodes) {
	//work queue for the algorithm
	std::queue<std::tuple<node_props_t *, node_props_t *, int>> propertyResolveQueue;

	for (auto & entry : nodes) {
		auto & props = entry.second;
		//seed algorithm with "match A has all of match A's permutation's matches as descendants"
		propertyResolveQueue.push(std::make_tuple(&props, &props, 0));
	}

	//containment algorithm
	//match A contains all of match B's permutation's matches
	while (!propertyResolveQueue.empty()) {
		auto entry = propertyResolveQueue.front();
		propertyResolveQueue.pop();
		auto & left = *std::get<0>(entry);
		auto & right = *std::get<1>(entry);
		size_t const leftsHeightMinusRightsHeight = std::get<2>(entry);
		if (right.height == 0) { //if right is a leaf
			left.height = std::max(leftsHeightMinusRightsHeight, left.height);
		}
		for (auto const & perm : right.permutations) {
			for (match const & containedMatch : perm) {
				auto & childProps = nodes.find(containedMatch)->second;
				if (left.all_descendents.insert(childProps.m).second) {
					propertyResolveQueue.push(std::make_tuple(&left, &nodes.find(containedMatch)->second, leftsHeightMinusRightsHeight + 1));
				}
				childProps.all_ancestors.insert(left.m);
				childProps.all_descendents_and_ancestors.insert(left.m);
				left.all_descendents_and_ancestors.insert(childProps.m);
			}
		}
	}
}

static void compute_intersections(std::vector<std::set<node_props_t *>> const & flattened) {
	for (size_t column = 0; column < flattened.size(); ++column) {
		std::set<match> columnMatches;
		for (auto const & nodeProp : flattened[column]) {
			columnMatches.insert(nodeProp->m);
		}
		for (auto & nodeProp : flattened[column]) {
			std::set<match> unrelatedIntersection;
			std::set_difference(
				columnMatches.begin(), columnMatches.end(),
				nodeProp->all_descendents_and_ancestors.begin(), nodeProp->all_descendents_and_ancestors.end(),
				std::inserter(nodeProp->all_unrelated_intersections, nodeProp->all_unrelated_intersections.end())
			);
			nodeProp->all_unrelated_intersections.erase(nodeProp->m);
		}
	}
}

static std::vector<std::set<match>> ordered_matches_by_height(std::map<match, node_props_t> & nodes) {
	std::vector<std::set<match>> orderedMatchesByHeight;
	for (auto & entry : nodes) {
		auto & node = entry.second;
		if (orderedMatchesByHeight.size() <= node.height) {
			orderedMatchesByHeight.resize(node.height + 1);
		}
		orderedMatchesByHeight[node.height].insert(node.m);
	}
	return orderedMatchesByHeight;
}

static bool does_precede(grammar_base const & g, node_props_t & a, node_props_t & b) {
	if (&a.m.r == &b.m.r) {
		return false;
	}
	return g.does_precede(&a.m.r, &b.m.r);
}

static bool associativity_test(node_props_t & a, node_props_t & b) {
	if (&a.m.r != &b.m.r) {
		return false;
	}
	auto const assoc = dynamic_cast<state_machine_base const *>(&a.m.r)->get_assoc();
	switch (assoc) {
		case associativity::LEFT:
		case associativity::ANY:
			return b.m.document_position > a.m.document_position;
		case associativity::RIGHT:
			return b.m.document_position == a.m.document_position;
		case associativity::NONE:
			return false;
	}
	throw std::domain_error("Invalid associativity value");
}

static void select_match(abstract_syntax_semilattice & asg, grammar_base const & g, std::map<match, node_props_t> & nodes, match const & m) {
	auto const & i = nodes.find(m);
	if (i == nodes.end()) {
		return; //continue
	}
	auto a = &i->second;

	//is it possibly preempted by another match that it intersects with?
	for (auto const & intersected : a->all_unrelated_intersections) {
		auto pair = nodes.find(intersected);
		throw_assert(pair != nodes.end());
		auto & b = pair->second;
		if (does_precede(g, b, *a) || associativity_test(b, *a)) {
			prune(asg, nodes, *a);
			return;
		}
	}

	auto preservedIntersections = a->all_unrelated_intersections;
	for (auto const & intersected : preservedIntersections) {
		auto const & pair = nodes.find(intersected);
		if (pair == nodes.end()) {
			continue;
		}
		auto & b = pair->second;
		if (does_precede(g, *a, b) || associativity_test(*a, b)) {
			//if it must be selected, then precedence and associativity must remove preempted intersections
			if (can_prune(asg, nodes, b)) {
				prune(asg, nodes, b);
			}
			else {
				if (does_precede(g, *a, b)) {
					static auto stringify = [](node_props_t & np) {
						return np.m.r.id + " from " + std::to_string(np.m.document_position) + " for " + std::to_string(np.m.consumed_character_count) + " characters at height " + std::to_string(np.height);
					};
					asg.warnings.push_back(stringify(*a) + " preempted " + stringify(b) + " by precedence, but was not applied because it would cause a degenerate parse tree.");
				}
				else {
					throw std::exception(); //degenerate parse caused by associativity?
				}
			}
		}
	}
}

static void select_trees(abstract_syntax_semilattice & asg, grammar_base const & g, std::map<match, node_props_t> & nodes, std::vector<std::set<match>> const orderedMatchesByHeight) {
	for (size_t height = 0; height < orderedMatchesByHeight.size(); ++height) {
		auto const & matches = orderedMatchesByHeight[height];
		for (auto const & m : matches) {
			select_match(asg, g, nodes, m);
		}
	}
}

static void apply_precedence_and_associativity(grammar_base const & g, abstract_syntax_semilattice & asg) {
	throw_assert(asg.is_rooted());
	auto anyAssociativities = false;
	for (auto const & stateMachineBase : g.get_state_machines()) {
		anyAssociativities = stateMachineBase->get_assoc() != associativity::NONE;
		if (anyAssociativities) {
			break;
		}
	}

	//short circuit if no rules are given
	if (!g.get_precedences().empty() || anyAssociativities) {

		std::map<match, node_props_t> nodes;
		//a per-character table of matches
		std::vector<std::set<node_props_t *>> flattened;
		flattened.resize(asg.root.consumed_character_count);

		construct_nodes(asg, nodes, flattened);
		resolve_nodes(nodes);
		compute_intersections(flattened);
		auto const matchesByHeight = ordered_matches_by_height(nodes);
		select_trees(asg, g, nodes, matchesByHeight);
	}
	throw_assert(asg.is_rooted());
}


//Construct an ASS, and if a solution was found, prunes unreachable nodes
abstract_syntax_semilattice parser::construct_result(job & j, match const & m) {
	//perf_timer timer("construct_result");
	auto result = abstract_syntax_semilattice(transition(match(m), nullptr));
	for (auto const & pair : j.producers) {
		producer const & producer = *pair.second;
		for (auto const & pair2 : producer.match_to_permutations) {
			auto const & n = match(pair2.first);
			auto const & permutations = pair2.second;
			result.permutations_of_matches[n] = permutations;
		}
	}
	j.producers.clear();
	if (result.is_rooted()) {
		result.prune_detached();
		apply_precedence_and_associativity(j.g, result);
		result.prune_detached();
	}
	return result;
}

} // namespace detail
} // namespace parlex
