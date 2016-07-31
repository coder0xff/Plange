#ifndef RETURN_HPP
#define RETURN_HPP

#include "Statement.hpp"

class Return :
	public Statement {
public:
	Return();
	~Return();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //RETURN_HPP