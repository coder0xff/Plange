#ifndef DERIVATION_HPP
#define DERIVATION_HPP

#include <vector>

#include "parlex/detail/match.hpp"
#include "transition.hpp"

namespace parlex {
namespace detail {

typedef std::vector<transition> derivation;

}
} // namespace parlex

#endif //DERIVATION_HPP
