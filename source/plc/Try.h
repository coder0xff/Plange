#ifndef TRY_H
#define TRY_H

#include "Statement.h"

class Try :
	public Statement {
public:
	Try();
	~Try();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //TRY_H
