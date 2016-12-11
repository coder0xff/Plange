#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <vector>

#pragma warning(push, 0)
#include <llvm/IR/IRBuilder.h>
#pragma warning(pop)

#include "source_code.hpp"
#include "statement.hpp"
#include "abstract_value.hpp"
#include "symbol.hpp"
#include "concrete_value.hpp"

namespace plc {

class scope : public concrete_value {
public:
	scope(source_code const & source_ptr, scope & parent, llvm::LLVMContext & llvmContext, llvm::Module & module);
	explicit scope(llvm::Function * llvmFunction);
	~scope() = default;
	source_code const * const source_ptr; //will be null if Plange scope, at least while were in c++
	scope * const parent;
	std::vector<scope> children;
	symbol_table symbols;
	bool is_descendent_of(scope const& s);
	bool can_execute(scope const& s);
	llvm::Function& getLLVMFunction() const;
};

}
#endif //SCOPE_HPP
