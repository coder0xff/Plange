#ifndef HAS_EXP_HPP
#define HAS_EXP_HPP

#include "BinaryOpExp.hpp"
class HasExp :
	public BinaryOpExp
{
public:
	HasExp();
	~HasExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //HAS_EXP_HPP
