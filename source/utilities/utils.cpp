#include <sstream>
#include <string>
#include <locale>
#include <vector>
#include <csignal>
#include <memory>

#include "utils.hpp"

void debugger() {
#ifdef _MSC_VER
	__asm int 3
#else
	raise(SIGTRAP);
#endif
}

std::string enquote(std::string s) {
	std::ostringstream result;
	result << "\"";
	for (auto c : s) {
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

std::string string_replace(std::string const & original, std::string const & find, std::string const & replace) {
	std::string newString;
	newString.reserve(original.length()); // avoids a few memory allocations

	std::string::size_type lastPos = 0;
	std::string::size_type findPos;

	while (std::string::npos != (findPos = original.find(find, lastPos))) {
		newString.append(original, lastPos, findPos - lastPos);
		newString += replace;
		lastPos = findPos + find.length();
	}

	// Care for the rest after last occurrence
	newString += original.substr(lastPos);

	return newString;
}

std::string realpath(std::string fileName) {
	struct free_delete {
		void operator()(char * x) const {
			free(static_cast<void *>(x));
		}
	};

#ifdef _MSC_VER
	std::unique_ptr<char, free_delete> buffer(_fullpath(nullptr, fileName.c_str(), _MAX_PATH));
#else
	std::unique_ptr<char, free_delete> buffer(realpath(fileName.c_str(), nullptr));
#endif
	return buffer.get();
}

std::string toupper(std::string const & in) {
	auto result = in;
	for (auto & c : result) c = toupper(c);
	return result;
}

std::string tolower(std::string const & in) {
	auto result = in;
	for (auto & c : result) c = tolower(c);
	return result;
}

#ifndef CMAKE_INTDIR
#define CMAKE_INTDIR "None"
#endif
#ifndef CMAKE_BUILD_TYPE
#define CMAKE_BUILD_TYPE "None"
#endif

#ifndef _MSC_VER

// compares two strings in compile time constant fashion
constexpr int c_strcmp(char const * lhs, char const * rhs) {
	return '\0' == lhs[0] && '\0' == rhs[0] ? 0
		       : lhs[0] != rhs[0] ? lhs[0] - rhs[0]
		       : c_strcmp(lhs + 1, rhs + 1);
}

#endif
