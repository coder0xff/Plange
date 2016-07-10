#pragma once
#include "Statement.h"

class Import :
	public Statement {
public:
	Import();
	~Import();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
