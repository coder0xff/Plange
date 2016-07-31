#ifndef EXPRESSION_STATEMENT_HPP
#define EXPRESSION_STATEMENT_HPP

#include "Statement.hpp"

class ExpressionStatement :
	public Statement {
public:
	ExpressionStatement();
	~ExpressionStatement();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //EXPRESSION_STATEMENT_HPP
