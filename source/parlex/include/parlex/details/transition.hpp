#ifndef TRANSITION_HPP
#define TRANSITION_HPP
#include "match.hpp"

namespace parlex::details {

struct transition : match {
	behavior::leaf const * const l;

	transition(match const & m, behavior::leaf const * l) : match(m), l(l) {}
};

}



#endif //TRANSITION_HPP