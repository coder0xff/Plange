#ifndef FILTER_FUNCTION_HPP
#define FILTER_FUNCTION_HPP

#include <functional>
#include <string>

#include "details/subjob.hpp"
#include "parlex/permutation.hpp"
#include "details/partial_abstract_syntax_graph.hpp"

namespace parlex {
	//a function that takes a vector of permutations and returns
	//the set of indices into the vector that are passed by the filter
	typedef std::function<std::set<int> (std::u32string const & /*document*/, details::partial_abstract_syntax_graph const &, std::list<permutation> const &)> filter_function;
}

#endif
