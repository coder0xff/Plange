#include "../mpl_map_vv.hpp"

namespace map_vv_test_constexpr {

struct functor {
	template<typename T>
	constexpr auto operator()(T const & element) const {
		return sizeof(T) * size_t(element);
	}
};

constexpr std::tuple<size_t, size_t> EXPECTED(sizeof(char) * 3, sizeof(int32_t));
constexpr functor F;
constexpr std::tuple<size_t, size_t> ACTUAL = mpl::map_vv(F, std::tuple<char, int32_t>(3, 1));
static_assert(EXPECTED == ACTUAL);

}