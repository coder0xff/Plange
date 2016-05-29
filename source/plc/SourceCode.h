#ifndef SOURCE_CODE_H
#define SOURCE_CODE_H

#include "parlex/abstract_syntax_graph.hpp"

class SourceCode
{
public:
	SourceCode();
	~SourceCode();
	parlex::abstract_syntax_graph graph;
};

#endif