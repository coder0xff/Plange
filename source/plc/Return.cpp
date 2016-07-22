#include "Return.h"


Return::Return() {}


Return::~Return() {}

std::unique_ptr<Statement> Return::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
