#ifndef IMPLICATION_EXP_H
#define IMPLICATION_EXP_H

#include "BinaryOpExp.h"
class ImplicationExp :
	public BinaryOpExp
{
public:
	ImplicationExp();
	~ImplicationExp();

	std::u32string get_name() const override;

};

#endif //IMPLICATION_EXP_H
