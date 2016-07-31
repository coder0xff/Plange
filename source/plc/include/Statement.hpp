#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <memory>

namespace parlex {
	struct abstract_syntax_graph;
	struct match;
}

class Statement {
public:
	Statement();
	virtual ~Statement();
	std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif
