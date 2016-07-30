#include "Break.h"


Break::Break() {}


Break::~Break() {}

std::unique_ptr<Statement> Break::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
