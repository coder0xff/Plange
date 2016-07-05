#include "Throw.h"



Throw::Throw()
{
}


Throw::~Throw()
{
}

std::unique_ptr<Statement> Throw::Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg)
{
	throw std::exception("Not implemented.");
}
