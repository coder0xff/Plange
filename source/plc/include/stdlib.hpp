#ifndef STDLIB_HPP
#define STDLIB_HPP

#pragma warning(push, 0)
#include "llvm/IR/Module.h"
#pragma warning(pop)

void loadStdLib(llvm::Module *module);

#endif //STDLIB_HPP
