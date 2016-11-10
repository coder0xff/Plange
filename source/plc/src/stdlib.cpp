#include "stdlib.hpp"

void load_std_lib(llvm::Module *module) {
	{
		//add puts
		std::vector<llvm::Type *> args;
		args.push_back(llvm::Type::getInt8PtrTy(module->getContext()));
		llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(module->getContext()), args, false);
		module->getOrInsertFunction("puts", funcType);
	}
}
