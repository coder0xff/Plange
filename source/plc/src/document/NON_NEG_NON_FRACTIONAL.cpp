// This file was generated using Parlex's cpp_generator

#include "NON_NEG_NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "HEX.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "OCTAL.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

namespace plc {

NON_NEG_NON_FRACTIONAL NON_NEG_NON_FRACTIONAL::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return NON_NEG_NON_FRACTIONAL(parlex::details::document::element<NON_NEG_NON_FRACTIONAL_base>::build(b, n));
}

} // namespace plc
