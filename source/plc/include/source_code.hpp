#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include "parlex/parser.hpp"
#pragma warning(push, 0)
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#pragma warning(pop)

class scope;

class source_code {
public:
	source_code(std::string const& pathname, std::u32string const& document, parlex::parser& parser, llvm::LLVMContext & llvmContext);
	~source_code();
	std::u32string const document;
	parlex::abstract_syntax_graph const asg;
	std::unique_ptr<llvm::Module> const module;
	std::pair<int, int> get_line_number_and_column(int charIndex);
	void compile();
private:
	std::map<int, int> line_number_by_first_character;
	std::map<std::u32string, llvm::Value *> global_strings;

	llvm::Value * get_or_add_global_string(llvm::LLVMContext & context, std::u32string const & s);
	std::unique_ptr<::scope> scope;
};

#endif
