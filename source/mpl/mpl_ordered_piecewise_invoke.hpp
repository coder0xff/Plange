// Given a list of candidate functions, and a list of argument values,
// invoke the first function that can accept the arguments.
// The selection is evaluated at compile time.

#ifndef INCLUDING_MPL_ORDERED_PIECEWISE_INVOKE_HPP
#define INCLUDING_MPL_ORDERED_PIECEWISE_INVOKE_HPP
#include <tuple>

namespace mpl {

	template<typename... TArgs, typename... TSignatures>
	auto ordered_piecewise_invoke(std::tuple<TArgs...> const & args, TSignatures const & functions...) {
		first<bind<is_invokable, std::list<
	}
}

#define INCLUDED_MPL_ORDERED_PIECEWISE_INVOKE_HPP
#elif !defined(INCLUDED_MPL_ORDERED_PIECEWISE_INVOKE_HPP)
#	error circular inclusion
#endif