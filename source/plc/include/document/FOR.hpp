// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct FOR_STEP_LIST;
struct IC;
struct STATEMENT_SCOPE;

struct FOR {
	int32_t document_position, consumed_character_count;

	struct initializer_t {
		val<STATEMENT_SCOPE> statement_scope;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit initializer_t
			(val<STATEMENT_SCOPE> const & statement_scope, std::vector<val<IC>> const & ic)
			: statement_scope(statement_scope), ic(ic) {}
	
		initializer_t(initializer_t const & other) = default;
		static initializer_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct step_t {
		val<FOR_STEP_LIST> for_step_list;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit step_t
			(val<FOR_STEP_LIST> const & for_step_list, std::vector<val<IC>> const & ic)
			: for_step_list(for_step_list), ic(ic) {}
	
		step_t(step_t const & other) = default;
		static step_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	std::optional<initializer_t> initializer;
	
	val<EXPRESSION> condition;
	
	std::vector<val<IC>> ic3;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care7;
	
	std::vector<val<IC>> ic4;
	
	std::optional<step_t> step;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<val<IC>> ic5;
	
	val<EXPRESSION> field_01;
	


	explicit FOR
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x28_t> const & dont_care2, std::vector<val<IC>> const & ic2, std::optional<initializer_t> const & initializer, val<EXPRESSION> const & condition, std::vector<val<IC>> const & ic3, parlex::detail::document::text<literal_0x3B_t> const & dont_care7, std::vector<val<IC>> const & ic4, std::optional<step_t> const & step, parlex::detail::document::text<literal_0x29_t> const & dont_care10, std::vector<val<IC>> const & ic5, val<EXPRESSION> const & field_01)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), initializer(initializer), condition(condition), ic3(ic3), dont_care7(dont_care7), ic4(ic4), step(step), dont_care10(dont_care10), ic5(ic5), field_01(field_01) {}

	FOR(FOR const & other) = default;
	static FOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_HPP
