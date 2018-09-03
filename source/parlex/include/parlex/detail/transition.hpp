#ifndef INCLUDED_PARLEX_TRANSITION_HPP
#define INCLUDED_PARLEX_TRANSITION_HPP

#include "parlex/detail/match.hpp"

namespace parlex::detail {
struct leaf;

struct transition : match {
	leaf const * l;

	transition(match const & m, leaf const * l) : match(m), l(l) {}
};

}



#endif // INCLUDED_PARLEX_TRANSITION_HPP