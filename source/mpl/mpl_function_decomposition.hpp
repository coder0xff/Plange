#ifndef INCLUDING_MPL_FUNCTION_DECOMPOSITION_HPP
#define INCLUDING_MPL_FUNCTION_DECOMPOSITION_HPP

namespace mpl {

	namespace details_function_decomposition {

		template<typename TClass, typename TFunc>
		struct impl {};

		template<typename TClass, typename TReturn, typename TArgs...>
		struct impl<TReturn (TClass::*)(TArgs...)> {
			using return_type = TReturn;
			using argument_types = std::tuple<TArgs...>;
		}

		template<typename TReturn, typename TArgs...>
		struct impl<TReturn (*)(TArgs...)> {
			using return_type = TReturn;
			using argument_types = std::tuple<Targs...>;
		}
		
	}

	template<typename T>
	using function_return = impl<T>::return_type;

	template<typename T>
	using function_arguments = impl<T>::argument_types;
}

#define INCLUDED_MPL_FUNCTION_DECOMPOSITION_HPP
#elif !defined(INCLUDED_MPL_FUNCTION_DECOMPOSITION_HPP)
#	error circular inclusion
#endif
