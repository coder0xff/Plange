#ifndef INCLUDED_PLC_ERRORS_HPP
#define INCLUDED_PLC_ERRORS_HPP

#include <string>

#define MAKE_ERROR(NAME, DESCRIPTION, KEYWORDS) inline void emit_##NAME(std::string file, int line, std::string info) { emit_error(__LINE__ + FIRST_ERROR_OFFSET, DESCRIPTION, file, line, info); }

namespace plc {

void emit_error(int errNumber, std::string const& description, std::string const& file, int const line, std::string const& info);

constexpr int FIRST_ERROR_OFFSET = -__LINE__;
MAKE_ERROR(NotImplemented, "INTERNAL ERROR: The required functionality is not implemented yet.", INTERNAL)
MAKE_ERROR(UnsupportedBootstrapFunctionality, "INTERNAL ERROR: the requested functionality is not available in the C++-based bootstrap compiler", INTERNAL)
MAKE_ERROR(Unknown, "INTERNAL ERROR: No error description is available.", INTERNAL)
MAKE_ERROR(AmbiguousParse, "More than one interpretation of the input exists.", FILE SOURCECODE PARSING)
MAKE_ERROR(CouldNotParse, "The document does not conform to the syntax.", FILE SOURCECODE PARSING)
MAKE_ERROR(CouldNotOpenFile, "The file could not be opened.", FILE)
MAKE_ERROR(ExpressionIsNotAFunction, "The expression does not evaluate to a function.", SOURCECODE LOGIC)
MAKE_ERROR(CannotAssignToConstant, "Assigning a value to a constant is prohibited.", SOURCECODE LOGIC)
MAKE_ERROR(RedefinitionOfSymbol, "The symbol is already defined in a containing scope.", SOURCECODE LOGIC)
MAKE_ERROR(UnexpectedStandardLibraryFileExtension, "Source code for the standard library must end in ._pg, .pgo, or .pge extensions.", FILE)
MAKE_ERROR(UnknownSymbol, "The symbol was not found in the current scope.", SOURCECODE LOGIC)
}

#undef MAKE_ERROR

#define ERROR(Name, Info) { plc::emit_##Name(__FILE__, __LINE__, Info); throw; } (void)0  // unreachable, but prevents warnings

#endif // INCLUDED_PLC_ERRORS_HPP
