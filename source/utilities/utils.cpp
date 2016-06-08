#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>

#include "utils.hpp"

std::string enquote(std::string s) {
	std::ostringstream result;
	result << "\"";
	for (char c : s) {
		switch (c) {
		case '\'':
			result << "\\'";
			break;
		case '"':
			result << "\\\"";
			break;
		case '?':
			result << "\\?";
			break;
		case '\\':
			result << "\\\\";
			break;
		case '\a':
			result << "\\a";
			break;
		case '\b':
			result << "\\b";
			break;
		case '\f':
			result << "\\f";
			break;
		case '\n':
			result << "\\n";
			break;
		case '\r':
			result << "\\r";
			break;
		case '\t':
			result << "\\t";
			break;
		case '\v':
			result << "\\v";
			break;
		default:
			result << c;
		}
	}
	result << "\"";
	return result.str();
}

#if _MSC_VER == 1900

std::string to_utf8(const std::u16string &s)
{
	std::wstring_convert<std::codecvt_utf8<int16_t>, int16_t> convert;
	auto p = reinterpret_cast<const int16_t *>(s.data());
	return convert.to_bytes(p, p + s.size());
}

std::string to_utf8(const std::u32string &s)
{
	std::wstring_convert<std::codecvt_utf8<int32_t>, int32_t> convert;
	auto p = reinterpret_cast<const int32_t *>(s.data());
	return convert.to_bytes(p, p + s.size());
}

std::u16string to_utf16(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<int16_t>, int16_t> convert;
	auto asInt = convert.from_bytes(s);
	return std::u16string((char16_t const *)asInt.data(), asInt.length());
}

std::u32string to_utf32(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<int32_t>, int32_t> convert;
	auto asInt = convert.from_bytes(s);
	return std::u32string((char32_t *)asInt.data(), asInt.length());
}

#else

std::string to_utf8(const std::u16string &s)
{
	std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> conv;
	return conv.to_bytes(s);
}

std::string to_utf8(const std::u32string &s)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
	return conv.to_bytes(s);
}

std::u16string to_utf16(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<int16_t>, int16_t> convert;
	return convert.from_bytes(s);
}

std::u32string to_utf32(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
	return conv.from_bytes(s);
}

#endif

std::u16string to_utf16(const std::u32string &s)
{
	return to_utf16(to_utf8(s));
}

std::u32string to_utf32(const std::u16string &s) {
	return to_utf32(to_utf8(s));
}

std::u32string read_with_bom(std::istream & src)
{

	enum encoding {
		encoding_utf32be = 0,
		encoding_utf32le,
		encoding_utf16be,
		encoding_utf16le,
		encoding_utf8,
		encoding_ascii,
	};

	std::vector<std::string> boms = {
		std::string("\x00\x00\xFE\xFF", 4),
		std::string("\xFF\xFE\x00\x00", 4),
		std::string("\xFE\xFF", 2),
		std::string("\xFF\xFE", 2),
		std::string("\xEF\xBB\xBF", 3)
	};

	std::string buffer((std::istreambuf_iterator<char>(src)), std::istreambuf_iterator<char>());

	encoding enc = encoding_ascii;

	for (unsigned int i = 0; i < boms.size(); ++i) {
		std::string testBom = boms[i];
		if (buffer.compare(0, testBom.length(), testBom) == 0) {
			enc = (encoding)i;
			buffer = buffer.substr(testBom.length());
			break;
		}
	}

	switch (enc) {
	case encoding_utf32be:
	{
		if (buffer.length() % 4 != 0) {
			throw std::exception("size in bytes must be a multiple of 4");
		}
		int count = buffer.length() / 4;
		std::u32string temp = std::u32string(count, 0);
		for (int i = 0; i < count; ++i) {
			temp[i] = (char32_t)(buffer[i * 4 + 3] << 0 | buffer[i * 4 + 2] << 8 | buffer[i * 4 + 1] << 16 | buffer[i * 4 + 0] << 24);
		}
		return temp;
	}
	case encoding_utf32le:
	{
		if (buffer.length() % 4 != 0) {
			throw std::exception("size in bytes must be a multiple of 4");
		}
		int count = buffer.length() / 4;
		std::u32string temp = std::u32string(count, 0);
		for (int i = 0; i < count; ++i) {
			temp[i] = (char32_t)(buffer[i * 4 + 0] << 0 | buffer[i * 4 + 1] << 8 | buffer[i * 4 + 2] << 16 | buffer[i * 4 + 3] << 24);
		}
		return temp;
	}
	case encoding_utf16be:
	{
		if (buffer.length() % 2 != 0) {
			throw std::exception("size in bytes must be a multiple of 2");
		}
		int count = buffer.length() / 2;
		std::u16string temp = std::u16string(count, 0);
		for (int i = 0; i < count; ++i) {
			temp[i] = (char16_t)(buffer[i * 2 + 1] << 0 | buffer[i * 2 + 0] << 8);
		}
		return to_utf32(temp);
	}
	case encoding_utf16le:
	{
		if (buffer.length() % 2 != 0) {
			throw std::exception("size in bytes must be a multiple of 2");
		}
		int count = buffer.length() / 2;
		std::u16string temp = std::u16string(count, 0);
		for (int i = 0; i < count; ++i) {
			temp[i] = (char16_t)(buffer[i * 2 + 0] << 0 | buffer[i * 2 + 1] << 8);
		}
		return to_utf32(temp);
	}
	default:
		return to_utf32(buffer);
	}
}