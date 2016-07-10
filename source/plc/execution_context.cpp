#include "execution_context.h"
#include "value.h"
#include "Errors.h"


execution_context::execution_context(Scope& scope, Thread& creatingThread): scope(scope), creating_thread(creatingThread) {}

execution_context::~execution_context() {}

value execution_context::evaluate(Expression const & exp)
{
	emit_NotImplemented(__FUNCTION__);
	throw;
}

value execution_context::type_of(Expression const & exp)
{
	emit_NotImplemented(__FUNCTION__);
	throw;
}
