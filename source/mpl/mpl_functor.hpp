#ifndef INCLUDING_MPL_FUNCTOR_HPP
#define INCLUDING_MPL_FUNCTOR_HPP

#include "mpl_apply.hpp"

namespace mpl {

	namespace details_functor {

		template<template <typename...> typename TFunctor, typename TFunctorTemplateArguments, typename... TFunctorInvokeArgs>
		struct impl {
		private:
			using concrete_type = apply<TFunctor, TFunctorTemplateArguments>;
			using return_type = decltype(
				concrete_type().operator()(
					(*(TFunctorInvokeArgs*)nullptr)...
				)
			);
		};

	}

	template<template <typename...> typename TFunctor, typename TFunctorTemplateArgs, typename... TFunctorInvokeArguments>
	using functor_return = typename details_functor::impl<TFunctor, TFunctorTemplateArgs, TFunctorInvokeArguments...>::return_type;

}

#define INCLUDED_MPL_FUNCTOR_HPP
#elif !defined(INCLUDED_MPL_FUNCTOR_HPP)
#	error circular inclusion
#endif
