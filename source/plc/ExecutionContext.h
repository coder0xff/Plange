#ifndef EXECUTION_CONTEXT_H
#define EXECUTION_CONTEXT_H

class Scope;
class Thread;

class ExecutionContext
{
public:
	ExecutionContext();
	~ExecutionContext();
	Scope * scope;
	Thread * creatingThread;
	void continue_();
};

#endif