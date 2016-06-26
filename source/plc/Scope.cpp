#include "Scope.h"
#include "plange_grammar.hpp"

Scope::Scope(SourceCode & source) : parent(nullptr), sourceCode(source), isPure(false), isAtomic(false), isReentrant(false)
{
	static parlex::state_machine const & statementProduction = get_plange().get_productions().find("STATEMENT")->second;
	static parlex::state_machine const & assignmentProduction = get_plange().get_productions().find("ASSIGNMENT")->second;
	static parlex::state_machine const & declarationProduction = get_plange().get_productions().find("DECLARATION")->second;
	static parlex::state_machine const & definitionProduction = get_plange().get_productions().find("DEFINITION")->second;
	static parlex::state_machine const & doProduction = get_plange().get_productions().find("DO")->second;
	static parlex::state_machine const & expressionProduction = get_plange().get_productions().find("EXPRESSION")->second;
	static parlex::state_machine const & forProduction = get_plange().get_productions().find("FOR")->second;
	static parlex::state_machine const & for_collectionProduction = get_plange().get_productions().find("FOR_COLLECTION")->second;
	static parlex::state_machine const & freeProduction = get_plange().get_productions().find("FREE")->second;
	static parlex::state_machine const & ifProduction = get_plange().get_productions().find("IF")->second;
	static parlex::state_machine const & importProduction = get_plange().get_productions().find("IMPORT")->second;
	static parlex::state_machine const & loopProduction = get_plange().get_productions().find("LOOP")->second;
	static parlex::state_machine const & returnProduction = get_plange().get_productions().find("RETURN")->second;
	static parlex::state_machine const & throwProduction = get_plange().get_productions().find("THROW")->second;
	static parlex::state_machine const & tryProduction = get_plange().get_productions().find("TRY")->second;
	static parlex::builtins::string_terminal const & breakLiteral = get_plange().get_literals().find(U"break")->second;
	static parlex::builtins::string_terminal const & continueLiteral = get_plange().get_literals().find(U"continue")->second;
	parlex::abstract_syntax_graph const & asg = source.graph;
	for (parlex::match const & m : *asg.permutations.find(asg.root)->second.begin()) {
		if (&m.r == &statementProduction) {
			parlex::permutation const & children = *asg.permutations.find(m)->second.begin();
			parlex::match const & command = children[0];
			if (&command.r == (parlex::recognizer *)&assignmentProduction) {

			}
		}
	}
}

Scope::~Scope()
{
}
