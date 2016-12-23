#include "statement.hpp"
#include "plange_grammar.hpp"
#include "errors.hpp"

namespace plc {

statement * statement::from_code(parlex::match m)
{
	if (&m.r == &DEFINITION) {
		
	} else if (&m.r == &ASSIGNMENT_CHAIN) {
		
	} else if (&m.r == &STATEMENT) {
		
	}
	ERROR(Unknown, "Tried to construct a statement from a " + m.r.id);
}

}
