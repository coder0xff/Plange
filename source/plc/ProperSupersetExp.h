#ifndef PROPER_SUPERSET_EXP_H
#define PROPER_SUPERSET_EXP_H

#include "BinaryOpExp.h"
class ProperSupersetExp :
	public BinaryOpExp
{
public:
	ProperSupersetExp();
	~ProperSupersetExp();

	std::u32string get_name() const override;

};

#endif //PROPER_SUPERSET_EXP_H
