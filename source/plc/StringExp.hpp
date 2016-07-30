#ifndef STRING_EXP_HPP
#define STRING_EXP_HPP

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

#endif //STRING_EXP_HPP
