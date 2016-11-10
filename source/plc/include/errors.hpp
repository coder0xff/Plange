#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <string>

void emit_error(int errNumber, std::string const & description, std::string const & file, int const line, std::string const & info);

#define MAKE_ERROR(NAME, DESCRIPTION, KEYWORDS) inline void emit_##NAME(std::string file, int line, std::string info) { emit_error(__LINE__ + firstErrorOffset, DESCRIPTION, file, line, info); }

constexpr int firstErrorOffset = -__LINE__;
MAKE_ERROR(AmbiguousParse, "More than one interpretation of the input exists.", FILE SOURCECODE PARSING)
MAKE_ERROR(CouldNotParse, "The document does not conform to the syntax.", FILE SOURCECODE PARSING)
MAKE_ERROR(CouldNotOpenFile, "The file could not be opened.", FILE)
MAKE_ERROR(Unknown, "An unknown error occurred.", GENERIC)
MAKE_ERROR(NotImplemented, "The requested functionality is not yet available.", GENERIC)

#undef MAKE_ERROR

#define ERROR(Name, Info) {emit_##Name(__FILE__, __LINE__, Info); throw; } (void)0  //throw is unreachable, but prevents warnings

#endif //ERRORS_HPP
