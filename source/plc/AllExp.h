#ifndef ALL_EXP_H
#define ALL_EXP_H

#include "UnaryOpExp.h"
class AllExp :
	public UnaryOpExp
{
public:
	AllExp();
	~AllExp();
	std::u32string get_name() const override;
	bool get_postfix() const override;
};

#endif //ALL_EXP_H
