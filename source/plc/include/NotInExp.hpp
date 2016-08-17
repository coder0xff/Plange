#ifndef NOT_IN_EXP_HPP
#define NOT_IN_EXP_HPP

#include "BinaryOpExp.hpp"
class NotInExp :
	public BinaryOpExp
{
public:
	NotInExp();
	~NotInExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NOT_IN_EXP_HPP
