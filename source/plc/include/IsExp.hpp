#ifndef IS_EXP_HPP
#define IS_EXP_HPP

#include "BinaryOpExp.hpp"
class IsExp :
	public BinaryOpExp
{
public:
	IsExp();
	~IsExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //IS_EXP_HPP
