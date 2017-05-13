#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <stdexcept>

#include "warnings.hpp"
#include "errors.hpp"

#include <llvm/IR/LLVMContext.h>

namespace plc {
	extern llvm::LLVMContext llvmContext;
}

#endif
