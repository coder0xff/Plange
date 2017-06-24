#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <stdexcept>

#pragma warning(push, 0)
#include <llvm/IR/LLVMContext.h>
#pragma warning(pop)

#include "warnings.hpp"
#include "errors.hpp"

namespace plc {
	extern llvm::LLVMContext llvmContext;
}

#endif
