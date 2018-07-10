#include "stdafx.hpp"
#include "module.hpp"

#include <fstream>

#pragma warning(push, 0)
#include "llvm/IR/Constants.h"
#pragma warning(pop)


#include "compiler.hpp"
#include "errors.hpp"
#include "utf.hpp"

plc::module::module() : llvm_module("module", llvm_context), plange(*this, nullptr, nullptr)
{
}

void plc::module::compile(std::string output_filename) const
{
	ERROR(NotImplemented, "");
}

plc::source_code const & plc::module::add_source(std::string pathname) {
	sources.emplace_back(pathname);
	return sources.back();
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
	auto const i = global_strings.find(s);
	if (i != global_strings.end()) return i->second;
	llvm::StringRef const str(to_utf8(s));
	auto const strConstant = llvm::ConstantDataArray::getString(llvm_context, str);
	auto gv = new llvm::GlobalVariable(llvm_module, strConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, strConstant);
	auto const name = "str" + std::to_string(global_strings.size());
	gv->setName(name);
	//gv->setUnnamedAddr(true)
	return global_strings[s] = gv;
}
