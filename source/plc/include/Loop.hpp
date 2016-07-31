#ifndef LOOP_HPP
#define LOOP_HPP

#include "Statement.hpp"

class Loop :
	public Statement {
public:
	Loop();
	~Loop();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //LOOP_HPP
