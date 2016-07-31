#ifndef FOR_HPP
#define FOR_HPP

#include "Statement.hpp"

class For :
	public Statement {
public:
	For();
	~For();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //FOR_HPP
