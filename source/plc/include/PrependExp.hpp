#ifndef PREPEND_EXP_HPP
#define PREPEND_EXP_HPP

#include "BinaryOpExp.hpp"
class PrependExp :
	public BinaryOpExp
{
public:
	PrependExp();
	~PrependExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //PREPEND_EXP_HPP
