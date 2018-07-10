#include "bits.hpp"

#include "gtest/gtest.h"

TEST(BitsTest, clzTest00) {
	EXPECT_EQ(32, clz(0));
	EXPECT_EQ(0, clz(0xFFFFFFFF));
	EXPECT_EQ(1, clz(0x7FFFFFFF));
	EXPECT_EQ(31, clz(1));
}
