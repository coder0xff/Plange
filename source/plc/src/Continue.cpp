#include "Continue.hpp"


Continue::Continue() {}


Continue::~Continue() {}

std::unique_ptr<Statement> Continue::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
