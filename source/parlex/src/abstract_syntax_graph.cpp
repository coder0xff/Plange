#include <queue>

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/recognizer.hpp"
#include "utils.hpp"

namespace parlex {

bool abstract_syntax_graph::is_rooted() const {
	auto i = permutations.find(root);
	return i != permutations.end() && i->second.size() > 0;
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

}