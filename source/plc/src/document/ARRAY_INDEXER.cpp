// This file was generated using Parlex's cpp_generator

#include "ARRAY_INDEXER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARGUMENT_PACK.hpp"
#include "EXPRESSION.hpp"
#include "SLICE.hpp"

#include "ARRAY_INDEXER.hpp"

namespace plc {

ARRAY_INDEXER ARRAY_INDEXER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ARRAY_INDEXER(parlex::detail::document::element<ARRAY_INDEXER_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::ARRAY_INDEXER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_INDEXER));
	return result;
}
