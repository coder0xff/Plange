#ifndef WARNINGS_HPP
#define WARNINGS_HPP

#include <string>

#define MAKE_WARNING(NAME, DESCRIPTION, KEYWORDS) inline void emit_##NAME(std::string file, int line, std::string info) { emit_warning(__LINE__ + FIRST_WARNING_OFFSET, DESCRIPTION, file, line, info); }

namespace plc {

void emit_warning(int warnNumber, std::string const& description, std::string const& file, int const line, std::string const& info);

constexpr int FIRST_WARNING_OFFSET = -__LINE__;
MAKE_WARNING(DuplicateFileIgnored, "Duplicate file ignored.", FILE SOURCECODE)

}

#undef MAKE_WARNING

#define WARNING(Name, Info) plc::emit_##Name(__FILE__, __LINE__, Info)

#endif //WARNINGS_HPP
