#ifndef FREE_H
#define FREE_H

#include "Statement.h"

class Free :
	public Statement {
public:
	Free();
	~Free();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //FREE_H
