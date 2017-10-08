// This file was generated using Parlex's cpp_generator

#include "STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STRING.hpp"

namespace plc {

STRING STRING::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return STRING(parlex::details::document::element<STRING_base>::build(b, n));
}

} // namespace plc
