#ifndef STRING_EXP_H
#define STRING_EXP_H

#include "Expression.h"
#include <string>

class StringExp :
	public Expression
{
public:
	StringExp(std::string const & value);
	~StringExp();
	std::string val;
	value evaluate() const override;
};

#endif //STRING_EXP_H
