#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

void throw_assert(bool pass);

std::string enquote(std::string s);

std::string string_replace(std::string const & original, std::string const & find, std::string const & replace);

std::string realpath(std::string fileName);

void debugger();

#endif
