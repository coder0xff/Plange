#ifndef UTF_HPP
#define UTF_HPP

#include <string>

std::string to_utf8(std::u32string const & s);
std::string to_utf8(std::wstring const & s);
std::wstring to_wchar(std::string const & s);
std::wstring to_wchar(std::u32string const & s);
std::u16string to_utf16(std::string const & s);
std::u32string to_utf32(std::string const & s);
std::u32string to_utf32(std::wstring const & s);
std::u32string read_with_bom(std::istream && src);

#endif //UTF_HPP