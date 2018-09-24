// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include "scope.hpp"

#include "compiler.hpp"
#include "DEFINITION.hpp"
#include "EXPRESSION.hpp"
#include "module.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "STATEMENT.hpp"

namespace plc
{

llvm::Value* buildConcreteValue(module& module)
{
	std::vector<llvm::Type*> elements;
	llvm::StructType* llvm_scope_type = llvm::StructType::get(module.owner.llvm_context, llvm::ArrayRef<llvm::Type*>(elements));
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

	void operator()(val<PARENTHETICAL_INVOCATION> const & parentheticalInvocation) const {
		s.static_resolve(*parentheticalInvocation->target);
	}
};

struct expression_visitor {
	analytic_value * operator()(val<INVOCATION> const & invocation) const {
		throw std::logic_error("not implemented");
	}
};

struct statement_visitor {
	scope & s;

	void operator()(val<ASSIGNMENT_CHAIN> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<BREAK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<CONTINUE> const & value) { throw std::logic_error("not implemented"); }

	void operator()(val<DEFINITION> const & definition) {
		std::optional<std::u32string> docString;
		if (definition->field_1.has_value()) {
			XML_DOC_STRING const & xmlDocString = *definition->field_1->xml_doc_string;

		}
	}

	void operator()(val<DO> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<EXPRESSION> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<FOR> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<FOR_COLLECTION> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<FREE> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<IMPORT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<LOOP> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<OP_ASSIGNMENT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<READ_LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<RETURN> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<THROW> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<TRY> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<TYPE_CONSTRAINT> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<WRITE_LOCK> const & value) { throw std::logic_error("not implemented"); }
	void operator()(val<USING> const & value) { throw std::logic_error("not implemented"); }

};

scope::scope(module & m, source_code const * source, scope * parent, STATEMENT_SCOPE const & dom) :
	natural_value(buildConcreteValue(m)),
	m(m),
	source(source),
	parent(parent)
{
	for (std::variant<val<IC>, val<STATEMENT>> const & entry : dom) {
		val<STATEMENT> const * statementPtr = std::get_if<val<STATEMENT>>(&entry);
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
