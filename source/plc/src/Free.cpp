#include "Free.hpp"


Free::Free() {}


Free::~Free() {}

std::unique_ptr<Statement> Free::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
