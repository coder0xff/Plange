#ifndef BREAK_HPP
#define BREAK_HPP

#include "Statement.hpp"

class Break :
	public Statement {
public:
	Break();
	~Break();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //BREAK_HPP
