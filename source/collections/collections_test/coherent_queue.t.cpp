#include "../coherent_queue.hpp"

#include "gtest/gtest.h"

TEST(CoherentQueue, test0) {
	collections::coherent_queue<int> x;
	x.push(1);
}

TEST(CoherentQueue, test1) {
	collections::coherent_queue<int> x;
	x.push(1);
	EXPECT_EQ(1, x.pop());
}

TEST(CoherentQueue, test2) {
	collections::coherent_queue<int> x;
	x.push(1);
	ASSERT_EQ(1, x.size());
	EXPECT_EQ(1, x.pop());
	EXPECT_EQ(0, x.size());
}

TEST(CoherentQueue, test3) {
	collections::coherent_queue<int> x;
	for (auto i = 0; i < 1024; ++i) {
		x.push(i);
	}
	for (auto i = 0; i < 1024; ++i) {
		ASSERT_EQ(i, x.pop());
	}
}

TEST(CoherentQueue, test4) {
	collections::coherent_queue<int> x;
	for (auto i = 0; i < 65536; ++i) {
		x.push(i);
	}
	for (auto i = 0; i < 10000000; ++i) {
		x.push(i);
	}
	for (auto i = 0; i < 65536; ++i) {
		ASSERT_EQ(i, x.pop());
	}
	for (auto i = 0; i < 10000000; ++i) {
		ASSERT_EQ(i, x.pop());
	}
}

TEST(CoherentQueue, test5) {
	collections::coherent_queue<int> x;
	for (auto i = 0; i < 65536; ++i) {
		x.push(i);
	}
	for (auto i = 0; i < 65536; ++i) {
		ASSERT_EQ(i, x.pop());
		x.push(i);
	}
	for (auto i = 0; i < 65536; ++i) {
		ASSERT_EQ(i, x.pop());
	}
}