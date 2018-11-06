#include "symbol.hpp"
 #include <utility>

namespace plc {

symbol::symbol(
	std::u32string name,
	std::optional<val<analytic_value>> value,
	std::optional<val<analytic_value>> type,
	ptr<analytic_value> const & scope,
	bool isVariable,
	bool isLocal,
	std::u32string xmlDocString,
	std::vector<val<analytic_value>> attributes,
	plc::visibility visibility,
	bool isExtern,
	bool isStatic,
	bool isVolatile) :
	name_(std::move(name)),
	value_(std::move(value)),
	type_(std::move(type)),
	scope_(scope),
	is_variable_(isVariable),
	is_local_(isLocal),
	xml_doc_string_(std::move(xmlDocString)),
	attributes_(std::move(attributes)),
	visibility_(visibility),
	is_extern_(isExtern),
	is_static_(isStatic),
	is_volatile_(isVolatile) {}

std::u32string const & symbol::get_name() const {
	return name_;
}

void symbol::set_xml_doc_string(std::u32string const & xmlDocString) {
	this->xml_doc_string_ = xmlDocString;
}

std::u32string const & symbol::get_xml_doc_string() const {
	return xml_doc_string_;
}

std::optional<val<analytic_value>> const & symbol::get_value() const {
	return value_;
}

void symbol::set_value(val<analytic_value> const & newValue) {
	value_ = newValue;
}

bool symbol::get_is_variable() const {
	return is_variable_;
}

}
