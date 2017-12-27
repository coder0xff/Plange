#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "parlex/detail/match.hpp"

namespace parlex::detail {
struct leaf;

struct transition : match {
	leaf const * const l;

	transition(match const & m, leaf const * l) : match(m), l(l) {}
};

}



#endif //TRANSITION_HPP