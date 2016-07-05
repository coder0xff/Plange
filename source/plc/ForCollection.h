#pragma once
#include "Statement.h"
class ForCollection :
	public Statement
{
public:
	ForCollection();
	~ForCollection();
	static std::unique_ptr<Statement> Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg);
};

