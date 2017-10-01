#include "../mpl_choose_v.hpp"

#include "../mpl_utils.hpp"

#include <array>
#include <cassert>
#include <string>

#include "gtest/gtest.h"

TEST(mplTest, choose_v_test1) {
	std::tuple<double, const char *, int> data = std::make_tuple(3.14, "c", 5);
	std::tuple<double, int> expected = std::make_tuple(3.14, 5);
	std::tuple<double, int> actual = mpl::choose_v< std::index_sequence<0, 2> >(data);
	assert(actual == expected);
}

TEST(mplTest, choose_v_test2) {
	std::array<double, 3> data = std::make_array(3.14, (double)'c', (double)5);
	std::array<double, 2> expected = std::make_array(3.14, (double)5);
	std::array<double, 2> actual = mpl::choose_v< std::index_sequence<0, 2> >(data);
	assert(actual == expected);
}
