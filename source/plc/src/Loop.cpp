#include "Loop.hpp"


Loop::Loop() {}


Loop::~Loop() {}

std::unique_ptr<Statement> Loop::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
