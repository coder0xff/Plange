#ifndef INCLUDING_MPL_SUBSTITUTE_HPP
#define INCLUDING_MPL_SUBSTITUTE_HPP

#include "mpl__if.hpp"
#include "mpl_equals.hpp"
#include "mpl_map.hpp"

namespace mpl {
	
	namespace details::substitute {

		template<typename TSearch, typename TReplace>
		struct impl {
			template<typename T>
			using result = _if<equals<T, TSearch>, TReplace, T>;
		}

	}

	template<typename TSearch, typename TReplace, typename TList>
	using substitute = map<details::substitute::impl<TSearch, TReplace>::result, TList>;

}

#define INCLUDED_MPL_SUBSTITUTE_HPP
#elif !defined(INCLUDED_MPL_SUBSTITUTE_HPP)
#	error circular inclusion
#endif
