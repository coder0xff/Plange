#include "stdafx.hpp"
#include <array>

#include "scope.hpp"
#include "compiler.hpp"
#include "module.hpp"

namespace plc {

llvm::Value * buildConcreteValue(module * module) {
	std::vector<llvm::Type*> elements;
	llvm::StructType* llvm_scope_type = llvm::StructType::get(llvmContext, llvm::ArrayRef<llvm::Type*>(elements));
	std::vector<llvm::Constant*> initial_values;
	auto initial_value = llvm::ConstantStruct::get(llvm_scope_type, llvm::ArrayRef<llvm::Constant*>(initial_values));
	return new llvm::GlobalVariable(module->get_llvm_module(), llvm_scope_type, false, llvm::GlobalValue::InternalLinkage, initial_value);	
}

scope::scope(source_code const & source_ptr, scope & parent, module * m) :
		concrete_value(buildConcreteValue(m)),
		source_ptr(&source_ptr),
		parent(&parent),
		m(m)
{}

}
