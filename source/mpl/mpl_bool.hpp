#ifndef INCLUDING_MPL_BOOL_HPP
#define INCLUDING_MPL_BOOL_HPP

namespace mpl {

	struct true_type : std::true_type {
		static constexpr bool result = true;
	};

	struct false_type : std::false_type {
		static constexpr bool result = false;
	};

}

#define INCLUDED_MPL_BOOL_HPP
#elif !defined(INCLUDED_MPL_BOOL_HPP)
#	error circular inclusion
#endif