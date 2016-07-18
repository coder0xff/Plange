#include "Statement.h"
#include "plange_grammar.hpp"
#include <cassert>
#include "Assignment.h"
#include "Try.h"
#include "Throw.h"
#include "Return.h"
#include "Loop.h"
#include "Import.h"
#include "Free.h"
#include "For.h"
#include "Declaration.h"
#include "Definition.h"
#include "Do.h"
#include "ForCollection.h"
#include "ExpressionStatement.h"
#include "Errors.h"

Statement::Statement() {}


Statement::~Statement() {}

std::unique_ptr<Statement> Statement::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	static parlex::state_machine const& statementProduction = get_plange().get_productions().find("STATEMENT")->second;
	assert(&m.r == static_cast<parlex::recognizer const *>(&statementProduction));

	static parlex::recognizer const* const assignmentProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("ASSIGNMENT")->second);
	static parlex::recognizer const* const declarationProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("DECLARATION")->second);
	static parlex::recognizer const* const definitionProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("DEFINITION")->second);
	static parlex::recognizer const* const doProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("DO")->second);
	static parlex::recognizer const* const expressionProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("EXPRESSION")->second);
	static parlex::recognizer const* const forProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("FOR")->second);
	static parlex::recognizer const* const for_collectionProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("FOR_COLLECTION")->second);
	static parlex::recognizer const* const freeProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("FREE")->second);
	static parlex::recognizer const* const importProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("IMPORT")->second);
	static parlex::recognizer const* const loopProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("LOOP")->second);
	static parlex::recognizer const* const returnProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("RETURN")->second);
	static parlex::recognizer const* const throwProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("THROW")->second);
	static parlex::recognizer const* const tryProduction = static_cast<parlex::recognizer const *>(&get_plange().get_productions().find("TRY")->second);
	parlex::match const subM = (*asg.permutations.find(m)->second.begin())[0];
	parlex::recognizer const* const r = &subM.r;
	if (r == assignmentProduction) {
		return Assignment::Build(subM, asg);
	}
	if (r == declarationProduction) {
		return Declaration::Build(subM, asg);
	}
	if (r == definitionProduction) {
		return Definition::Build(subM, asg);
	}
	if (r == doProduction) {
		return Do::Build(subM, asg);
	}
	if (r == expressionProduction) {
		return ExpressionStatement::Build(subM, asg);
	}
	if (r == forProduction) {
		return For::Build(subM, asg);
	}
	if (r == for_collectionProduction) {
		return ForCollection::Build(subM, asg);
	}
	if (r == freeProduction) {
		return Free::Build(subM, asg);
	}
	if (r == importProduction) {
		return Import::Build(subM, asg);
	}
	if (r == loopProduction) {
		return Loop::Build(subM, asg);
	}
	if (r == returnProduction) {
		return Return::Build(subM, asg);
	}
	if (r == throwProduction) {
		return Throw::Build(subM, asg);
	}
	if (r == tryProduction) {
		return Try::Build(subM, asg);
	}
	ERROR(Unknown, "");
}
