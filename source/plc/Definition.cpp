#include "Definition.h"


Definition::Definition() {}


Definition::~Definition() {}

std::unique_ptr<Statement> Definition::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
