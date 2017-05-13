#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <stdexcept>

#include "warnings.hpp"
#include "errors.hpp"

#include <llvm/IR/LLVMContext.h>

#include "parlex/parser.hpp"

namespace plc {
	extern parlex::parser parser;
	extern llvm::LLVMContext llvmContext;
}

#endif
