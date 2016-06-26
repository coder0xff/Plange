#ifndef SCOPE_H
#define SCOPE_H

#include <vector>
#include "SourceCode.h"
#include "Constant.h"
#include "Assertion.h"
#include "Statement.h"
#include "Variable.h"
#include "FunctionModel.h"
#include "SideEffect.h"

class Scope
{
public:
	explicit Scope(SourceCode & source);
	~Scope();
	Scope * parent;
	std::vector<Scope> children;
	SourceCode const & sourceCode;
	std::vector<Constant> constants;
	std::vector<Assertion> assertions;
	std::vector<Statement> statements;
	std::vector<Variable> variables;
	bool isPure;
	bool isAtomic;
	bool isReentrant;
	FunctionModel model;
	std::vector<SideEffect> sideEffects;
	bool isDescendentOf(Scope const & s);
	bool canExecute(Scope const & s);
};

#endif SCOPE_H