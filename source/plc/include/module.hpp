#ifndef INCLUDED_PLC_MODULE_HPP
#define INCLUDED_PLC_MODULE_HPP

// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <unordered_map>

#pragma warning(push, 0)
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Module.h"
#pragma warning(pop)

#include "scope.hpp"
#include "source_code.hpp"

namespace plc {

class compiler;
class scope;

class module
{
	friend class compiler;
public:
	explicit module(compiler & owner, nptr<source_code const> source);
	void compile(std::string const & outputFilename);
	llvm::Module const& get_llvm_module() const;
	llvm::Module& get_llvm_module();
	compiler & get_compiler() const;
	nptr<source_code const> get_source() const;
private:
	compiler & owner;
	nptr<source_code const> source;
	llvm::Module llvm_module;
	std::unordered_map<std::u32string, llvm::GlobalVariable *> global_strings;
	llvm::GlobalVariable* get_or_add_global_string(std::u32string const& s);
	val<scope> plange;
};

} // namespace plc

#endif // INCLUDED_PLC_MODULE_HPP
