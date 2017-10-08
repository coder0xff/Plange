#ifndef INCLUDING_MPL_FUNCTION_DECOMPOSITION_HPP
#define INCLUDING_MPL_FUNCTION_DECOMPOSITION_HPP

#include <tuple>

namespace mpl {

	namespace details::function_decomposition {

		template<typename TFunc>
		struct impl {};

		template<typename TClass, typename TReturn, typename... TArgs>
		struct impl<TReturn (TClass::*)(TArgs...)> {
			using return_type = TReturn;
			using argument_types = std::tuple<TArgs...>;
		};

		template<typename TClass, typename TReturn, typename... TArgs>
		struct impl<TReturn(TClass::*)(TArgs...) const> {
			using return_type = TReturn;
			using argument_types = std::tuple<TArgs...>;
		};

		template<typename TReturn, typename... TArgs>
		struct impl<TReturn (*)(TArgs...)> {
			using return_type = TReturn;
			using argument_types = std::tuple<TArgs...>;
		};
		
		template<typename TReturn, typename... TArgs>
		struct impl<TReturn (TArgs...)> {
			using return_type = TReturn;
			using argument_types = std::tuple<TArgs...>;
		};
	}

	template<typename T>
	using function_return = typename details::function_decomposition::impl<T>::return_type;

	template<typename T>
	using function_arguments = typename details::function_decomposition::impl<T>::argument_types;
}

#define INCLUDED_MPL_FUNCTION_DECOMPOSITION_HPP
#elif !defined(INCLUDED_MPL_FUNCTION_DECOMPOSITION_HPP)
#	error circular inclusion
#endif
