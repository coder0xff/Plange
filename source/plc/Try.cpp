#include "Try.h"



Try::Try()
{
}


Try::~Try()
{
}

std::unique_ptr<Statement> Try::Build(parlex::match const & m, parlex::abstract_syntax_graph const & asg)
{
	throw std::exception("Not implemented.");
}
