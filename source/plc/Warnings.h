#ifndef WARNINGS_H
#define WARNINGS_H

void emit_warning(int warnNumber, std::string description, std::string info);

#define MAKE_WARNING(NAME, DESCRIPTION) inline void emit_##NAME(std::string info) { emit_warning(__LINE__ + firstWarningOffset, #DESCRIPTION, info); }

int constexpr firstWarningOffset = -__LINE__;
MAKE_WARNING(DuplicateFileIgnored, Duplicate file ignored.)

#endif //WARNINGS_H