#ifndef MODULE_HPP
#define MODULE_HPP

#include <unordered_map>

#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>

#include "source_code.hpp"

namespace plc
{

class module
{
public:
	explicit module(std::vector<std::reference_wrapper<source_code const>> sources);
	void compile(std::string output_filename) const;
	llvm::Module const & get_llvm_module() const;
	llvm::Module & get_llvm_module();
private:
	std::vector<std::reference_wrapper<source_code const>> sources;
	llvm::Module llvm_module;
	std::unordered_map<std::u32string, llvm::GlobalVariable *> global_strings;
	llvm::GlobalVariable * get_or_add_global_string(std::u32string const& s);
};

}

#endif
