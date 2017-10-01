#include "parlex/details/parser.hpp"

#include <stack>
#include <unordered_set>

#include "parlex/post_processor.hpp"

#include "parlex/details/context.hpp"
#include "parlex/details/grammar_base.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/permutation.hpp"
#include "parlex/details/producer.hpp"
#include "parlex/details/subjob.hpp"

#include "utils.hpp"

namespace parlex {
namespace details {

void parser::start_workers(int threadCount) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			//DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					//DBG("THREAD ", threadCount, " POPPING ITEM");
					auto item = get_work_item();
					lock.unlock();
					context const & c = *std::get<0>(item);
					int const nextDfaState = std::get<1>(item);
					update_progress(c);
					//INF("thread ", threadCount, " executing DFA state");	
					c.owner.machine.process(c, nextDfaState);
					c.owner.end_dependency(); //reference code A
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

parser::parser(unsigned threadCount) : single_thread_mode(threadCount == 1), activeCount(0), terminating(false) {
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

abstract_syntax_semilattice parser::construct_result_and_postprocess(recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, job const & j) {
	abstract_syntax_semilattice result = construct_result(j, match(match_class(overrideMain, 0), document.size()));
	if (!posts.empty()) {
		//std::string preDot = result.to_dot();
		for (auto const & post : posts) {
			post(result);
		}
		if (result.is_rooted()) {
			result.prune_detached();
		}
		//std::string postDot = result.to_dot();
	}
	return result;
}

void parser::complete_progress_handler(job & j) {
	j.update_progress(j.document.length());
}

void parser::update_progress(context const & context) {
	context.owner.owner.update_progress(context.currentDocumentPosition);
}

std::tuple<context const*, int> parser::get_work_item() {
	std::tuple<context const*, int> item = work.front();
	work.pop();
	return item;
}

abstract_syntax_semilattice parser::single_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler) {
	//perf_timer timer("parse");
	job j(*this, document, g, overrideMain, progressHandler);
	throw_assert(activeCount > 0);
	while (true) {
		while (work.size() > 0) {
			auto item = get_work_item();
			auto const & c = *std::get<0>(item);
			int const nextDfaState = std::get<1>(item);
			update_progress(c);	
			//INF("thread ", threadCount, " executing DFA state");
			c.owner.machine.process(c, nextDfaState);
			c.owner.end_dependency(); //reference code A
			--activeCount;
		}
		throw_assert(activeCount == 0);
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	}
	throw_assert(activeCount == 0);
	complete_progress_handler(j);
	return construct_result_and_postprocess(overrideMain, posts, document, j);
}

abstract_syntax_semilattice parser::multi_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler) {
	//perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	job j(*this, document, g, overrideMain, progressHandler);
	throw_assert(activeCount > 0);
	while (true) {
		halt_cv.wait(lock, [this]() { return activeCount == 0; });
		//DBG("parser is idle; checking for deadlocks");
		if (handle_deadlocks(j)) {
			break;
		}
	}
	throw_assert(activeCount == 0);
	complete_progress_handler(j);
	return construct_result_and_postprocess(overrideMain, posts, document, j);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler) {
	if (single_thread_mode) {
		return single_thread_parse(g, overrideMain, posts, document, progressHandler);
	}
	return multi_thread_parse(g, overrideMain, posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t progressHandler) {
	return parse(g, overrideMain, std::vector<post_processor>(), document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler) {
	return parse(g, g.get_main_state_machine(), posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar_base const & g, std::u32string const & document, progress_handler_t progressHandler) {
	return parse(g, g.get_main_state_machine(), document, progressHandler);
}

void parser::schedule(context const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.id, " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
	++activeCount;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace(&c, nextDfaState);
	work_cv.notify_one();
}

bool parser::handle_deadlocks(job const & j) const {
	throw_assert(activeCount == 0);
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
		producer const & p = *i.second;
		if (p.r.is_terminal() || p.completed) {
			continue;
		}
		for (auto const & subscription : p.consumers) {
			context const & c = subscription.c;
			match_class temp(c.owner.machine, c.owner.document_position);
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
			}
		}
	}

	bool anyHalted = false;
	//halt subjobs that are subscribed to themselves (in)directly
	for (auto const & i : all_subscriptions) {
		match_class const & matchClass = i.first;
		producer & p = *j.producers.find(matchClass)->second;
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

std::set<match> getChildren(abstract_syntax_semilattice const & asg, match const & m) {
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


	node_props_t(abstract_syntax_semilattice & asg, match const & m) : m(m), r(m.r), permutations(asg.permutations[m]), children(getChildren(asg, m)), height(0), selected(false) {
	}
};

bool can_prune(abstract_syntax_semilattice & asg, std::map<match, node_props_t> const & nodes, node_props_t const & props) {
	if (!(props.m < asg.root || asg.root < props.m)) {
		return false;
	}
	for (auto const & parentMatchAndPermutations : props.parentPermutationsByMatch) {
		match const & parentMatch = parentMatchAndPermutations.first;
		auto const i = nodes.find(parentMatch);
		throw_assert(i != nodes.end());
		node_props_t const & parentProps = i->second;
		std::set<permutation> const & parentPermutations = parentMatchAndPermutations.second;
		if (parentProps.permutations.size() == parentPermutations.size()) { //if all parent permutations depend on this, then we can only prune if the parent can be pruned
			if (!can_prune(asg, nodes, parentProps)) {
				return false;
			}
		}
	}
	return true;
}

void prune(abstract_syntax_semilattice & asg, std::map<match, node_props_t> & nodes, node_props_t & props) {
	std::queue<match> toPrune;
	std::set<match> completed;
	std::function<void(match const &)> add = [&](match const & m) {
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
			throw_assert(i != nodes.end());
			node_props_t & parentProps = i->second;
			std::set<permutation> const & parentPermutations = parentMatchAndPermutations.second;
			for (permutation const & perm : parentPermutations) {
				parentProps.permutations.erase(perm);
			}
			if (parentProps.permutations.size() == 0) {
				add(parentMatch);
			}
		}
		for (match const & descendentMatch : thisNode.allDescendents) {
			auto const i = nodes.find(descendentMatch);
			throw_assert(i != nodes.end());
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
			throw_assert(i != nodes.end());
			node_props_t & ancestor = i->second;
			ancestor.allDescendents.erase(thisMatch);
			ancestor.allDescendentsAndAncestors.erase(thisMatch);
			ancestor.children.erase(thisMatch);
		}
		for (match const & intersectorMatch : thisNode.allIntersections) {
			auto const i = nodes.find(intersectorMatch);
			throw_assert(i != nodes.end());
			node_props_t & intersector = i->second;
			intersector.allIntersections.erase(thisMatch);
		}
	}

	for (match const & i : completed) {
		nodes.erase(i);
		asg.permutations.erase(i);
	}
}

void construct_nodes(abstract_syntax_semilattice & asg, std::map<match, node_props_t> & nodes, std::vector<std::set<node_props_t *>> & flattened) {
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
		//seed algorithm with "fast_match A has all of fast_match A's permutation's matches as descendants"
		propertyResolveQueue.push(std::make_tuple(&props, &props, 0));
	}

	//containment algorithm
	//fast_match A contains all of fast_match B's permutation's matches
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

bool precedence_test(grammar_base const & g, node_props_t & a, node_props_t & b) {
	if (&a.m.r == &b.m.r) {
		return false;
	}
	return g.test_precedence(*dynamic_cast<state_machine_base const *>(&a.m.r), *dynamic_cast<state_machine_base const *>(&b.m.r));
}

bool associativity_test(node_props_t & a, node_props_t & b) {
	if (&a.m.r != &b.m.r) {
		return false;
	}
	associativity const assoc = dynamic_cast<state_machine_base const *>(&a.m.r)->get_assoc();
	switch (assoc) {
	case associativity::left:
	case associativity::any:
		return a.m.document_position < b.m.document_position;
	case associativity::right:
		return a.m.document_position > b.m.document_position;
	case associativity::none:
		return false;
	}
	throw std::domain_error("Invalid associativity value");
}

void select_trees(abstract_syntax_semilattice & asg, grammar_base const & g, std::map<match, node_props_t> & nodes, std::vector<std::set<match>> const orderedMatchesByHeight) {
	if (!orderedMatchesByHeight.empty()) {
		for (match const & i : orderedMatchesByHeight[0]) {
			nodes.find(i)->second.selected = true;
		}
	}
	for (size_t height = 1; height < orderedMatchesByHeight.size(); ++height) {
		std::set<match> const & matches = orderedMatchesByHeight[height];
		std::set<match> preservedIntersections; //needs to be define well before use due to gotos skipping initializtion
		for (match const & m : matches) {
			bool anyPermutationSelected = false;
			node_props_t * a;
			auto const & i = nodes.find(m);
			if (i == nodes.end()) {
				goto matchLoop; //continue
			}
			a = &i->second;
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
				goto matchLoop; //continue
			}

			//is it possibly preempted by another fast_match that it intersects with?
			for (match const & intersected : a->allIntersections) {
				auto pair = nodes.find(intersected);
				throw_assert(pair != nodes.end());
				node_props_t & b = pair->second;
				if (precedence_test(g, b, *a) || associativity_test(b, *a)) {
					prune(asg, nodes, *a);
					goto matchLoop;
				}
			}

			a->selected = true;
			preservedIntersections = a->allIntersections; //needs to be defined well before use, because of gotos skipping initialization otherwise
			for (match const & intersected : preservedIntersections) {
				auto const & pair = nodes.find(intersected);
				if (pair == nodes.end()) {
					continue;
				}
				node_props_t & b = pair->second;
				if (precedence_test(g, *a, b) || associativity_test(*a, b)) {
					//if it must be selected, then precedence and associativity must remove preempted intersections
					if (can_prune(asg, nodes, b)) {
						prune(asg, nodes, b);
					}
					else {
						if (precedence_test(g, *a, b)) {
							static auto stringify = [](node_props_t & np) {
								return np.r.id + " from " + std::to_string(np.m.document_position) + " for " + std::to_string(np.m.consumed_character_count) + " characters at height " + std::to_string(np.height);
							};
							asg.warnings.push_back(stringify(*a) + " preempted " + stringify(b) + " by precedence, but was not applied because it would cause a degenerate parse tree.");
						}
						else {
							throw std::exception(); //degenerate parse caused by associativity?
						}

					}
				}
			}
		matchLoop:
			;
		}
	}
}

abstract_syntax_semilattice& apply_precedence_and_associativity(grammar_base const & g, abstract_syntax_semilattice & asg) {
	throw_assert(asg.is_rooted());
	bool anyAssociativities = false;
	for (auto const & entry : g.get_state_machines()) {
		anyAssociativities = entry.second->get_assoc() != associativity::none;
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
		std::vector<std::set<match>> matchesByHeight = ordered_matches_by_height(nodes);
		select_trees(asg, g, nodes, matchesByHeight);
	}
	throw_assert(asg.is_rooted());
	return asg;
}


//Construct an ASS, and if a solution was found, prunes unreachable nodes
abstract_syntax_semilattice parser::construct_result(job const & j, match const & m) {
	//perf_timer timer("construct_result");
	abstract_syntax_semilattice result = abstract_syntax_semilattice(transition(match(m), nullptr));
	for (auto const & pair : j.producers) {
		producer const & producer = *pair.second;
		for (auto const & pair2 : producer.match_to_permutations) {
			struct match const & n = match(pair2.first);
			std::set<permutation> const & permutations = pair2.second;
			result.permutations[n] = permutations;
		}
	}
	if (result.is_rooted()) {
		result.prune_detached();
		return apply_precedence_and_associativity(j.g, result);
	}
	return result;
}

} // namespace details
} // namespace parlex
