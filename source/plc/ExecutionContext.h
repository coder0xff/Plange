#ifndef EXECUTION_CONTEXT_H
#define EXECUTION_CONTEXT_H

class Scope;
class Thread;

class ExecutionContext
{
public:
	ExecutionContext(Scope& scope, Thread& creatingThread);
	~ExecutionContext();
	Scope & scope;
	Thread & creating_thread;
	void continue_();
};

#endif