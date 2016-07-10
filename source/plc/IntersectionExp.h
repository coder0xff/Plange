#ifndef INTERSECTION_EXP_H
#define INTERSECTION_EXP_H

#include "BinaryOpExp.h"
class IntersectionExp :
	public BinaryOpExp
{
public:
	IntersectionExp();
	~IntersectionExp();

	std::u32string get_name() const override;

};

#endif //INTERSECTION_EXP_H
