#include "Scope.h"
#include "plange_grammar.hpp"

Scope::Scope(SourceCode & source) : parent(nullptr), sourceCode(source), isPure(false), isAtomic(false), isReentrant(false)
{
	static parlex::state_machine const & statementProduction = get_plange().get_productions().find("STATEMENT")->second;
	parlex::abstract_syntax_graph const & asg = source.graph;
	for (parlex::match const & m : *asg.permutations.find(asg.root)->second.begin()) {
		if (&m.r == &statementProduction) {
			parlex::permutation const & children = *asg.permutations.find(m)->second.begin();
			parlex::match const & command = children[0];
		}
	}
}

Scope::~Scope()
{
}
