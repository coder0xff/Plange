#include "document.hpp"

#include "parlex/builder.hpp"

parlex::details::grammar & plange_grammar()
{
	static parlex::details::grammar value(
#include "document/plange.grammar_builder.cpp.inc"
	);
	return value;
}
