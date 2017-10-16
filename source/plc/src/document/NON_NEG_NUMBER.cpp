// This file was generated using Parlex's cpp_generator

#include "NON_NEG_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_NEG_FRACTIONAL.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

#include "NON_NEG_NUMBER.hpp"

namespace plc {

NON_NEG_NUMBER NON_NEG_NUMBER::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().NON_NEG_NUMBER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_NUMBER(parlex::details::document::element<NON_NEG_NUMBER_base>::build(document, b, w));
}

} // namespace plc
