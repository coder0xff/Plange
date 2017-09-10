#ifndef INCLUDING_MPL_LIST_HPP
#define INCLUDING_MPL_LIST_HPP

// The metafunctions in this library work well with std::tuple.
// However, mpl::list provides a zero-sized struct

namespace mpl {

	template<typename... Ts>
	struct list {};

}

#define INCLUDED_MPL_LIST_HPP
#elif !defined(INCLUDED_MPL_LIST_HPP)
#	error circular inclusion
#endif