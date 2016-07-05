#include "ForCollection.h"



ForCollection::ForCollection()
{
}


ForCollection::~ForCollection()
{
}

std::unique_ptr<Statement> ForCollection::Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg)
{
	throw std::exception("Not implemented.");
}
