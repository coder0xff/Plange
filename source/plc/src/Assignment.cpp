#include "Assignment.hpp"


Assignment::Assignment() {}


Assignment::~Assignment() {}

std::unique_ptr<Statement> Assignment::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
