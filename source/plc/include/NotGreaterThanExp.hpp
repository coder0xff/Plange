#ifndef NOT_GREATER_THAN_EXP_HPP
#define NOT_GREATER_THAN_EXP_HPP

#include "BinaryOpExp.hpp"
class NotGreaterThanExp :
	public BinaryOpExp
{
public:
	NotGreaterThanExp();
	~NotGreaterThanExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NOT_GREATER_THAN_EXP_HPP
