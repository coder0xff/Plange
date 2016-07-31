#ifndef IMPORT_HPP
#define IMPORT_HPP

#include "Statement.hpp"

class Import :
	public Statement {
public:
	Import();
	~Import();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //IMPORT_HPP
