#include "../mpl_drop_v.hpp"

#include <array>

#include "gtest/gtest.h"

TEST(mplTest, drop_v_test1) {
	auto data = std::make_tuple();
	ASSERT_EQ(std::make_tuple(), mpl::drop_v<0>(data));
}

TEST(mplTest, drop_v_test2) {
	auto helloPtr = "hello";
	auto data = std::make_tuple(5, helloPtr, 3.14);
	ASSERT_EQ(std::make_tuple(helloPtr, 3.14), mpl::drop_v<1>(data));
}

TEST(mplTest, drop_v_test3) {
	auto data = std::make_array(3.14, double('c'), double(5));
	ASSERT_EQ(std::make_array((double)'c', (double)5), mpl::drop_v<1>(data));
}