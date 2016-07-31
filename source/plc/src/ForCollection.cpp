#include "ForCollection.hpp"


ForCollection::ForCollection() {}


ForCollection::~ForCollection() {}

std::unique_ptr<Statement> ForCollection::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
