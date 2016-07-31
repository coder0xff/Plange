#include "Throw.hpp"


Throw::Throw() {}


Throw::~Throw() {}

std::unique_ptr<Statement> Throw::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
