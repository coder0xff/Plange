#include "../mpl_fold_vv.hpp"

#include <cassert>

#include "gtest/gtest.h"

namespace {
	struct functor {
		double multiplier;

		explicit functor(double const multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double const accumulator, TElement value) {
			return accumulator * multiplier + value;
		}
	};

	void fold_vv_1() {
		functor f(2);
		auto const data = std::make_tuple(13, 3.14, 'a');
		auto expected = (((10.2) * 2 + 13) * 2 + 3.14) * 2 + 'a';
		auto actual = mpl::fold_vv(f, 10.2, data);
		ASSERT_EQ(expected, actual);
	}
}

TEST(mplTest, fold_vv_1) {
	fold_vv_1();
}