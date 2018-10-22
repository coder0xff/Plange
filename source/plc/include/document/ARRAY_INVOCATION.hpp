// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INVOCATION_HPP
#define INCLUDED_ARRAY_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_ARGUMENTS;
struct IC;

struct ARRAY_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct arguments_t {
		val<ARRAY_ARGUMENTS> array_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit arguments_t
			(val<ARRAY_ARGUMENTS> const & array_arguments, std::vector<val<IC>> const & ic)
			: array_arguments(array_arguments), ic(ic) {}
	
		arguments_t(arguments_t const & other) = default;
		static arguments_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<arguments_t> arguments;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care3;
	


	explicit ARRAY_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B_t> const & dont_care0, std::vector<val<IC>> const & ic, std::optional<arguments_t> const & arguments, parlex::detail::document::text<literal_0x5D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), arguments(arguments), dont_care3(dont_care3) {}

	ARRAY_INVOCATION(ARRAY_INVOCATION const & other) = default;
	static ARRAY_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_INVOCATION_HPP
