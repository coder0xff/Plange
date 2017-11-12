// This file was generated using Parlex's cpp_generator

#include "DATE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DATE_YEAR_DAY.hpp"
#include "DATE_YEAR_MONTH_DAY.hpp"

#include "DATE.hpp"

namespace plc {

DATE DATE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DATE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DATE(parlex::details::document::element<DATE_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::DATE::recognizer() {
	return plange_grammar::get().DATE.get_recognizer();
}
