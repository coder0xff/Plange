#ifndef INCLUDED_MPL_UTILS_HPP
#define INCLUDED_MPL_UTILS_HPP

namespace mpl {

	namespace details {

		template<typename TTuple>
		constexpr auto sequence() {
			return std::make_index_sequence<std::tuple_size_v<std::decay_t<TTuple>>>{};
		}

		template<typename... Ts>
		constexpr int variadic_size() {
			return std::tuple_size<std::tuple<Ts...>>::value;
		}
	}

}

#endif //INCLUDED_MPL_UTILS_HPP