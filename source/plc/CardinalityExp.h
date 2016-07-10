#ifndef CARDINALITY_EXP_H
#define CARDINALITY_EXP_H

#include "UnaryOpExp.h"
class CardinalityExp :
	public UnaryOpExp
{
public:
	CardinalityExp();
	~CardinalityExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //CARDINALITY_EXP_H
