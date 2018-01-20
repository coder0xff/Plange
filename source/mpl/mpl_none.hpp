#ifndef INCLUDING_MPL_NONE_HPP
#define INCLUDING_MPL_NONE_HPP

namespace mpl {
	
	// see mpl::some
	struct none {};

}

#define INCLUDED_MPL_NONE_HPP
#elif !defined(INCLUDED_MPL_NONE_HPP)
#	error circular inclusion
#endif