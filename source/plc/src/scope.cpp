// ReSharper disable once CppInconsistentNaming

// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include "errors.hpp"
#include "module.hpp"
#include "scope.hpp"
#include "type.hpp"
#include "visibility.hpp"
#include "function_type.hpp"

namespace plc {

scope::scope(module & m, nptr<source_code const> source, nptr<scope> parent) :
	m(m),
	source(source),
	parent(parent) {}

//struct invocation_visitor {
//	scope & s;
//
//	scope::evaluation_result operator()(val<PARENTHETICAL_INVOCATION> const & parentheticalInvocation) const {
//		return s.evaluate(*parentheticalInvocation->target);
//	}
//};

std::vector<val<analytic_value>> evaluate_standard_arguments(scope & s, STANDARD_ARGUMENTS const & v) {
	std::vector<val<analytic_value>> results;

	struct arg_visitor {
		scope & s;

		std::vector<val<analytic_value>> operator()(val<EXPRESSION> const & v) const {
			return { s.evaluate(*v) };
		}

		std::vector<val<analytic_value>> operator()(val<ARGUMENT_PACK> const & v) const {
			ERROR(NotImplemented, "Argument packs have not been implemented.");
		}
	};

	arg_visitor visitor{s};

	std::optional<std::variant<val<EXPRESSION>, val<ARGUMENT_PACK>>> maybe_head = v.head;
	if (maybe_head.has_value()) {
		std::variant<val<EXPRESSION>, val<ARGUMENT_PACK>> firstArg = *maybe_head;
		results = std::visit(visitor, firstArg);
	} else {
		ERROR(NotImplemented, "Default arguments have not been implemented.");
	}
	for (auto const & element : v.tail) {
		std::optional<STANDARD_ARGUMENTS::tail_t::field_1_t> maybe_element = element.field_1;
		if (maybe_element.has_value()) {
			std::variant<val<EXPRESSION>, val<ARGUMENT_PACK>> element2 = maybe_element->argument;
			std::vector<val<analytic_value>> temp = std::visit(visitor, element2);
			results.insert(results.end(), temp.begin(), temp.end());
		} else {
			ERROR(NotImplemented, "Default arguments have not been implemented.");
		}
	}
	ERROR(NotImplemented, "");
}

struct value_specification {
	std::optional<std::u32string> xml_doc_string;
	std::vector<val<analytic_value>> attributes;
	std::optional<visibility> vis;
	bool is_static;
	bool is_extern;

	value_specification(const ptr<source_code> & source, const ptr<scope> & scope, IDENTIFIER_SPECIFICATION const & v) :
		xml_doc_string(v.doc.has_value()
			               ? std::optional<std::u32string>(source->get_xml_doc_string(**v.doc))
			               : std::nullopt),
		vis(v.visibility.has_value()
			           ? std::optional<visibility>(visibility_from_ast(*(*v.visibility).visibility_modifier))
			           : std::nullopt),
		is_static(v.static_.has_value()),
		is_extern(v.extern_.has_value()) {
		for (auto const & attributeContainer : v.attributes) {
			auto attribute = *attributeContainer.attribute;
			attributes.push_back(scope->evaluate(*attribute.expression));
		}
	}

	value_specification(ptr<source_code> source, ptr<scope> scope, TYPE_CONSTRAINT_SPECIFICATION const & v) :
		xml_doc_string(v.doc.has_value()
			               ? std::optional<std::u32string>(source->get_xml_doc_string(**v.doc))
			               : std::nullopt),
		vis(v.visibility.has_value()
			           ? std::optional<visibility>(visibility_from_ast(*(*v.visibility).visibility_modifier))
			           : std::nullopt),
		is_static(v.static_.has_value()),
		is_extern(v.extern_.has_value()) {
		for (auto const & attributeContainer : v.attributes) {
			auto attribute = *attributeContainer.attribute;
			attributes.push_back(scope->evaluate(*attribute.expression));
		}
	}

	value_specification combine(value_specification const & other) const {
		auto result = *this;
		if (other.xml_doc_string.has_value()) {
			result.xml_doc_string = *other.xml_doc_string;
		}
		if (other.vis.has_value()) {
			result.vis = *other.vis;
		}
		result.is_static |= other.is_static;
		result.is_extern |= other.is_extern;
		result.attributes.insert(result.attributes.end(), other.attributes.begin(), other.attributes.end());
		return result;
	}
};

struct type_constraint {
	std::optional<val<analytic_value>> value;
	bool is_volatile;
	bool is_implicit;

	type_constraint(val<analytic_value> const & value, bool const isVolatile,
	                bool const isImplicit) : value(value), is_volatile(isVolatile), is_implicit(isImplicit) {}

	type_constraint(bool const isVolatile, bool const isImplicit) : is_volatile(isVolatile), is_implicit(isImplicit) {}
};

struct type_constraint_specification {
	struct type_constraint_specification_visitor {
		ptr<scope> s;

		type_constraint operator()(val<TYPE_DEREFERENCE> const & value) const {
			auto const & unpacked = *value;
			return type_constraint(s->evaluate(*unpacked.expression), false, false);
		}

		type_constraint operator()(val<VOLATILE_TYPE_DEREFERENCE> const & value) const {
			auto const & unpacked = *value;
			return type_constraint(s->evaluate(*unpacked.expression), true, false);
		}

		type_constraint operator()(val<IMPLICIT_TYPE_DEREFERENCE> const & value) const {
			return type_constraint(false, true);
		}

		type_constraint operator()(val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE> const & value) const {
			return type_constraint(true, true);
		}

	};

	type_constraint type;
	value_specification specification;

	type_constraint_specification(const ptr<source_code const> source, const ptr<scope> & s, TYPE_CONSTRAINT_SPECIFICATION const & v) :
		type(std::visit(type_constraint_specification_visitor{s}, v.type_dereference)),
		specification(value_specification(source, s, v)) { }
};

struct type_constraint_element_visitor {
	type_constraint_specification common;
	ptr<scope> s;
	ptr<source_code const> source;

	symbol make_symbol(IDENTIFIER_SPECIFICATION const & v, val<analytic_value> const & value) {
		value_specification specification(source, s, v);
		auto combined = specification.combine(common.specification);
		//return
		//	symbol(
		//		source.get_substring(*v.identifier),
		//		std::nullopt,
		//		common.type.value,
		//		false,
		//		true,
		//		combined.xml_doc_string.value_or(U""),
		//		combined.attributes,
		//		combined.visibility.value_or(visibility::PUBLIC),
		//		combined.is_extern,
		//		combined.is_static,
		//		common.type.is_volatile
		//	)
		//;
		ERROR(NotImplemented, "");
	}

	std::vector<symbol> operator()(val<TYPE_CONSTRAINT_DECLARATION> const & v) {
		if (v->args.has_value()) {
			if (!common.type.value.has_value()) {
				ERROR(UnsupportedBootstrapFunctionality, "Declarations with implicit and deduced types are not supported");
			}
			TYPE_CONSTRAINT_DECLARATION::args_t a = *v->args;
			PARENTHETICAL_INVOCATION b = *a.parenthetical_invocation;
			std::optional<PARENTHETICAL_INVOCATION::arguments_t> c = b.arguments;
			if (c.has_value()) {
				PARENTHETICAL_INVOCATION::arguments_t d = *c;
				const std::vector<val<analytic_value>> arguments = evaluate_standard_arguments(*s, *d.standard_arguments);
				if (common.type.value.has_value()) {
					return { make_symbol(*v->identifier_specification, s->construct(*common.type.value, arguments)) };
				} else {
					ERROR(NotImplemented, "");
				}
			} else {
				ERROR(NotImplemented, "");
				//value = s.construct(common.type.value, {});
			}
		}
		ERROR(NotImplemented, "");
	}

	std::vector<symbol> operator()(val<ASSIGNMENT> const & v) {
		std::vector<symbol> results;

		auto current = &*v->assignment_node;
		ASSIGNMENT_NODE::value_t const * next;
		while ((next = std::get_if<ASSIGNMENT_NODE::value_t>(&current->value))) {
			current = &*next->next;
		}
		auto const value = s->evaluate(*std::get<val<EXPRESSION>>(current->value));

		// Create a symbol for the head identifier
		results.push_back(make_symbol(*v->identifier_specification, value));

		current = &*v->assignment_node;
		while ((next = std::get_if<ASSIGNMENT_NODE::value_t>(&current->value))) {
			results.push_back(make_symbol(*next->identifier_specification, value));
		}

		return results;
	}

	std::vector<symbol> operator()(val<DEFINITION> const & v) {
		return {make_symbol(*v->identifier_specification, s->evaluate(*v->expression))};
	}
};


void scope::load_dom(ptr<scope> s, ptr<source_code> c, STATEMENT_SCOPE const & dom)
{	
	struct statement_visitor {
		ptr<scope> s;
		ptr<source_code const> source;

		void operator()(val<ASSIGNMENT> const & value) { throw std::logic_error("not implemented"); }
		void operator()(val<BREAK> const & value) { throw std::logic_error("not implemented"); }
		void operator()(val<CONTINUE> const & value) { throw std::logic_error("not implemented"); }

		void operator()(val<DEFINITION> const & definition) {
			std::u32string const & document = source->get_document();
			std::optional<std::u32string> documentation_string;
			auto a = value_specification(source, s, *definition->identifier_specification);
			std::u32string name = source->get_substring(*definition->identifier_specification->identifier);
			val<analytic_value> value = s->evaluate(*definition->expression);
			auto const result = s->add_symbol(symbol(
				name,
				value,
				value->get_type(),
				s,
				false,
				true,
				a.xml_doc_string.value_or(U""),
				a.attributes,
				a.vis.value_or(visibility::PUBLIC),
				a.is_extern,
				a.is_static,
				false
			));
			if (!result.second) {
				auto const location = source->describe_code_span(*definition);
				ERROR(RedefinitionOfSymbol, location);
			}

		}

		void operator()(val<DO> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<EXPRESSION> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<FOR> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<FOR_COLLECTION> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<FREE> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<IMPORT> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<LOCK> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<LOOP> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<OP_ASSIGNMENT> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<READ_LOCK> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<RETURN> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<THROW> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<TRY> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<TYPE_CONSTRAINT> const & value) {
			TYPE_CONSTRAINT const & v = *value;
			// All variables in this type constraint will have these properties, possibly extended or overriden by any per-identifier properties.
			type_constraint_specification common_specification = type_constraint_specification(
				source, s, *v.specification);

			TYPE_CONSTRAINT_ELEMENT const & head = *value->head;
			type_constraint_element_visitor visitor{common_specification, s, source};
			std::variant<
				val<TYPE_CONSTRAINT_DECLARATION>,
				val<ASSIGNMENT>,
				val<DEFINITION>
			> a = head;
			std::visit(visitor, *(TYPE_CONSTRAINT_ELEMENT_base *)&head);

			for (TYPE_CONSTRAINT::tail_t const & element : v.tail) {
				std::visit(visitor, *(TYPE_CONSTRAINT_ELEMENT_base *)&element.type_constraint_element);
			}
		}

		void operator()(val<WRITE_LOCK> const & value) {
			ERROR(NotImplemented, "");
		}

		void operator()(val<USING> const & value) {
			ERROR(NotImplemented, "");
		}

	};
	for (std::variant<val<IC>, val<STATEMENT>> const & entry : dom) {
		val<STATEMENT> const * statementPtr = std::get_if<val<STATEMENT>>(&entry);
		if (statementPtr != nullptr) {
			STATEMENT const & statement = **statementPtr;
			visit(statement_visitor{ s, c }, statement.value);
		}
	}
}

std::pair<symbol_table::iterator, bool> scope::add_symbol(symbol const & s) {
	return symbols.emplace(std::piecewise_construct, forward_as_tuple(s.get_name()), std::forward_as_tuple(s));
}

//val<natural_value> scope::getFunctionType(MAPS_TO const & v) {
//	std::vector<val<natural_value>> types;
//	types.push_back(evaluate())
//	EXPRESSION const & lhs = *v.lhs;
//	EXPRESSION const & rhs = *v.rhs;
//
//}

val<analytic_value> evaluate(scope & s, MAPS_TO const & value) {
	auto is_volatile = value.field_1.has_value();
	auto is_const = value.field_2.has_value();
	val<analytic_value> lhs = s.evaluate(*value.lhs);
	val<analytic_value> rhs = s.evaluate(*value.rhs);
	type const * lhs_as_t = dynamic_cast<type const *>(&*lhs);
	if (lhs_as_t != nullptr) {
		type const * rhs_as_t = dynamic_cast<type const *>(&*rhs);
		if (rhs_as_t != nullptr) {
			// Dealing with the function type meaning
			function_type const * rhs_as_ft = dynamic_cast<function_type const *>(&*rhs);
			if (rhs_as_ft != nullptr) {
				return function_type(is_volatile, is_const, *lhs_as_t, *rhs_as_ft);
			}
			return function_type(is_volatile, is_const, *lhs_as_t, *rhs_as_t);
		}
	}
	ERROR(NotImplemented, "");
}

val<analytic_value> evaluate(scope & s, BINARY_LOGICAL_OP const & value) {
	struct visitor {
		scope & s;
		val<analytic_value> operator()(val<AND> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<IFF> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<IMPLICATION> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<MAPS_TO> const & value) {
			return evaluate(s, *value);
		}
		val<analytic_value> operator()(val<NAND> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<NOR> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<OR> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<XOR> const & value) { ERROR(NotImplemented, ""); }
	};

	return std::visit(visitor{ s }, static_cast<BINARY_LOGICAL_OP_base>(value));
}

val<analytic_value> evaluate(scope & s, BINARY_OP const & value) {
	struct visitor {
		scope & s;
		val<analytic_value> operator()(val<BINARY_ARITHMETIC_OP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<BINARY_COLLECTION_OP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<BINARY_LOGICAL_OP> const & value) {
			return evaluate(s, *value);
		}
		val<analytic_value> operator()(val<BITWISE_OP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<CONSTRUCTIVE_OP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<RELATIONAL_OP> const & value) { ERROR(NotImplemented, ""); }
	};

	return std::visit(visitor{ s }, static_cast<BINARY_OP_base>(value));
}

val<analytic_value> scope::evaluate(EXPRESSION const & expression) {
	struct visitor {
		scope & s;
		val<analytic_value> operator()(val<ARRAY> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<ASM_FUNCTION> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<BINARY_OP> const & value) {
			return plc::evaluate(s, *value);
		}
		val<analytic_value> operator()(val<BOOL> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<CAST> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<CEILING> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<COMPLEMENT> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<CONDITIONAL> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<DATE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<DATE_TIME> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<DELTA> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<DIMENSIONAL_NUMBER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<EMBEDDED_STRING> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<ENUM> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<EQUALITY> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<FLOOR> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<FUNCTION> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<GREATER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<IDENTIFIER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<IF> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<INVOCATION> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<LESSER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<LIST> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<MAGNITUDE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<MAP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<MEMBER_ACCESS> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<NEAREST_INTEGER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<NON_NEG_NUMBER> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<OBJECT> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<PARENTHETICAL> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<RANGE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<REGEX> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<SET> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<SET_COMPREHENSION> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<SUBSET> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<SUPERSET> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<SWIZZLE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<THIS> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<THIS_FUNC> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<THIS_TYPE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<TIME> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<TUPLE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<TYPE> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<UNARY_OP> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(val<VECTOR_NORM> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(parlex::detail::document::text<literal_context_t> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(parlex::detail::document::text<literal_null_t> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(parlex::detail::document::text<literal_unit_t> const & value) { ERROR(NotImplemented, ""); }
		val<analytic_value> operator()(parlex::detail::document::text<void> const & value) { ERROR(NotImplemented, ""); }
	};

	return std::visit(visitor{ *this }, static_cast<EXPRESSION_base>(expression));
}

val<analytic_value> scope::construct(val<analytic_value> const & type, std::vector<val<analytic_value>> const & arguments) {
	ERROR(NotImplemented, "");
}

std::map<std::string, val<analytic_value>> scope::get_constrained_symbols() const {
	ERROR(UnsupportedBootstrapFunctionality, "Scopes are not introspectible.");
}


natural_value* scope::collapse() {
	ERROR(UnsupportedBootstrapFunctionality, "Scopes are not introspectible.");
}

}
