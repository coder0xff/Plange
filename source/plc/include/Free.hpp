#ifndef FREE_HPP
#define FREE_HPP

#include "Statement.hpp"

class Free :
	public Statement {
public:
	Free();
	~Free();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //FREE_HPP
