#ifndef MODULE_HPP
#define MODULE_HPP

#include <unordered_map>

#pragma warning(push, 0)
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>
#pragma warning(pop)

#include "source_code.hpp"
#include "scope.hpp"

namespace plc
{

	class compiler;
	class scope;

	class module
	{
	public:
		module();
		void compile(std::string output_filename) const;
		source_code const & add_source(std::string pathname);
		llvm::Module const& get_llvm_module() const;
		llvm::Module& get_llvm_module();
	private:
		friend class compiler;
		std::vector<source_code> sources;
		llvm::Module llvm_module;
		std::unordered_map<std::u32string, llvm::GlobalVariable *> global_strings;
		llvm::GlobalVariable* get_or_add_global_string(std::u32string const& s);
		scope plange;
	};
}

#endif
