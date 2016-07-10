#ifndef UNION_EXP_H
#define UNION_EXP_H

#include "BinaryOpExp.h"
class UnionExp :
	public BinaryOpExp
{
public:
	UnionExp();
	~UnionExp();

	std::u32string get_name() const override;

};

#endif //UNION_EXP_H
