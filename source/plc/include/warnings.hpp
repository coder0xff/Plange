#ifndef WARNINGS_HPP
#define WARNINGS_HPP

void emit_warning(int warnNumber, std::string const & description, std::string const & file, int const line, std::string const & info);

#define MAKE_WARNING(NAME, DESCRIPTION, KEYWORDS) inline void emit_##NAME(std::string file, int line, std::string info) { emit_warning(__LINE__ + firstWarningOffset, DESCRIPTION, file, line, info); }

constexpr int firstWarningOffset = -__LINE__;
MAKE_WARNING(DuplicateFileIgnored, "Duplicate file ignored.", FILE SOURCECODE)

#undef MAKE_WARNING

#define WARNING(Name, Info) emit_##Name(__FILE__, __LINE__, Info)

#endif //WARNINGS_HPP
