#include "stdlib.hpp"

void loadStdLib(llvm::Module *module) {
	{
		//add printf
		std::vector<llvm::Type *> args;
		args.push_back(llvm::Type::getInt8PtrTy(module->getContext()));
		llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(module->getContext()), args, true);
		module->getOrInsertFunction("printf", funcType);
	}
}
