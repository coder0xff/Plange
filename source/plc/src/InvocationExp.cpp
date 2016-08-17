#include "InvocationExp.hpp"
#include "value.hpp"



InvocationExp::InvocationExp()
{
}


InvocationExp::InvocationExp(InvocationExp const & other) : function(clone(*other.function))
{
	for (auto const & argument : other.arguments) {
		arguments.resize(arguments.size() + 1);
		auto temp = clone(*argument);
		arguments.rbegin()->swap(temp);
	}
}

InvocationExp::~InvocationExp()
{
}

value InvocationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
