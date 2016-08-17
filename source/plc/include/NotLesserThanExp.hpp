#ifndef NOT_LESSER_THAN_EXP_HPP
#define NOT_LESSER_THAN_EXP_HPP

#include "BinaryOpExp.hpp"
class NotLesserThanExp :
	public BinaryOpExp
{
public:
	NotLesserThanExp();
	~NotLesserThanExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NOT_LESSER_THAN_EXP_HPP
