// This file was generated using Parlex's cpp_generator

#include "IC.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "COMMENT.hpp"
#include "EMBEDDED_COMMENT.hpp"
#include "END_OF_LINE_COMMENT.hpp"
#include "WS.hpp"

#include "IC.hpp"

namespace plc {

IC IC::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return IC(parlex::detail::document::element<IC_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::IC::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IC));
	return result;
}
