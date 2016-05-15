#include <sstream>
#include <string>
#include <locale>
#include <codecvt>

#include "parlex/details/utils.hpp"

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

std::string to_utf8(const std::u32string &s)
{
	std::wstring_convert<std::codecvt_utf8<int32_t>, int32_t> convert;
	auto p = reinterpret_cast<const int32_t *>(s.data());
	return convert.to_bytes(p, p + s.size());
}

std::u32string to_utf32(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<__int32>, __int32> conv;
	auto asInt = conv.from_bytes(s);
	return std::u32string((char32_t *)asInt.data(), asInt.length());
}

#else

std::string to_utf8(const std::u32string &s)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
	return conv.to_bytes(s);
	throw;
}

std::u32string to_utf32(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
	return conv.from_bytes(s);
}

#endif
