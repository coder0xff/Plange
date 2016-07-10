#pragma once
#include "Statement.h"

class Throw :
	public Statement {
public:
	Throw();
	~Throw();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
