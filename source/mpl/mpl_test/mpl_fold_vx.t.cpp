#include "../mpl_fold_vx.hpp"

#include <array>
#include <cassert>

#include "gtest/gtest.h"

#include "../mpl_list.hpp"

namespace fold_vx_test1 {
	struct functor {
		double multiplier;

		functor(double multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double accumulator, double value) {
			return accumulator * multiplier + sizeof(TElement) + value;
		}
	};

	void invoke() {
		double const initial = 10.2;
		double const multiplier = 2;
		functor f(multiplier);
		auto const data = std::array<double, 0>();
		double expected = initial;
		double actual = mpl::fold_vx<mpl::list<>>(f, initial, data);
		ASSERT_EQ(expected, actual);
	}

}

TEST(mplTest, fold_vx_test1) {
	fold_vx_test1::invoke();
}

namespace fold_vx_test2 {
	struct functor {
		double multiplier;

		functor(double multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double accumulator, double value) {
			return accumulator * multiplier + sizeof(TElement) + value;
		}
	};

	void invoke() {
		double const initial = 10.2;
		double const multiplier = 2;
		functor f(multiplier);
		auto const data = std::make_array(13.0, 3.14, -3.0);
		double expected = ((initial * multiplier + sizeof(int) + data[0]) * multiplier + sizeof(float) + data[1]) * multiplier + sizeof(std::string) + data[2];
		double actual = mpl::fold_vx<mpl::list<int, float, std::string>>(f, initial, data);
		ASSERT_EQ(expected, actual);
	}
}

TEST(mplTest, fold_vx_test2) {
	fold_vx_test2::invoke();
}

namespace fold_vx_test3 {
	struct functor {
		double multiplier;

		functor(double multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double accumulator, double value) {
			return accumulator * multiplier + sizeof(TElement) + value;
		}
	};

	void invoke() {
		double const initial = 10.2;
		double const multiplier = 2;
		functor f(multiplier);
		std::vector<double> data;
		double expected = initial;
		double actual = mpl::fold_vx<mpl::list<>>(f, initial, data);
		ASSERT_EQ(expected, actual);
	}

}

TEST(mplTest, fold_vx_test3) {
	fold_vx_test3::invoke();
}

namespace fold_vx_test4 {
	struct functor {
		double multiplier;

		functor(double multiplier) : multiplier(multiplier) {}

		template<typename TElement>
		double operator()(double accumulator, double value) {
			return accumulator * multiplier + sizeof(TElement) + value;
		}
	};

	void invoke() {
		double const initial = 10.2;
		double const multiplier = 2;
		functor f(multiplier);
		std::vector<double> data { 13.0, 3.14, -3.0 };
		double expected = ((initial * multiplier + sizeof(int) + data[0]) * multiplier + sizeof(float) + data[1]) * multiplier + sizeof(std::string) + data[2];
		double actual = mpl::fold_vx<mpl::list<int, float, std::string>>(f, initial, data);
		ASSERT_EQ(expected, actual);
	}
}

TEST(mplTest, fold_vx_test4) {
	fold_vx_test4::invoke();
}
