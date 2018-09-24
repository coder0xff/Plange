// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_SPECIFICATION_HPP
#define INCLUDED_TYPE_CONSTRAINT_SPECIFICATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ATTRIBUTE;
struct IC;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;
struct VISIBILITY_MODIFIER;
struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
struct VOLATILE_TYPE_DEREFERENCE;
struct XML_DOC_STRING;

struct TYPE_CONSTRAINT_SPECIFICATION {
	int32_t document_position, consumed_character_count;

	struct attributes_t {
		val<ATTRIBUTE> attribute;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit attributes_t
			(val<ATTRIBUTE> && attribute, std::vector<val<IC>> && ic)
			: attribute(std::move(attribute)), ic(std::move(ic)) {}
	
		attributes_t(attributes_t const & other) = default;
		attributes_t(attributes_t && move) = default;
	
		static attributes_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct visibility_t {
		val<VISIBILITY_MODIFIER> visibility_modifier;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit visibility_t
			(val<VISIBILITY_MODIFIER> && visibility_modifier, std::vector<val<IC>> && ic)
			: visibility_modifier(std::move(visibility_modifier)), ic(std::move(ic)) {}
	
		visibility_t(visibility_t const & other) = default;
		visibility_t(visibility_t && move) = default;
	
		static visibility_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct static__t {
		parlex::detail::document::text<literal_static_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit static__t
			(parlex::detail::document::text<literal_static_t> && dont_care0, std::vector<val<IC>> && field_1)
			: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}
	
		static__t(static__t const & other) = default;
		static__t(static__t && move) = default;
	
		static static__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct extern__t {
		parlex::detail::document::text<literal_extern_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit extern__t
			(parlex::detail::document::text<literal_extern_t> && dont_care0, std::vector<val<IC>> && field_1)
			: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}
	
		extern__t(extern__t const & other) = default;
		extern__t(extern__t && move) = default;
	
		static extern__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<XML_DOC_STRING>> doc;
	
	std::vector<attributes_t> attributes;
	
	std::optional<visibility_t> visibility;
	
	std::optional<static__t> static_;
	
	std::optional<extern__t> extern_;
	
	std::variant<
		val<TYPE_DEREFERENCE>,
		val<VOLATILE_TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>,
		val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	> type_dereference;
	


	explicit TYPE_CONSTRAINT_SPECIFICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> && doc, std::vector<attributes_t> && attributes, std::optional<visibility_t> && visibility, std::optional<static__t> && static_, std::optional<extern__t> && extern_, std::variant<
	val<TYPE_DEREFERENCE>,
	val<VOLATILE_TYPE_DEREFERENCE>,
	val<IMPLICIT_TYPE_DEREFERENCE>,
	val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
> && type_dereference)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(std::move(doc)), attributes(std::move(attributes)), visibility(std::move(visibility)), static_(std::move(static_)), extern_(std::move(extern_)), type_dereference(std::move(type_dereference)) {}

	TYPE_CONSTRAINT_SPECIFICATION(TYPE_CONSTRAINT_SPECIFICATION const & other) = default;
	TYPE_CONSTRAINT_SPECIFICATION(TYPE_CONSTRAINT_SPECIFICATION && move) = default;

	static TYPE_CONSTRAINT_SPECIFICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_SPECIFICATION_HPP
