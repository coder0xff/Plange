#ifndef INCLUDING_MPL_IS_INVOCABLE_HPP
#define INCLUDING_MPL_IS_INVOCABLE_HPP

#include <functional>
#include <type_traits>

#include "mpl_apply.hpp"
#include "mpl_push.hpp"

#if false //defined(_MSC_VER) && _MSC_VER <= 1911
// std::is_invocable et al are not available in this version of MSVC++
namespace std {
	
	namespace detail::is_nothrow_invocable_r {
		template<typename R, typename Fn, typename... ArgTypes>
		static true_type impl(
			typename enable_if<
				noexcept( (R) ((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...) ),
				decltype( (R) ((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...) )
			>::type *);

		template<typename, typename...>
		static false_type impl(...);
	}

	template <typename R, typename Fn, typename... ArgTypes>
	using is_nothrow_invocable_r = decltype(detail::is_nothrow_invocable_r::impl<R, Fn, ArgTypes...>(nullptr));

	template <typename R, typename Fn, typename... ArgTypes>
	constexpr bool is_nothrow_invocable_r_v = is_nothrow_invocable_r<R, Fn, ArgTypes...>::value;
	


	namespace detail::is_nothrow_invocable {
		template<typename Fn, typename... ArgTypes>
		static true_type impl(
			typename enable_if<
			noexcept( ((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...) ),
			decltype( ((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...) )
			>::type *);

		template<typename, typename...>
		static false_type impl(...);
	}

	template <typename Fn, typename... ArgTypes>
	using is_nothrow_invocable = decltype(detail::is_nothrow_invocable::impl<Fn, ArgTypes...>(nullptr));

	template <typename Fn, typename... ArgTypes>
	constexpr bool is_nothrow_invocable_v = is_nothrow_invocable<Fn, ArgTypes...>::value;



	namespace detail::is_invocable_r {
		template<typename R, typename Fn, typename... ArgTypes>
		static true_type impl(decltype((R)((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...)) *);

		template<typename, typename...>
		static false_type impl(...);
	}

	template <typename R, typename Fn, typename... ArgTypes>
	using is_invocable_r = decltype(detail::is_invocable_r::impl<R, Fn, ArgTypes...>(nullptr));

	template <typename R, typename Fn, typename... ArgTypes>
	constexpr bool is_invocable_r_v = is_invocable_r<R, Fn, ArgTypes...>::value;



	namespace detail::is_invocable {
		template<typename Fn, typename... ArgTypes>
		static true_type impl(decltype(((Fn*)nullptr)->operator()(*(ArgTypes*)nullptr...)) *);

		template<typename, typename...>
		static false_type impl(...);
	}

	template <typename Fn, typename... ArgTypes>
	using is_invocable = decltype(detail::is_invocable::impl<Fn, ArgTypes...>(nullptr));

	template <typename Fn, typename... ArgTypes>
	constexpr bool is_invocable_v = is_invocable<Fn, ArgTypes...>::value;


}
#endif

namespace mpl {

	template <typename TFunctor, typename TList>
	constexpr bool IS_INVOCABLE = apply<std::is_invocable, push<TFunctor, TList>>::value;

	template <typename R, typename TFunctor, typename TList>
	constexpr bool IS_INVOCABLE_R = apply<std::is_invocable_r, push<R, push<TFunctor, TList>>>::value;

	template <typename TFunctor, typename TList>
	constexpr bool IS_NOTHROW_INVOCABLE = apply<std::is_nothrow_invocable, push<TFunctor, TList>>::value;

	template <typename R, typename TFunctor, typename TList>
	constexpr bool IS_NOTHROW_INVOCABLE_R = apply<std::is_nothrow_invocable_r, push<R, push<TFunctor, TList>>>::value;

}

#define INCLUDED_MPL_IS_INVOCABLE_HPP
#elif !defined(INCLUDED_MPL_IS_INVOCABLE_HPP)
#	error circular inclusion
#endif