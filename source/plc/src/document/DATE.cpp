// This file was generated using Parlex's cpp_generator

#include "DATE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DATE_YEAR_DAY.hpp"
#include "DATE_YEAR_MONTH_DAY.hpp"

#include "DATE.hpp"

namespace plc {

DATE DATE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DATE(parlex::detail::document::element<DATE_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::DATE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE));
	return result;
}
