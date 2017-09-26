#include "gtest/gtest.h"
#include "utf.hpp"

//see https://stackoverflow.com/a/17106065/395029
TEST(UtfTest, banana_test1) {
	std::u16string banana16(u"\U0001F34C");
	std::string banana8 = to_utf8(banana16);
	EXPECT_EQ("\xF0\x9F\x8D\x8C", banana8);
}

TEST(UtfTest, banana_test2) {
	std::u32string banana32(U"\U0001F34C");
	std::string banana8 = to_utf8(banana32);
	EXPECT_EQ("\xF0\x9F\x8D\x8C", banana8);
}

TEST(UtfTest, banana_test3) {
	std::u32string banana32(U"\U0001F34C");
	std::u16string banana16 = to_utf16(banana32);
	EXPECT_EQ(0xD83C, banana16[0]);
	EXPECT_EQ(0xDF4C, banana16[1]);
}

TEST(UtfTest, banana_test4) {
	std::u16string banana16(u"  ");
	banana16[0] = 0xD83C;
	banana16[1] = 0xDF4C;
	std::u32string banana32 = to_utf32(banana16);
	EXPECT_EQ(U"\U0001F34C", banana32);
}