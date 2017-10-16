// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_3.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_4.hpp"
#include "FUNCTION_MODIFIER_PLATFORM.hpp"

#include "FUNCTION_MODIFIER_3.hpp"

namespace plc {

FUNCTION_MODIFIER_3 FUNCTION_MODIFIER_3::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FUNCTION_MODIFIER_3.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_3(parlex::details::document::element<FUNCTION_MODIFIER_3_base>::build(document, b, w));
}

} // namespace plc
