#pragma once
#include "Statement.h"

class Break :
	public Statement {
public:
	Break();
	~Break();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
