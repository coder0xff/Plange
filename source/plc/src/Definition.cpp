#include "Definition.hpp"


Definition::Definition() {}


Definition::~Definition() {}

std::unique_ptr<Statement> Definition::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
