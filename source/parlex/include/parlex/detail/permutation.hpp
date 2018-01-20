#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

#include <vector>

#include "parlex/detail/match.hpp"
#include "transition.hpp"

namespace parlex {
namespace detail {

typedef std::vector<transition> permutation;

}
} // namespace parlex

#endif //PERMUTATION_HPP
