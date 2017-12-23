#include "../mpl_choose_v.hpp"

#include "../mpl_utils.hpp"

#include <array>
#include <cassert>

#include "gtest/gtest.h"

TEST(mplTest, choose_v_test1) {
	auto const data = std::make_tuple(3.14, "c", 5);
	auto expected = std::make_tuple(3.14, 5);
	std::tuple<double, int> actual = mpl::choose_v< std::index_sequence<0, 2> >(data);
	ASSERT_EQ(expected, actual);
}

TEST(mplTest, choose_v_test2) {
	auto const data = std::make_array(3.14, double('c'), double(5));
	auto expected = std::make_array(3.14, double(5));
	std::array<double, 2> actual = mpl::choose_v< std::index_sequence<0, 2> >(data);
	ASSERT_EQ(expected, actual);
}
