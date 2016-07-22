#include "Declaration.h"


Declaration::Declaration() {}


Declaration::~Declaration() {}

std::unique_ptr<Statement> Declaration::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
