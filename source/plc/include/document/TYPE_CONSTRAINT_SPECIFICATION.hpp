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
			(val<ATTRIBUTE> const & attribute, std::vector<val<IC>> const & ic)
			: attribute(attribute), ic(ic) {}
	
		attributes_t(attributes_t const & other) = default;
		static attributes_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct visibility_t {
		val<VISIBILITY_MODIFIER> visibility_modifier;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit visibility_t
			(val<VISIBILITY_MODIFIER> const & visibility_modifier, std::vector<val<IC>> const & ic)
			: visibility_modifier(visibility_modifier), ic(ic) {}
	
		visibility_t(visibility_t const & other) = default;
		static visibility_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct static__t {
		parlex::detail::document::text<literal_static_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit static__t
			(parlex::detail::document::text<literal_static_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		static__t(static__t const & other) = default;
		static static__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct extern__t {
		parlex::detail::document::text<literal_extern_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit extern__t
			(parlex::detail::document::text<literal_extern_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		extern__t(extern__t const & other) = default;
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
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> const & doc, std::vector<attributes_t> const & attributes, std::optional<visibility_t> const & visibility, std::optional<static__t> const & static_, std::optional<extern__t> const & extern_, std::variant<
	val<TYPE_DEREFERENCE>,
	val<VOLATILE_TYPE_DEREFERENCE>,
	val<IMPLICIT_TYPE_DEREFERENCE>,
	val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
> const & type_dereference)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(doc), attributes(attributes), visibility(visibility), static_(static_), extern_(extern_), type_dereference(type_dereference) {}

	TYPE_CONSTRAINT_SPECIFICATION(TYPE_CONSTRAINT_SPECIFICATION const & other) = default;
	static TYPE_CONSTRAINT_SPECIFICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_SPECIFICATION_HPP
