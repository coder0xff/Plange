#ifndef SUPERSET_EXP_H
#define SUPERSET_EXP_H

#include "BinaryOpExp.h"
class SupersetExp :
	public BinaryOpExp
{
public:
	SupersetExp();
	~SupersetExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SUPERSET_EXP_H
