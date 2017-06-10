#ifndef FILTER_FUNCTION_HPP
#define FILTER_FUNCTION_HPP

#include <functional>
#include <set>
#include <list>
#include <memory>

#include "permutation.hpp"

namespace parlex {
	//a function that takes a vector of permutations and returns
	//the set of indices into the vector that are passed by the filter
	//shared_ptr because std::functions have no equality operator
	typedef std::shared_ptr<std::function<std::set<int> (std::u32string const & /*document*/, std::list<permutation> const &)>> filter_function;
}

#endif
