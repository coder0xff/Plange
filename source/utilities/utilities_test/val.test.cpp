#include "val.hpp"

#include <cassert>

#include "gtest/gtest.h"
#include <optional>

struct base1 {
	base1() : value1(1) {}
	explicit base1(int32_t const value1) : value1(value1) {}
	int32_t value1;
};

struct base2 {
	base2() : value2(2) {}
	explicit base2(int64_t const value2) : value2(value2) {}
	int64_t value2;
};

struct derived1 : base1, base2 {
	derived1() : value3(3) {}
	derived1(int32_t const value1, int64_t const value2, int8_t const value3) : base1(value1), base2(value2), value3(value3) {}
	int8_t value3;
};

struct derived2 : derived1 {
	derived2() : value4(4) {}
	derived2(int32_t const value1, int64_t const value2, int8_t const value3, int16_t const value4) : derived1(value1, value2, value3), value4(value4) {}
	int16_t value4;
};

struct abstract1 {
	virtual int operator()() = 0;
};

struct concrete1 : abstract1 {
	int operator()() override { return 1337; }
};

static_assert(val_detail::small_storage_size<0, derived2> == sizeof(derived2));
struct undefined;
static_assert(val_detail::small_storage_size<0, undefined> == 0);

TEST(ValTest, val_constructor_test1) {
	auto x = make_val<derived2>();
	EXPECT_EQ(1, x->value1);
	EXPECT_EQ(2, x->value2);
	EXPECT_EQ(3, x->value3);
	EXPECT_EQ(4, x->value4);
}

TEST(ValTest, val_constructor_test2) {
	auto x = make_val<derived2>(5, 6, 7, 8);
	EXPECT_EQ(5, x->value1);
	EXPECT_EQ(6, x->value2);
	EXPECT_EQ(7, x->value3);
	EXPECT_EQ(8, x->value4);
}

TEST(ValTest, val_constructor_test_3) {
	auto x = make_val<derived2>(5, 6, 7, 8);
	val<derived2> y(x);
	EXPECT_EQ(5, y->value1);
}

TEST(ValTest, val_upcast_test_1) {
	auto const x = make_val<derived2>();
	val<derived1> y(x);
	EXPECT_EQ(1, y->value1);
	EXPECT_EQ(2, y->value2);
	EXPECT_EQ(3, y->value3);
}

TEST(ValTest, val_upcast_test_2) {
	auto const x = make_val<derived2>();
	val<derived1> const y(x);
	val<base1> z(y);
	EXPECT_EQ(1, z->value1);
}

TEST(ValTest, val_upcast_test_3) {
	auto const x = make_val<derived2>();
	val<derived1> const y(x);
	val<base2> z(y);
	EXPECT_EQ(2, z->value2);
}

TEST(ValTest, val_upcast_test_4) {
	auto const x = make_val<derived2>();
	val<base1> y(x);
	EXPECT_EQ(1, y->value1);
}

TEST(ValTest, val_upcast_test_5) {
	auto const x = make_val<derived2>(5, 6, 7, 8);
	val<base1> y(x);
	EXPECT_EQ(5, y->value1);
}

TEST(ValTest, val_assignment_test_1) {
	auto const x = make_val<derived2>(5, 6, 7, 8);
	val<base1> y = make_val<base1>();
	EXPECT_EQ(1, y->value1);
	*y = *x;
	EXPECT_EQ(5, y->value1);
}

TEST(ValTest, val_abstract_test1) {
	val<abstract1> x((concrete1()));
	EXPECT_EQ(1337, x->operator ()());
}

TEST(PtrTest, construct) {
	val<base1> x((base1()));
	ptr<base1> y(x);
}

TEST(PtrTest, val_abstract_optional) {
	std::optional<val<abstract1>> x;
}

TEST(PtrTest, val_abstract_optional_map) {
	std::map<std::string, std::optional<val<abstract1>>> x;
}

TEST(PtrTest, ptr_upcast_test_1) {
	auto const x = make_val<derived2>();
	ptr<derived2> y(x);
	ptr<base1> z(y);
	EXPECT_EQ(1, z->value1);
}

TEST(ValTest, val_collection_test_1) {
	std::vector<val<base1>> v;
	v.push_back(make_val<derived2>());
}

TEST(ValTest, val_move_test_1) {
	// Move is not supported. This should compile to a copy construction
	auto x = make_val<base1>();
	val<base1> y(std::move(x));
}

TEST(ValTest, val_move_test_2) {
	// Move is not supported. This should compile to copy construction
	std::vector<val<base1>> x = { make_val<base1>() };
	std::vector<val<base1>> y(std::move(x));
}
