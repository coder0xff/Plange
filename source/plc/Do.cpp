#include "Do.h"



Do::Do()
{
}


Do::~Do()
{
}

std::unique_ptr<Statement> Do::Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg)
{
	throw std::exception("Not implemented.");
}
