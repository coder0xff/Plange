#ifndef INCLUDING_MPL_SOME_HPP
#define INCLUDING_MPL_SOME_HPP

namespace mpl {


	template<typename T>
	struct some {
		using type = T;
	};

}

#define INCLUDED_MPL_SOME_HPP
#elif !defined(INCLUDED_MPL_SOME_HPP)
#	error circular inclusion
#endif