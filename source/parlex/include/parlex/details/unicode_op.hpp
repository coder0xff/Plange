#ifndef UNICODE_OP_HPP
#define UNICODE_OP_HPP

#include <string>

std::string uni_trunc(std::u32string const & s);
std::u32string uni_grow(std::string const & s);

#endif
