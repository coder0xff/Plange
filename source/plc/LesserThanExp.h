#ifndef LESSER_THAN_EXP_H
#define LESSER_THAN_EXP_H

#include "BinaryOpExp.h"
class LesserThanExp :
	public BinaryOpExp
{
public:
	LesserThanExp();
	~LesserThanExp();

	std::u32string get_name() const override;

};

#endif //LESSER_THAN_EXP_H
