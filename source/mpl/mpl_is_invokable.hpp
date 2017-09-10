#ifndef INCLUDING_MPL_IS_INVOKABLE_HPP
#define INCLUDING_MPL_IS_INVOKABLE_HPP

namespace mpl {

	template <typename Fn, typename... ArgTypes>
	using is_invocable = std::is_invocable_v<Fn, ArgTypes...>

	template <typename R, typename Fn, typename... ArgTypes>
	using is_invocable_r = std::is_invocable_r_v<R, Fn, ArgTypes...>

	template <typename Fn, typename... ArgTypes>
	using is_nothrow_invocable = std::is_nothrow_invocable_v<Fn, ArgTypes...>

	template <typename R, typename Fn, typename... ArgTypes>
	using is_nothrow_invocable_r = std::is_nothrow_invocable_r_v<R, Fn, ArgTypes...>
}

#define INCLUDED_MPL_IS_INVOKABLE_HPP
#elif !define(INCLUDED_MPL_IS_INVOKABLE_HPP)
#	error circular inclusion
#endif