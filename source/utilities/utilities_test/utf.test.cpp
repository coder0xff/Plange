﻿#include "utf.hpp"

#include "gtest/gtest.h"

TEST(UtfTest, RoundTrip32) {
	auto const original = U"A©☺💩"; // A=1 byte, © (A9)=2 bytes, ☺ (263A)=3 bytes, 💩 (1F4A9)=4 bytes
	auto const utf8 = to_utf8(original);
	char expectedUtf8[10] = {
		char(0x41), char(0xC2), char(0xA9), char(0xE2), char(0x98), char(0xBA), char(0xF0), char(0x9F), char(0x92), char(0xA9)
	};
	for (auto i = 0; i < 10; ++i) {
	ASSERT_EQ(expectedUtf8[i], utf8[i]);
	}
	auto const actual = to_utf32(utf8);
EXPECT_EQ(original, actual);
}

// IMPORTANT: u16string tests can be uncommented once implemented

//see https://stackoverflow.com/a/17106065/395029

//TEST(UtfTest, banana_test1) {
//	std::u16string banana16(u"\U0001F34C");
//	std::string banana8 = to_utf8(banana16);
//	EXPECT_EQ("\xF0\x9F\x8D\x8C", banana8);
//}

TEST(UtfTest, banana_test2) {
	std::u32string const banana32(U"\U0001F34C");
	auto banana8 = to_utf8(banana32);
	EXPECT_EQ("\xF0\x9F\x8D\x8C", banana8);
}

//TEST(UtfTest, banana_test3) {
//	std::u32string banana32(U"\U0001F34C");
//	std::u16string banana16 = to_utf16(banana32);
//	EXPECT_EQ(0xD83C, banana16[0]);
//	EXPECT_EQ(0xDF4C, banana16[1]);
//}

//TEST(UtfTest, banana_test4) {
//	std::u16string banana16(u"  ");
//	banana16[0] = 0xD83C;
//	banana16[1] = 0xDF4C;
//	std::u32string banana32 = to_utf32(banana16);
//	EXPECT_EQ(U"\U0001F34C", banana32);
//}
