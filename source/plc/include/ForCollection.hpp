#ifndef FOR_COLLECTION_HPP
#define FOR_COLLECTION_HPP

#include "Statement.hpp"

class ForCollection :
	public Statement {
public:
	ForCollection();
	~ForCollection();
	static std::unique_ptr<Statement> Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg);
};

#endif //FOR_COLLECTION_HPP
