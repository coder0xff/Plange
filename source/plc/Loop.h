#pragma once
#include "Statement.h"

class Loop :
	public Statement {
public:
	Loop();
	~Loop();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
