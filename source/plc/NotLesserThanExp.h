#ifndef NOT_LESSER_THAN_EXP_H
#define NOT_LESSER_THAN_EXP_H

#include "BinaryOpExp.h"
class NotLesserThanExp :
	public BinaryOpExp
{
public:
	NotLesserThanExp();
	~NotLesserThanExp();

	std::u32string get_name() const override;

};

#endif //NOT_LESSER_THAN_EXP_H
