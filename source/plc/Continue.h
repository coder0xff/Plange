#ifndef CONTINUE_H
#define CONTINUE_H

#include "Statement.h"

class Continue :
	public Statement {
public:
	Continue();
	~Continue();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //CONTINUE_H
