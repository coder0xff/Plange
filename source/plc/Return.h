#pragma once
#include "Statement.h"

class Return :
	public Statement {
public:
	Return();
	~Return();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
