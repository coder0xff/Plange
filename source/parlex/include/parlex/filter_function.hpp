#ifndef FILTER_FUNCTION_HPP
#define FILTER_FUNCTION_HPP

//#include <functional>

#include "details/subjob.hpp"
#include "permutation.hpp"

namespace parlex {
	//a function that takes a vector of permutations and returns
	//the set of indices into the vector that are passed by the filter
	typedef std::function<std::set<int> (std::vector<permutation> const &)> filter_function;
}

#endif
