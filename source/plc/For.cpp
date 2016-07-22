#include "For.h"


For::For() {}


For::~For() {}

std::unique_ptr<Statement> For::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
