#include "../mpl_drop_v.hpp"

#include "gtest/gtest.h"
#include <array>

TEST(mplTest, drop_v_test1) {
	std::tuple<> data = std::make_tuple();
	std::tuple<> expected = std::make_tuple();
	std::tuple<> actual = mpl::drop_v<0>(data);
	assert(actual == expected);
}

TEST(mplTest, drop_v_test2) {
	char const * helloPtr = "hello";
	std::tuple<int, char const *, double> data = std::make_tuple(5, helloPtr, 3.14);
	std::tuple<char const *, double> expected = std::make_tuple(helloPtr, 3.14);
	std::tuple<char const *, double> actual = mpl::drop_v<1>(data);
	assert(actual == expected);
}

TEST(mplTest, drop_v_test3) {
	std::array<double, 3> data = std::make_array(3.14, (double)'c', (double)5);
	std::array<double, 2> expected = std::make_array((double)'c', (double)5);
	std::array<double, 2> actual = mpl::drop_v<1>(data);
	assert(actual == expected);
}