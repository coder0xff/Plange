#ifndef UNICODE_OP_HPP
#define UNICODE_OP_HPP

#include <string>

std::string to_utf8(const std::u32string &s);
std::u32string to_utf32(const std::string &s);

#endif
