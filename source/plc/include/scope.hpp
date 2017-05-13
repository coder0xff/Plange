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

class module;

class scope : public concrete_value {
public:
	scope(source_code const & source_ptr, scope & parent, module *m);
	~scope() = default;

	module * const m;
	source_code const * const source_ptr; //will be null if Plange scope, at least while were in c++
	scope * const parent;
	std::vector<scope> children;
	symbol_table symbols;

	bool is_descendent_of(scope const& s);
	bool can_execute(scope const& s);
private:
};

}
#endif //SCOPE_HPP
