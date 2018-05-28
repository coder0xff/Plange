#include "stdafx.hpp"

#include "scope.hpp"
#include "compiler.hpp"
#include "module.hpp"
#include "EXPRESSION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "DEFINITION.hpp"
#include "STATEMENT.hpp"

namespace plc
{

llvm::Value* buildConcreteValue(module& module)
{
	std::vector<llvm::Type*> elements;
	llvm::StructType* llvm_scope_type = llvm::StructType::get(llvm_context, llvm::ArrayRef<llvm::Type*>(elements));
	std::vector<llvm::Constant*> initial_values;
	auto initial_value = llvm::ConstantStruct::get(llvm_scope_type, llvm::ArrayRef<llvm::Constant*>(initial_values));
	return new llvm::GlobalVariable(module.get_llvm_module(), llvm_scope_type, false, llvm::GlobalValue::InternalLinkage, initial_value);
}

scope::scope(module& m, source_code const* source, scope* parent) :
	natural_value(buildConcreteValue(m)),
	m(m),
	source(source),
	parent(parent)
{
}

struct invocation_visistor {
	scope & s;

	void operator()(erased<PARENTHETICAL_INVOCATION> const & parentheticalInvocation) const {
		s.static_resolve(*parentheticalInvocation->target);
	}
};

struct expression_visitor {
	analytic_value * operator()(erased<INVOCATION> const & invocation) const {
		throw std::logic_error("not implemented");
	}
};

struct statement_visitor {
	scope & s;

	void operator()(erased<ASSIGNMENT_CHAIN> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<BREAK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<CONTINUE> const & value) { throw std::logic_error("not implemented"); }

	void operator()(erased<DEFINITION> const & definition) {
		std::optional<std::u32string> docString;
		if (definition->field_1.has_value()) {
			XML_DOC_STRING const & xmlDocString = *definition->field_1->xml_doc_string;

		}
	}

	void operator()(erased<DO> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<EXPRESSION> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<FOR> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<FOR_COLLECTION> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<FREE> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<IMPORT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<LOOP> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<OP_ASSIGNMENT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<READ_LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<RETURN> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<THROW> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<TRY> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<TYPE_CONSTRAINT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<WRITE_LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(erased<USING> const & value) { throw std::logic_error("not implemented"); }

};

scope::scope(module & m, source_code const * source, scope * parent, STATEMENT_SCOPE const & dom) :
	natural_value(buildConcreteValue(m)),
	m(m),
	source(source),
	parent(parent)
{
	for (std::variant<erased<IC>, erased<STATEMENT>> const & entry : dom) {
		erased<STATEMENT> const * statementPtr = std::get_if<erased<STATEMENT>>(&entry);
		if (statementPtr != nullptr) {
			STATEMENT const & statement = **statementPtr;
			visit(statement_visitor{ *this }, statement.value);
		}
	}
}

bool scope::add_symbol(symbol const& s)
{
	return symbols.emplace(std::piecewise_construct, forward_as_tuple(s.name), std::forward_as_tuple(s)).second;
}

analytic_value * scope::static_resolve(EXPRESSION const & expression) {
	throw new std::logic_error("not implemented");
}

}
