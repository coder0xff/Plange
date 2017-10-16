// This file was generated using Parlex's cpp_generator

#include "ARRAY_INDEXER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ARGUMENT.hpp"
#include "ARGUMENT_PACK.hpp"
#include "IC.hpp"
#include "SLICE.hpp"

plc::ARRAY_INDEXER plc::ARRAY_INDEXER::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().ARRAY_INDEXER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>,
		erased<SLICE>
	>>::build(document, *children[1], w);
	return ARRAY_INDEXER(std::move(v_0), std::move(v_1));
}

