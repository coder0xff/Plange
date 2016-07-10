#ifndef OR_EXP_H
#define OR_EXP_H

#include "BinaryOpExp.h"
class OrExp :
	public BinaryOpExp
{
public:
	OrExp();
	~OrExp();

	std::u32string get_name() const override;

};

#endif //OR_EXP_H
