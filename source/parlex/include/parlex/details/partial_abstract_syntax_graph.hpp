#ifndef PARTIAL_ABSTRACT_SYNTAX_GRAPH_HPP
#define PARTIAL_ABSTRACT_SYNTAX_GRAPH_HPP

#include <map>
#include <set>

#include "parlex/match.hpp"
#include "parlex/permutation.hpp"

namespace parlex {
namespace details {

struct partial_abstract_syntax_graph {
	partial_abstract_syntax_graph(std::set<match> const & matches);
	std::map<match, std::set<permutation>> permutations;
	std::set<match> matches;
};

}
}

#endif
