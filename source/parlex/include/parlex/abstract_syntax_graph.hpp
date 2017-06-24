#ifndef ABSTRACT_SYNTAX_GRAPH_HPP
#define ABSTRACT_SYNTAX_GRAPH_HPP

#include <map>
#include <set>
#include <list>

#include "parlex/match.hpp"
#include "parlex/permutation.hpp"

namespace parlex {

struct abstract_syntax_graph {
	explicit abstract_syntax_graph(match root);
	std::map<match, std::set<permutation>> permutations;
	match root;
	bool is_rooted() const;
	void cut(std::set<match> const & matches);
	void prune_detached();
	std::string to_dot() const;
	std::string to_concrete_dot(std::u32string const & document);
	std::list<std::string> warnings;
	uint64_t variation_count() const;
};

} // namespace parlex

#endif //ABSTRACT_SYNTAX_GRAPH_HPP
