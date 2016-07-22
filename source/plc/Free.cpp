#include "Free.h"


Free::Free() {}


Free::~Free() {}

std::unique_ptr<Statement> Free::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::exception("Not implemented.");
}
