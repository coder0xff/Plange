#include "scope.hpp"
#include "compiler.hpp"

namespace plc {

llvm::Function *buildScopeFunction(llvm::LLVMContext & llvmContext, llvm::Module & module) {
	static auto nullaryVoidFuncType = llvm::FunctionType::get(llvm::Type::getVoidTy(llvmContext), std::vector<llvm::Type*>(), false);
	return llvm::Function::Create(nullaryVoidFuncType, llvm::Function::ExternalLinkage, "", &module);
}

scope::scope(source_code const & source_ptr, scope & parent, llvm::LLVMContext & llvmContext, llvm::Module & module) :
		concrete_value(buildScopeFunction(llvmContext, module)),
		source_ptr(&source_ptr),
		parent(&parent)
{}

scope::scope(llvm::Function* llvmFunction) :
		concrete_value(llvmFunction),
		source_ptr(nullptr),
		parent(nullptr)
{}

llvm::Function& scope::getLLVMFunction() const {
	return *static_cast<llvm::Function*>(underlying.get());
}

}
