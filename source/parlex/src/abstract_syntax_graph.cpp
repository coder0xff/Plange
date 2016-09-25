#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/recognizer.hpp"
#include "utils.hpp"
#include <queue>

namespace parlex {

abstract_syntax_graph::abstract_syntax_graph(match root) : root(root) {}

bool abstract_syntax_graph::is_rooted() const {
	auto i = permutations.find(root);
	return i != permutations.end() && i->second.size() > 0;
}

void abstract_syntax_graph::cut(std::set<match> const & matches)
{
	std::map<match, std::set<match>> reversedDependencies;
	for (auto const & entry : permutations) {
		for (auto const & p : entry.second) {
			for (auto const & m : p) {
				reversedDependencies[m].insert(entry.first);
			}
		}
	}
	std::queue<match> pending;
	for (auto const & m : matches) {
		pending.push(m);
	}
	bool anyCut = false;
	while (!pending.empty()) {
		match m = pending.front();
		pending.pop();
		if (permutations.erase(m) == 1) {
			anyCut = true;
			for (auto const & n : reversedDependencies[m]) {
				std::set<permutation> newPermutations;
				for (auto const & p : permutations[n]) {
					bool cutPermutation = false;
					for (auto const & o : p) {
						if (!(o < m) && !(m < o)) {
							cutPermutation = true;
							break;
						}
					}
					if (!cutPermutation) {
						newPermutations.insert(p);
					}
				}
				if (newPermutations.empty()) {
					pending.push(n);
				} else {
					permutations[n].swap(newPermutations);
				}
			}
		}
	}
	if (anyCut) {
		
	}
}

void abstract_syntax_graph::prune_detached() {
	std::set<match> unconnecteds;
	for (auto const & entry : permutations) {
		unconnecteds.insert(entry.first);
	}
	std::queue<match> pending;
	unconnecteds.erase(root);
	pending.push(root);
	while (!pending.empty()) {
		match m = pending.front();
		pending.pop();
		for (auto const & permutation : permutations[m]) {
			for (auto const & child : permutation) {
				if (unconnecteds.erase(child) > 0) {
					pending.push(child);
				}
			}
		}
	}
	for (auto const & unconnected : unconnecteds) {
		permutations.erase(unconnected);
	}
}

std::string abstract_syntax_graph::to_dot() const {
	std::string result = "digraph {\n";
	std::set<match> completed;
	for (auto const & entry : permutations) {
		match i = entry.first;
		completed.insert(i);
		std::string from_name = i.r.get_id() + ":" + std::to_string(i.document_position) + ":" + std::to_string(i.consumed_character_count);
		for (permutation const & j : entry.second) {
			for (match const & k : j) {
				std::string to_name = k.r.get_id() + ":" + std::to_string(k.document_position) + ":" + std::to_string(k.consumed_character_count);
				result += "\t" + enquote(from_name) + " -> " + enquote(to_name) + "\n";
			}
		}
	}
	result += "}";
	return result;
}

std::string abstract_syntax_graph::to_cst_dot(std::u32string const& document) {
	std::string result = "digraph {\n";
	std::set<match> completed;
	for (auto const & entry : permutations) {
		match i = entry.first;
		completed.insert(i);
		std::string from_name = i.r.get_id() + ":" + std::to_string(i.document_position) + ":" + std::to_string(i.consumed_character_count) + "\n" + to_utf8(document.substr(i.document_position, i.consumed_character_count));
		for (permutation const & j : entry.second) {
			for (match const & k : j) {
				std::string to_name = k.r.get_id() + ":" + std::to_string(k.document_position) + ":" + std::to_string(k.consumed_character_count) + "\n" + to_utf8(document.substr(k.document_position, k.consumed_character_count));
				result += "\t" + enquote(from_name) + " -> " + enquote(to_name) + "\n";
			}
		}
	}
	result += "}";
	return result;
}


}
