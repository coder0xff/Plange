#ifndef THROW_HPP
#define THROW_HPP

#include "Statement.h"

class Throw :
	public Statement {
public:
	Throw();
	~Throw();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //THROW_HPP
