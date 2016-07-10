#ifndef NOT_GREATER_THAN_EXP_H
#define NOT_GREATER_THAN_EXP_H

#include "BinaryOpExp.h"
class NotGreaterThan :
	public BinaryOpExp
{
public:
	NotGreaterThan();
	~NotGreaterThan();

	std::u32string get_name() const override;

};

#endif //NOT_GREATER_THAN_EXP_H
