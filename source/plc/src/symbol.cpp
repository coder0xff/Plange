#include "symbol.hpp"

namespace plc {

symbol::symbol(
	std::u32string const & name,
	std::optional<val<analytic_value>> const & value,
	std::optional<val<analytic_value>> const & type,
	ptr<analytic_value> const & scope,
	bool isVariable,
	bool isLocal,
	std::u32string xmlDocString,
	std::vector<val<analytic_value>> const & attributes,
	plc::visibility visibility,
	bool isExtern,
	bool isStatic,
	bool isVolatile) :
	name(name),
	value(value),
	type(type),
	scope(scope),
	is_variable(isVariable),
	is_local(isLocal),
	xml_doc_string(xmlDocString),
	attributes(attributes),
	visibility(visibility),
	is_extern(isExtern),
	is_static(isStatic),
	is_volatile(isVolatile) {}

std::u32string const & symbol::get_name() const {
	return name;
}

void symbol::set_xml_doc_string(std::u32string const & xmlDocString) {
	this->xml_doc_string = xmlDocString;
}

std::u32string const & symbol::get_xml_doc_string() const {
	return xml_doc_string;
}

std::optional<val<analytic_value>> const & symbol::get_value() const {
	return value;
}

void symbol::set_value(val<analytic_value> const & newValue) {
	value = newValue;
}

bool symbol::get_is_variable() const {
	return is_variable;
}

}
