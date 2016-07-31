#ifndef TRY_HPP
#define TRY_HPP

#include "Statement.hpp"

class Try :
	public Statement {
public:
	Try();
	~Try();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //TRY_HPP
