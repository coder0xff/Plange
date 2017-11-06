#include "../mpl_fold_vv.hpp"

#include <cassert>
#include "gtest/gtest.h"

namespace {
	struct functor {
		double multiplier;

		functor(double multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double accumulator, TElement value) {
			return accumulator * multiplier + value;
		}
	};

	void fold_vv_1() {
		functor f(2);
		auto data = std::make_tuple(13, 3.14, 'a');
		double expected = (((10.2) * 2 + 13) * 2 + 3.14) * 2 + 'a';
		double actual = mpl::fold_vv(f, 10.2, data);
		ASSERT_EQ(expected, actual);
	}
}

TEST(mplTest, fold_vv_1) {
	fold_vv_1();
}