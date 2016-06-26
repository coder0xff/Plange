#include "ExecutionContext.h"


ExecutionContext::ExecutionContext(Scope& scope, Thread& creatingThread): scope(scope), creating_thread(creatingThread)
{
}

ExecutionContext::~ExecutionContext()
{
}
