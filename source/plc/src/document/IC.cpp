// This file was generated using Parlex's cpp_generator

#include "IC.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "COMMENT.hpp"
#include "EMBEDDED_COMMENT.hpp"
#include "END_OF_LINE_COMMENT.hpp"
#include "WS.hpp"
#include "IC.hpp"

namespace plc {

IC IC::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return IC(parlex::details::document::element<IC_base>::build(b, n));
}

} // namespace plc
