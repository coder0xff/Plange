#include "document.hpp"

#include "parlex/builder.hpp" // needed by plange_grammar.cpp.inc

namespace plc {

#include "document/plange_grammar.cpp.inc"

parlex::details::grammar const & grammar() {
	static const plange_grammar value;
	return value;
}

}