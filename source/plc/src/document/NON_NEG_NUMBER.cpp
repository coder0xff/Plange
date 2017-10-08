// This file was generated using Parlex's cpp_generator

#include "NON_NEG_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_NEG_FRACTIONAL.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"
#include "NON_NEG_NUMBER.hpp"

namespace plc {

NON_NEG_NUMBER NON_NEG_NUMBER::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return NON_NEG_NUMBER(parlex::details::document::element<NON_NEG_NUMBER_base>::build(b, n));
}

} // namespace plc
