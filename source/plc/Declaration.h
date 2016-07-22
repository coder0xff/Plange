#ifndef DECLARATION_H
#define DECLARATION_H

#include "Statement.h"

class Declaration :
	public Statement {
public:
	Declaration();
	~Declaration();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //DECLARATION_H
