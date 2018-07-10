#include "../coherent_set.hpp"

#include "gtest/gtest.h"

TEST(CoherentSet, test00) {
	collections::coherent_set<int> x;
}

TEST(CoherentSet, test01) {
	collections::coherent_set<int> x;
	x.insert(0);
}

TEST(CoherentSet, test02) {
	collections::coherent_set<int> x;
	x.insert(0);
	EXPECT_EQ(1, x.size());
}

TEST(CoherentSet, test03) {
	collections::coherent_set<int> x;
	x.insert(0);
	ASSERT_EQ(1, x.size());
	EXPECT_EQ(0, *x.begin());
}

TEST(CoherentSet, test04) {
	collections::coherent_set<int> x;
	x.insert(1337);
	ASSERT_EQ(1, x.size());
	EXPECT_EQ(1337, *x.begin());
}

TEST(CoherentSet, test05) {
	collections::coherent_set<int> x;
	for (auto i = 0; i < 10000000; ++i) {
		x.insert(i);
	}
	for (auto i = 0; i < 10000000; ++i) {
		EXPECT_EQ(1, x.count(i));
	}
}