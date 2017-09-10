// Given a list of candidate functions, and a list of argument values,
// invoke the first function that can accept the arguments.
// The selection is evaluated at compile time.

#ifndef INCLUDING_MPL_ORDERED_PIECEWISE_INVOKE_HPP
#define INCLUDING_MPL_ORDERED_PIECEWISE_INVOKE_HPP

namespace mpl {

	template<typename... TSignatures, typename... TArgs>
	auto ordered_piecewise_invoke(TSignatures... const & functions, std::tuple<TArgs...> && args) {
		
	}
}

#define INCLUDED_MPL_ORDERED_PIECEWISE_INVOKE_HPP
#elif !defined(INCLUDED_MPL_ORDERED_PIECEWISE_INVOKE_HPP)
#	error circular inclusion
#endif