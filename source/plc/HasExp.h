#ifndef HAS_EXP_H
#define HAS_EXP_H

#include "BinaryOpExp.h"
class HasExp :
	public BinaryOpExp
{
public:
	HasExp();
	~HasExp();

	std::u32string get_name() const override;

};

#endif //HAS_EXP_H
