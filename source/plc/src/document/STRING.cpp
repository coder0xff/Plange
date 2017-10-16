// This file was generated using Parlex's cpp_generator

#include "STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STRING.hpp"

namespace plc {

STRING STRING::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().STRING.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STRING(parlex::details::document::element<STRING_base>::build(document, b, w));
}

} // namespace plc
