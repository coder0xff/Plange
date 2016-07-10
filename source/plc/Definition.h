#pragma once
#include "Statement.h"

class Definition :
	public Statement {
public:
	Definition();
	~Definition();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};
