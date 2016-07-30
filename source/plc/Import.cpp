#include "Import.h"


Import::Import() {}


Import::~Import() {}

std::unique_ptr<Statement> Import::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}
