#include <cassert>
#include "gtest/gtest.h"

#include "erased.hpp"

struct base1 {
	base1() : value1(1) {}
	base1(int32_t value1) : value1(value1) {}
	int32_t value1;
};

struct base2 {
	base2() : value2(2) {}
	base2(int64_t value2) : value2(value2) {}
	int64_t value2;
};

struct derived1 : base1, base2 {
	derived1() : value3(3) {}
	derived1(int32_t value1, int64_t value2, int8_t value3) : base1(value1), base2(value2), value3(value3) {}
	int8_t value3;
};

struct derived2 : derived1 {
	derived2() : value4(4) {}
	derived2(int32_t value1, int64_t value2, int8_t value3, int16_t value4) : derived1(value1, value2, value3), value4(value4) {}
	int16_t value4;
};

TEST(ErasedTest, erased_constructor_test1) {
	erased<derived2> x = make_erased<derived2>();
	EXPECT_EQ(1, x->value1);
	EXPECT_EQ(2, x->value2);
	EXPECT_EQ(3, x->value3);
	EXPECT_EQ(4, x->value4);
}

TEST(ErasedTest, erased_constructor_test2) {
	erased<derived2> x = make_erased<derived2>(5, 6, 7, 8);
	EXPECT_EQ(5, x->value1);
	EXPECT_EQ(6, x->value2);
	EXPECT_EQ(7, x->value3);
	EXPECT_EQ(8, x->value4);
}

TEST(ErasedTest, erased_upcast_test_1) {
	erased<derived2> x = make_erased<derived2>();
	erased<derived1> y(x);
	EXPECT_EQ(1, y->value1);
	EXPECT_EQ(2, y->value2);
	EXPECT_EQ(3, y->value3);
}

TEST(ErasedTest, erased_upcast_test_2) {
	erased<derived2> x = make_erased<derived2>();
	erased<derived1> y(x);
	erased<base1> z(y);
	EXPECT_EQ(1, z->value1);
}

TEST(ErasedTest, erased_upcast_test_3) {
	erased<derived2> x = make_erased<derived2>();
	erased<derived1> y(x);
	erased<base2> z(y);
	EXPECT_EQ(2, z->value2);
}

TEST(ErasedTest, erased_upcast_test_4) {
	erased<derived2> x = make_erased<derived2>();
	erased<base1> y(x);
	EXPECT_EQ(1, y->value1);
}

TEST(ErasedTest, erased_upcast_test_5) {
	erased<derived2> x = make_erased<derived2>(5, 6, 7, 8);
	erased<base1> y(x);
	EXPECT_EQ(5, y->value1);
}

TEST(ErasedTest, erased_assignment_test_1) {
	erased<derived2> x = make_erased<derived2>(5, 6, 7, 8);
	erased<base1> y = make_erased<base1>();
	y = x;
	EXPECT_EQ(5, y->value1);
}

