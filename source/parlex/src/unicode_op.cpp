#include <string>
#include <locale>
#include <codecvt>

#include "parlex/details/unicode_op.hpp"

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
	std::wstring_convert<std::codecvt_utf8<__int32>, __int32> conv;
	return conv.to_bytes(s);
	throw;
}

std::u32string to_utf32(const std::string &s)
{
	std::wstring_convert<std::codecvt_utf8<__int32>, __int32> conv;
	return conv.from_bytes(s);
}

#endif