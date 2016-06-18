#ifndef ABSTRACT_SYNTAX_GRAPH_HPP
#define ABSTRACT_SYNTAX_GRAPH_HPP

#include <map>
#include <set>
#include <string>

#include "parlex/match.hpp"
#include "parlex/permutation.hpp"

namespace parlex {

struct abstract_syntax_graph {
	inline abstract_syntax_graph(match root) : root(root) {}
	std::map<match, std::set<permutation>> permutations;
	std::vector<std::set<match>> matchesByHeight;
	match root;
	bool is_rooted() const;
	std::string to_dot() const;
};

}

#endif
