#include "ExpressionStatement.h"


ExpressionStatement::ExpressionStatement() {}


ExpressionStatement::~ExpressionStatement() {}

std::unique_ptr<Statement> ExpressionStatement::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
