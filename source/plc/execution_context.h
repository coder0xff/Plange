#ifndef EXECUTION_CONTEXT_H
#define EXECUTION_CONTEXT_H

class Expression;
class value;
class Scope;
class Thread;

class execution_context {
public:
	execution_context(Scope& scope, Thread& creatingThread);
	~execution_context();
	Scope& scope;
	Thread& creating_thread;
	void continue_();
	value evaluate(Expression const & exp);
	value type_of(Expression const & exp);
};

#endif
