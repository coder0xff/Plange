#ifndef DO_HPP
#define DO_HPP

#include "Statement.h"

class Do :
	public Statement {
public:
	Do();
	~Do();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //DO_HPP
