#ifndef STDAFX_HPP
#define STDAFX_HPP

#pragma warning(push, 0)
#include <llvm/IR/LLVMContext.h>
#pragma warning(pop)

namespace plc {

extern llvm::LLVMContext llvm_context;

}

#endif
