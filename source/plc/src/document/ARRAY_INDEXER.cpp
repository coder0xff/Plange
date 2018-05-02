// This file was generated using Parlex's cpp_generator

#include "ARRAY_INDEXER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARGUMENT.hpp"
#include "ARGUMENT_PACK.hpp"
#include "IC.hpp"
#include "SLICE.hpp"

plc::ARRAY_INDEXER plc::ARRAY_INDEXER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>,
		erased<SLICE>
	>>::build(&*children[1], w);
	return ARRAY_INDEXER(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::ARRAY_INDEXER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_INDEXER));
	return result;
}
