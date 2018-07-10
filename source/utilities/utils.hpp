#ifndef INCLUDED_UTILITIES_UTILS_HPP
#define INCLUDED_UTILITIES_UTILS_HPP

#include <string>

inline void throw_assert(bool const pass) {
#if defined(DEBUG) || _DEBUG==1
	if (!pass) {
		throw std::runtime_error("failed assert");
	}
#endif
}

void debugger();

template <typename T>
inline size_t hash_combine(T const & v) {
	std::hash<T> hasher;
	return hasher(v);
}

template <typename T, typename... Rest>
inline size_t hash_combine(T const & v, Rest... rest) {
	std::hash<T> hasher;
	size_t const seed = hash_combine(rest...);
	return hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

std::string enquote(std::string s);

std::string string_replace(std::string const & original, std::string const & find, std::string const & replace);

std::string realpath(std::string fileName);

std::string toupper(std::string const & in);

std::string tolower(std::string const & in);

#endif // INCLUDED_UTILITIES_UTILS_HPP
