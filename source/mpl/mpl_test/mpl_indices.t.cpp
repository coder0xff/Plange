#include "../mpl_indices.hpp"

#include "gtest/gtest.h"

#include "../mpl_equals.hpp"


static_assert(mpl::equals<mpl::drop_indices<0, mpl::indices<3, 1, 4, 5, 2>>, mpl::indices<3, 1, 4, 5, 2>>, "");

static_assert(mpl::equals<mpl::drop_indices<2, mpl::indices<3, 1, 4, 5, 2>>, mpl::indices<4, 5, 2>>, "");

static_assert(mpl::equals<mpl::indices_of<std::tuple<>>, mpl::indices<>>, "");

static_assert(mpl::equals<mpl::indices_of<std::tuple<int, float>>, mpl::indices<0, 1>>, "");

namespace indices_test_apply1 {
	size_t f(size_t x, size_t y, size_t z) { return x + y + z; };
	using data = std::index_sequence<1, 5, 1337>;

	void invoke() {
		auto result = mpl::apply_indices<data>(f);
	}
}

TEST(mplTest, indices_test_apply1) {
	indices_test_apply1::invoke();
}