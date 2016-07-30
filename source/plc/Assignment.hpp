#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include "Statement.h"
#include <vector>
#include "Expression.h"

class Assignment :
	public Statement {
public:
	Assignment();
	virtual ~Assignment();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
	std::vector<std::unique_ptr<Expression>> parts;
};

#endif //ASSIGNMENT_HPP
