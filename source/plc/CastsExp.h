#ifndef CASTS_EXP_H
#define CASTS_EXP_H

#include "BinaryOpExp.h"
class CastsExp :
	public BinaryOpExp
{
public:
	CastsExp();
	~CastsExp();
	value evaluate() const override;
	std::u32string get_name() const override;
};

#endif //CASTS_EXP_H
