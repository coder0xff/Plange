#pragma once
#include "Statement.h"
class ExpressionStatement :
	public Statement
{
public:
	ExpressionStatement();
	~ExpressionStatement();
	static std::unique_ptr<Statement> Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg);
};

