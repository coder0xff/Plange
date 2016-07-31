#ifndef CONTINUE_HPP
#define CONTINUE_HPP

#include "Statement.hpp"

class Continue :
	public Statement {
public:
	Continue();
	~Continue();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //CONTINUE_HPP
