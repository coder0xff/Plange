// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct FOR_COLLECTION {
	struct declaration {
		struct field_1_t_1_t {
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			> field_1;
			
			std::vector<erased<IC>> field_2;
			
		
		
			explicit field_1_t_1_t(
				std::variant<
					erased<TYPE_DEREFERENCE>,
					erased<IMPLICIT_TYPE_DEREFERENCE>
				> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::optional<field_1_t_1_t> field_1;
		
		erased<IDENTIFIER> field_2;
		
	
	
		explicit declaration(
			std::optional<field_1_t_1_t> && field_1, erased<IDENTIFIER> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		declaration(declaration const & other) = default;
		declaration(declaration && move) = default;
	
		static declaration build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dontCare0;
	
	std::vector<erased<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dontCare2;
	
	std::vector<erased<IC>> field_02;
	
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_03;
	
	std::vector<erased<IC>> field_04;
	
	std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	> field_05;
	
	std::vector<erased<IC>> field_06;
	
	erased<EXPRESSION> collection;
	
	std::vector<erased<IC>> field_07;
	
	parlex::detail::document::text<literal_0x29_t> dontCare10;
	
	std::vector<erased<IC>> field_08;
	
	erased<EXPRESSION> invoke;
	


	explicit FOR_COLLECTION(
		parlex::detail::document::text<literal_for_t> && dontCare0, std::vector<erased<IC>> && field_01, parlex::detail::document::text<literal_0x28_t> && dontCare2, std::vector<erased<IC>> && field_02, std::variant<
			declaration,
			erased<EXPRESSION>
		> && field_03, std::vector<erased<IC>> && field_04, std::variant<
			parlex::detail::document::text<literal_in_t>,
			parlex::detail::document::text<literal_0xE20x880x88_t>
		> && field_05, std::vector<erased<IC>> && field_06, erased<EXPRESSION> && collection, std::vector<erased<IC>> && field_07, parlex::detail::document::text<literal_0x29_t> && dontCare10, std::vector<erased<IC>> && field_08, erased<EXPRESSION> && invoke) : dontCare0(std::move(dontCare0)), field_01(std::move(field_01)), dontCare2(std::move(dontCare2)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), collection(std::move(collection)), field_07(std::move(field_07)), dontCare10(std::move(dontCare10)), field_08(std::move(field_08)), invoke(std::move(invoke)) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	FOR_COLLECTION(FOR_COLLECTION && move) = default;

	static FOR_COLLECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
