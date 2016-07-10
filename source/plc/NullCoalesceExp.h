#ifndef NULL_COALESCE_EXP_H
#define NULL_COALESCE_EXP_H

#include "BinaryOpExp.h"
class NullCoalesceExp :
	public BinaryOpExp
{
public:
	NullCoalesceExp();
	~NullCoalesceExp();

	std::u32string get_name() const override;

};

#endif //NULL_COALESCE_EXP_H
