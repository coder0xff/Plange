#include "parlex/detail/parser.hpp"

#include <stack>

#include "parlex/post_processor.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/permutation.hpp"
#include "parlex/detail/producer.hpp"
#include "parlex/detail/subjob.hpp"

#include "utils.hpp"
#include "bits.hpp"
#include "perf_timer.hpp"
#include "tarjan.hpp"

namespace parlex {
namespace detail {

void parser::process(work_item const & item) const {
	update_progress(*item.dfa_context);
	auto & p = current_job->get_producer(item.producer_id);
	auto & sj = *dynamic_cast<subjob *>(&p);
	//INF("thread ", threadCount, " executing DFA state");
	sj.machine.process(*current_job, item.producer_id, sj, *item.dfa_context, item.dfa_state);
	sj.end_work_queue_reference(*current_job, item.producer_id);
}

void parser::start_workers(int threadCount) {
	for (; threadCount > 0; --threadCount) {
		workers.emplace_back([=]() {
			//DBG("thread ", threadCount, " started");
			std::unique_lock<std::mutex> lock(mutex);
			goto wait;
			while (!terminating) {
				{
					//DBG("THREAD ", threadCount, " POPPING ITEM");
					auto item = work.back();
					work.pop_back();
					lock.unlock();
					process(item);
					if (--active_count == 0) {
						halt_cv.notify_one();
					}
					lock.lock();
				}
			wait:
				work_cv.wait(lock, [this]() { return !work.empty() || terminating; });
			}
		});
	}
}

parser::parser(unsigned const threadCount) : single_thread_mode(threadCount == 1), active_count(0), terminating(false), current_job(nullptr) {
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

void parser::complete_progress_handler(job & j) {
	j.update_progress(j.document.length());
}

void parser::update_progress(context const & context) const {
	current_job->update_progress(context.current_document_position);
}

abstract_syntax_semilattice parser::single_thread_parse(grammar const & g, uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler) {
	//perf_timer perf1(__func__);
	job j(*this, document, g, overrideRootRecognizerIndex, progressHandler);
	current_job = &j;
	throw_assert(active_count > 0);
	{
		//perf_timer perf2("Recognizer work queue processing");
		while (true) {
			while (!work.empty()) {
				auto const item = work.back();
				work.pop_back();
				process(item);
				--active_count;
			}
			throw_assert(active_count == 0);
			//DBG("parser is idle; checking for deadlocks");			
			if (j.handle_deadlocks()) {
				break;
			}
		}
	}
	throw_assert(active_count == 0);
	current_job = nullptr;
	complete_progress_handler(j);
	return j.construct_result_and_postprocess(overrideRootRecognizerIndex, posts, document);
}

abstract_syntax_semilattice parser::multi_thread_parse(grammar const & g, uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler) {
	//perf_timer timer("parse");
	std::unique_lock<std::mutex> lock(mutex); //use the lock to make sure we see activeCount != 0
	job j(*this, document, g, overrideRootRecognizerIndex, progressHandler);
	current_job = &j;
	throw_assert(active_count > 0);
	{
		//perf_timer recognizeTimer("Recognizer work queue processing");
		while (true) {
			halt_cv.wait(lock, [this]() { return active_count == 0; });
			//DBG("parser is idle; checking for deadlocks");
			throw_assert(active_count == 0);
			if (j.handle_deadlocks()) {
				break;
			}
		}
	}
	throw_assert(active_count == 0);
	current_job = nullptr;
	complete_progress_handler(j);
	return j.construct_result_and_postprocess(overrideRootRecognizerIndex, posts, document);
}

abstract_syntax_semilattice parser::parse(grammar const & g, recognizer const & overrideMain, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler) {
	auto const overrideRootRecognizerIndex = g.lookup_recognizer_index(overrideMain);
	if (single_thread_mode) {
		return single_thread_parse(g, overrideRootRecognizerIndex, posts, document, progressHandler);
	}
	return multi_thread_parse(g, overrideRootRecognizerIndex, posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t const & progressHandler) {
	return parse(g, overrideMain, std::vector<post_processor>(), document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar const & g, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler) {
	return parse(g, g.get_root_state_machine(), posts, document, progressHandler);
}

abstract_syntax_semilattice parser::parse(grammar const & g, std::u32string const & document, progress_handler_t const & progressHandler) {
	return parse(g, g.get_root_state_machine(), document, progressHandler);
}

void parser::schedule(uint32_t const producerId, context const & c, int nextDfaState) {
	//DBG("scheduling m: ", c.owner().machine.name, " b:", c.owner().documentPosition, " s:", nextDfaState, " p:", c.current_document_position());
	auto & p = current_job->get_producer(producerId);
	auto & sj = *static_cast<subjob *>(&p);  // NOLINT
	sj.begin_work_queue_reference();
	++active_count;
	std::unique_lock<std::mutex> lock(mutex);
	work.emplace_back(producerId, &c, nextDfaState);
	work_cv.notify_one();
}

struct node_props_t {
	match const m;
	std::set<permutation> & permutations;
	std::map<match, std::set<permutation>> parent_permutations_by_match;
	size_t height;
	std::set<match> all_descendents;
	std::set<match> all_ancestors;
	std::set<match> all_descendents_and_ancestors;
	collections::coherent_set<match> all_unrelated_intersections;

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
			if (parentProps.permutations.empty()) {
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
	//perf_timer perf(__FUNCTION__);
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
	//perf_timer perf(__FUNCTION__);

	std::vector<node_props_t *> vertices;
	typedef std::vector<node_props_t *>::iterator vert_iterator;
	std::map<node_props_t *, vert_iterator> lookup;
	vertices.reserve(nodes.size());
	for (auto & entry : nodes) {
		vertices.push_back(&entry.second);
		lookup[&entry.second] = vertices.begin() + (vertices.size() - 1);
	}

	std::function<std::vector<vert_iterator> (vert_iterator)> const transitionFunc = [&nodes, &lookup](vert_iterator const & vert) {
		std::vector<vert_iterator> results;
		for (auto const & permutation : (*vert)->permutations) {
			for (auto const & m : permutation) {
				auto i = nodes.find(m);
				throw_assert(i != nodes.end());
				results.push_back(lookup[&(i->second)]);
			}
		}
		return results;
	};

	auto orderedNodes = tarjan(vertices.begin(), vertices.end(), transitionFunc);

	for (auto const & subgraph : orderedNodes) {
		for (auto const & vertI : subgraph) {
			auto & node = **vertI;
			for (auto const & permutation : node.permutations) {
				for (auto const & m : permutation) {
					auto i = nodes.find(m);
					throw_assert(i != nodes.end());
					auto & otherNode = i->second;
					node.height = std::max(node.height, otherNode.height + 1);
					node.all_descendents.insert(otherNode.m);
					node.all_descendents.insert(otherNode.all_descendents.begin(), otherNode.all_descendents.end());
				}
			}
		}
	}

	std::reverse(orderedNodes.begin(), orderedNodes.end());
	for (auto const & subgraph : orderedNodes) {
		for (auto const & vertI : subgraph) {
			auto & node = **vertI;
			for (auto const & entry : node.parent_permutations_by_match) {
				auto const parentMatch = entry.first;
				auto const i = nodes.find(parentMatch);
				throw_assert(i != nodes.end());
				auto const & parentNode = i->second;
				node.all_ancestors.insert(parentNode.m);
				node.all_ancestors.insert(parentNode.all_ancestors.begin(), parentNode.all_ancestors.end());
			}
		}
	}
	
	for (auto & entry : nodes) {
		entry.second.all_descendents_and_ancestors = entry.second.all_descendents;
		entry.second.all_descendents_and_ancestors.insert(entry.second.all_ancestors.begin(), entry.second.all_ancestors.end());
	}
}

//Algorithm for quickly getting the `matches` that are present in a range of document indices
struct intersection_lookup {
	explicit intersection_lookup(std::vector<std::set<node_props_t *>> const & flattened, std::set<size_t> const & affectedRecognizerIndices) {
		auto const docLen = flattened.size();
		auto const lookupDepth = sizeof(int32_t) * 8 - clz(uint32_t(docLen));
		lookup.resize(lookupDepth);
		auto & lowestRow = lookup[lookupDepth - 1];
		lowestRow.resize(docLen);
		for (size_t i = 0; i < docLen; ++i) {
			for (auto const & node : flattened[i]) {
				if (affectedRecognizerIndices.count(node->m.recognizer_index) > 0) {
					lowestRow[i].insert(node->m);
				}
			}
		}
		for (int depth = lookupDepth - 2; depth >= 0; --depth) {
			auto const antiDepth = (lookupDepth - 1) - depth;
			auto const rowWidth = docLen >> antiDepth;
			auto & row = lookup[depth];
			row.resize(rowWidth);
			auto & lowerRow = lookup[depth + 1];
			for (size_t i = 0; i + 1 < lowerRow.size(); i += 2) {
				auto const column = i / 2;
				auto & cell = row[column];
				cell.insert_many(lowerRow[i].begin(), lowerRow[i].end());
				cell.insert_many(lowerRow[i + 1].begin(), lowerRow[i + 1].end());
			}
		}
	}

	void query(int const first, int const last, collections::coherent_set<match> & results) {
		int const lookupDepth = lookup.size();
		// common higher-order bits identify the row and column fully containing the span
		auto const containmentAntiRow = sizeof(int32_t) * 8 - clz(first ^ last);
		int const containmentBreadth = 1 << containmentAntiRow;
		int const containmentColumn = first >> containmentAntiRow;
		int const containmentFirst = containmentColumn << containmentAntiRow;
		auto const containmentLast = containmentFirst + containmentBreadth - 1;
		int const containmentRow = int(lookupDepth - 1) - containmentAntiRow;
		if (containmentRow >= 0 && int(lookup[containmentRow].size()) > containmentColumn && first == containmentFirst && last == containmentLast) {
			auto resolved = lookup[containmentRow][containmentColumn];
			results.insert_many(resolved.begin(), resolved.end());
		} else {
			int const divisionAntiRow = containmentAntiRow - 1;
			auto const divisionColumn = (containmentColumn << 1) + 1;
			auto const divisionIndex = divisionColumn << divisionAntiRow;
			query(first, divisionIndex - 1, results);
			query(divisionIndex, last, results);
		}
	}

private:
	std::vector<std::vector<collections::coherent_set<match>>> lookup;	
};

static void compute_intersections(std::map<match, node_props_t> & nodes, std::vector<std::set<node_props_t *>> const & flattened, std::set<size_t> const & affectedRecognizerIndices) {
	//perf_timer perf(__FUNCTION__);
	intersection_lookup lookup(flattened, affectedRecognizerIndices);
	for (auto & matchAndProps : nodes) {		
		auto const & m = matchAndProps.first;
		if (affectedRecognizerIndices.count(m.recognizer_index) > 0) {
			auto & props = matchAndProps.second;
			auto const first = m.document_position;
			auto const last = first + m.consumed_character_count - 1;
			lookup.query(first, last, props.all_unrelated_intersections);
			props.all_unrelated_intersections.erase(m);
			auto const & remove = props.all_descendents_and_ancestors;
			props.all_unrelated_intersections.erase_many(remove.begin(), remove.end());
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

static bool does_precede(grammar const & g, node_props_t & a, node_props_t & b) {
	if (a.m.recognizer_index == b.m.recognizer_index) {
		return false;
	}
	return g.does_precede(a.m.recognizer_index, b.m.recognizer_index);
}

static bool associativity_test(grammar const & g, node_props_t & a, node_props_t & b) {
	if (a.m.recognizer_index != b.m.recognizer_index) {
		return false;
	}
	auto const assoc = dynamic_cast<state_machine const *>(&g.get_recognizer(a.m.recognizer_index))->get_assoc();
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

static void select_match(abstract_syntax_semilattice & asg, grammar const & g, std::map<match, node_props_t> & nodes, match const & m) {
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
		if (does_precede(g, b, *a) || associativity_test(g, b, *a)) {
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
		if (does_precede(g, *a, b) || associativity_test(g, *a, b)) {
			//if it must be selected, then precedence and associativity must remove preempted intersections
			if (can_prune(asg, nodes, b)) {
				prune(asg, nodes, b);
			}
			else {
				if (does_precede(g, *a, b)) {
					static auto stringify = [&g](node_props_t & np) {
						auto const & r = g.get_recognizer(np.m.recognizer_index);
						return r.name + " from " + std::to_string(np.m.document_position) + " for " + std::to_string(np.m.consumed_character_count) + " characters at height " + std::to_string(np.height);
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

static void select_trees(abstract_syntax_semilattice & asg, grammar const & g, std::map<match, node_props_t> & nodes, std::vector<std::set<match>> const orderedMatchesByHeight) {
	//perf_timer perf(__FUNCTION__);
	for (const auto & matches : orderedMatchesByHeight) {
		for (auto const & m : matches) {
			select_match(asg, g, nodes, m);
		}
	}
}

void parser::apply_precedence_and_associativity(grammar const & g, abstract_syntax_semilattice & asg) {
	//perf_timer perf(__FUNCTION__);
	throw_assert(asg.is_rooted());

	std::set<size_t> affectedRecognizerIndices;

	for (uint16_t i = 0; i < g.get_recognizer_count(); ++i) {
		auto const * recognizerPtr = &g.get_recognizer(i);
		auto const * asStateMachineBasePtr = dynamic_cast<state_machine const *>(recognizerPtr);
		if (asStateMachineBasePtr != nullptr) {
			auto const & stateMachineBase = *asStateMachineBasePtr;
			if (stateMachineBase.get_assoc() != associativity::NONE) {
				affectedRecognizerIndices.insert(i);
			}
		}
	}
	auto const precedences = g.get_precedences();
	for (size_t i = 0; i < precedences.size(); ++i) {
		auto const & precedenceSet = precedences[i];
		if (!precedenceSet.empty()) {
			affectedRecognizerIndices.insert(i);
			for (auto other : precedenceSet) {
				affectedRecognizerIndices.insert(other);
			}
		}
	}

	//short circuit if no rules are given
	if (!affectedRecognizerIndices.empty()) {

		std::map<match, node_props_t> nodes;
		//a per-character table of matches
		std::vector<std::set<node_props_t *>> flattened;
		flattened.resize(asg.root.consumed_character_count);

		construct_nodes(asg, nodes, flattened);
		resolve_nodes(nodes);
		compute_intersections(nodes, flattened, affectedRecognizerIndices);
		auto const matchesByHeight = ordered_matches_by_height(nodes);
		select_trees(asg, g, nodes, matchesByHeight);
	}
	throw_assert(asg.is_rooted());
}



} // namespace detail
} // namespace parlex
