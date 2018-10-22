// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_STEP_LIST_HPP
#define INCLUDED_FOR_STEP_LIST_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FOR_STEP;
struct IC;

struct FOR_STEP_LIST {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<FOR_STEP> for_step;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x2C_t> const & comma, std::vector<val<IC>> const & ic2, val<FOR_STEP> const & for_step)
			: ic1(ic1), comma(comma), ic2(ic2), for_step(for_step) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<FOR_STEP> for_step;
	
	std::vector<tail_t> tail;
	


	explicit FOR_STEP_LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, val<FOR_STEP> const & for_step, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), for_step(for_step), tail(tail) {}

	FOR_STEP_LIST(FOR_STEP_LIST const & other) = default;
	static FOR_STEP_LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_STEP_LIST_HPP
