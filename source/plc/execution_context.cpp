#include "execution_context.h"
#include "value.h"
#include "Errors.h"


execution_context::execution_context(Scope& scope, Thread& creatingThread): scope(scope), creating_thread(creatingThread) {}

execution_context::~execution_context() {}

value execution_context::evaluate(Expression const & exp)
{
	ERROR(NotImplemented, __FUNCTION__);
}

value execution_context::type_of(Expression const & exp)
{
	ERROR(NotImplemented, __FUNCTION__);
}
