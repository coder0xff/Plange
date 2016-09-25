#ifndef ABSTRACT_SYNTAX_GRAPH_HPP
#define ABSTRACT_SYNTAX_GRAPH_HPP

#include <map>
#include <set>

#include "parlex/match.hpp"
#include "parlex/permutation.hpp"

namespace parlex {

struct abstract_syntax_graph {
	abstract_syntax_graph(match root);
	std::map<match, std::set<permutation>> permutations;
	match root;
	bool is_rooted() const;
	void cut(std::set<match> const & matches);
	void prune_detached();
	std::string to_dot() const;
	std::string to_cst_dot(std::u32string const & document);
};

}

#endif
