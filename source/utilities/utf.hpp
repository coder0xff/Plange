#ifndef UTF_HPP
#define UTF_HPP

#include <string>

std::string to_utf8(const std::u16string &s);
std::string to_utf8(const std::u32string &s);
std::u16string to_utf16(const std::string &s);
std::u16string to_utf16(const std::u32string &s);
std::u32string to_utf32(const std::string &s);
std::u32string to_utf32(const std::u16string &s);
std::u32string read_with_bom(std::istream && src);

#endif //UTF_HPP