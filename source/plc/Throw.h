#ifndef THROW_H
#define THROW_H

#include "Statement.h"

class Throw :
	public Statement {
public:
	Throw();
	~Throw();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //THROW_H
