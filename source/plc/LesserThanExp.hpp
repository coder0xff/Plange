#ifndef LESSER_THAN_EXP_HPP
#define LESSER_THAN_EXP_HPP

#include "BinaryOpExp.hpp"
class LesserThanExp :
	public BinaryOpExp
{
public:
	LesserThanExp();
	~LesserThanExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //LESSER_THAN_EXP_HPP
