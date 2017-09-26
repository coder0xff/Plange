#ifndef INCLUDING_MPL_NONE_HPP
#define INCLUDING_MPL_NONE_HPP

#include "mpl__if.hpp"
#include "mpl_equals.hpp"
#include "mpl_push.hpp"

namespace mpl {
	
	// see mpl::some
	struct none {};

}

#define INCLUDED_MPL_NONE_HPP
#elif !defined(INCLUDED_MPL_NONE_HPP)
#	error circular inclusion
#endif