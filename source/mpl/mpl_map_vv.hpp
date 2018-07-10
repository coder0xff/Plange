#ifndef INCLUDING_MPL_MAP_VV_HPP
#define INCLUDING_MPL_MAP_VV_HPP

// map_vv<tuple<Ts...>>::map(functor, elements) returns a tuple<Us...>, where functor has member function `template <typename T> U operator()(T const & element)`, and elements is a tuple<Ts...>

#include <tuple>
#include <vector>

#include "mpl_utils.hpp"

namespace mpl {

	namespace detail_map_vv {

		template <typename TFunctor, typename TTuple, size_t... Indices>
		constexpr auto impl1(TFunctor && functor, TTuple && t, std::index_sequence<Indices...>)
		{
			return std::make_tuple((functor(std::get<Indices>(std::forward<TTuple>(t))))...);
		}

		//template <typename TFunctor, typename TTuple, size_t... Indices>
		//constexpr auto impl1(TFunctor const & functor, TTuple && t, std::index_sequence<Indices...>)
		//{
		//	return std::make_tuple((functor(std::get<Indices>(std::forward<TTuple>(t))))...);
		//}

		template <typename TTuple, typename TFunctor, typename TElement, size_t Size, size_t... Indices>
		constexpr auto impl2(TFunctor const & functor, std::array<TElement, Size> const & elements, std::index_sequence<Indices...>)
		{
			return std::make_tuple((functor.template operator()<std::tuple_element<Indices, TTuple>>(elements[Indices]))...);
		}

	}

	template<typename TFunctor, typename TTuple>
	constexpr auto map_vv(TFunctor && functor, TTuple && elements) {
		return detail_map_vv::impl1(
			std::forward<TFunctor>(functor),
			std::forward<TTuple>(elements),
			std::make_index_sequence<VARIADIC_SIZE<TTuple>>()
		);
	}

	//template<typename TFunctor, typename TTuple>
	//constexpr auto map_vv(TFunctor const & functor, TTuple && elements) {
	//	return detail_map_vv::impl1(
	//		functor,
	//		std::forward<TTuple>(elements),
	//		std::make_index_sequence<VARIADIC_SIZE<TTuple>>()
	//	);
	//}

	// invoke the functor with a template argument from Ts for each element of `elements`
	// example:
	// struct { template<typename T> T operator()(std::string const & s) { /*convert string to T*/ } myFunctor {};
	// map_values<float, int>(myFunctor, std::array<std::string, 2>{ "1.5", "1337" })
	template<typename... Ts>
	struct map_array_values {
		template<typename TFunctor, typename TElement, size_t Size>
		static constexpr auto map(TFunctor && functor, std::array<TElement, Size> && elements) {
			static_assert(mpl::VARIADIC_SIZE<Ts...>() == Size);
			typedef std::tuple<Ts...> t_tuple;
			return detail_map_vv::impl2<t_tuple>(
				std::forward<TFunctor>(functor),
				std::forward<std::array<TElement, Size>>(elements),
				std::make_index_sequence<VARIADIC_SIZE<t_tuple>>()
			);
		}		
	};

	// see map_array_values
	template<typename... Ts>
	struct map_vector_values {
		template<typename TFunctor, typename TElement>
		static constexpr auto map(TFunctor && functor, std::vector<TElement> && elements) {
			if (mpl::VARIADIC_SIZE<Ts...>() != elements.size()) {
				throw std::runtime_error("mismatch in element count");
			}
			typedef std::tuple<Ts...> t_tuple;
			return detail_map_vv::impl2<t_tuple>(
				std::forward<TFunctor>(functor),
				std::forward<std::vector<TElement>>(elements),
				std::make_index_sequence<VARIADIC_SIZE<t_tuple>>()
			);
		}
	};
}

#define INCLUDED_MPL_MAP_VV_HPP
#elif !defined(INCLUDED_MPL_MAP_VV_HPP)
#	error circular inclusion
#endif