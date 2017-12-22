// map_vv<tuple<Ts...>>::map(functor, elements) returns a tuple<Us...>, where functor has member function `template <typename T> U operator()(T const & element)`, and elements is a tuple<Ts...>

#ifndef INCLUDING_MPL_MAP_VV_HPP
#define INCLUDING_MPL_MAP_VV_HPP

#include <tuple>
#include <vector>

#include "mpl_utils.hpp"

namespace mpl {

	namespace detail_map_vv {

		template <typename TFunctor, typename TTuple, size_t... Indices>
		constexpr auto impl1(TFunctor & functor, TTuple && t, std::index_sequence<Indices...>)
		{
			return make_tuple((functor(std::get<Indices>(std::forward<TTuple>(t))))...);
		}

		template <typename TFunctor, typename TTuple, size_t... Indices>
		constexpr auto impl1(TFunctor const & functor, TTuple && t, std::index_sequence<Indices...>)
		{
			return make_tuple((functor(std::get<Indices>(std::forward<TTuple>(t))))...);
		}

		template <typename TTuple, typename TFunctor, typename TElement, size_t size, size_t... Indices>
		constexpr auto impl2(TFunctor & functor, std::array<TElement, size> const & elements, std::index_sequence<Indices...>)
		{
			return make_tuple((functor.template operator() < std::tuple_element<Indices, TTuple> > (elements[Indices]))...);
		}

		template <typename TTuple, typename TFunctor, typename TArray, size_t... Indices>
		constexpr auto impl2(TFunctor const & functor, TArray const & elements, std::index_sequence<Indices...>)
		{
			return make_tuple((functor.template operator()<std::tuple_element<Indices, TTuple>>(elements[Indices]))...);
		}

	}

	template<typename TFunctor, typename TTuple>
	constexpr auto map_vv(TFunctor && functor, TTuple && elements) {
		return details_map_vv::impl1(
			std::forward<TFunctor>(functor),
			std::forward<TTuple>(elements),
			detail::sequence<TTuple>()
		);
	}

	// invoke the functor with a template argument from Ts for each element of `elements`
	// example:
	// struct { template<typename T> T operator()(std::string const & s) { /*convert string to T*/ } myFunctor {};
	// map_values<float, int>(myFunctor, std::array<std::string, 2>{ "1.5", "1337" })
	template<typename... Ts>
	struct map_array_values {
		template<typename TFunctor, typename TElement, size_t size>
		static constexpr auto map(TFunctor && functor, std::array<TElement, size> && elements) {
			static_assert(detail::variadic_size<Ts...>() == size);
			typedef std::tuple<Ts...> TTuple;
			return details_map_vv::impl2<TTuple>(
				std::forward<TFunctor>(functor),
				std::forward<std::array<TElement, size>>(elements),
				detail::sequence<TTuple>()
			);
		}		
	};

	// see map_array_values
	template<typename... Ts>
	struct map_vector_values {
		template<typename TFunctor, typename TElement>
		static constexpr auto map(TFunctor && functor, std::vector<TElement> && elements) {
			if (detail::variadic_size<Ts...>() != elements.size()) {
				throw std::runtime_error("mismatch in element count");
			}
			typedef std::tuple<Ts...> TTuple;
			return details_map_vv::impl2<TTuple>(
				std::forward<TFunctor>(functor),
				std::forward<std::vector<TElement>>(elements),
				detail::sequence<TTuple>()
			);
		}
	};
}

#define INCLUDED_MPL_MAP_VV_HPP
#elif !defined(INCLUDED_MPL_MAP_VV_HPP)
#	error circular inclusion
#endif