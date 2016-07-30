#ifndef INTERSECTION_EXP_HPP
#define INTERSECTION_EXP_HPP

#include "BinaryOpExp.hpp"
class IntersectionExp :
	public BinaryOpExp
{
public:
	IntersectionExp();
	~IntersectionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //INTERSECTION_EXP_HPP
