#include "stdafx.hpp"

#include "module.hpp"
#include <llvm/IR/Constants.h>
#include "utils.hpp"

plc::module::module(std::vector<std::reference_wrapper<source_code const>> sources) : sources(sources), llvm_module("module", llvmContext), global(*this, nullptr, nullptr)
{
}

void plc::module::compile(std::string output_filename) const
{
	ERROR(NotImplemented, "");
}

llvm::Module const & plc::module::get_llvm_module() const
{
	return llvm_module;
}

llvm::Module & plc::module::get_llvm_module()
{
	return llvm_module;
}

llvm::GlobalVariable * plc::module::get_or_add_global_string(std::u32string const& s)
{
	auto i = global_strings.find(s);
	if (i != global_strings.end()) return i->second;
	llvm::StringRef Str(to_utf8(s));
	auto StrConstant = llvm::ConstantDataArray::getString(llvmContext, Str);
	auto gv = new llvm::GlobalVariable(llvm_module, StrConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, StrConstant);
	auto name = "str" + std::to_string(global_strings.size());
	gv->setName(name);
	//gv->setUnnamedAddr(true)
	return global_strings[s] = gv;
}
