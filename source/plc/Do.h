#pragma once
#include "Statement.h"

class Do :
	public Statement
{
public:
	Do();
	~Do();
	static std::unique_ptr<Statement> Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg);
};

