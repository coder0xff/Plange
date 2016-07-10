#ifndef NEGATION_EXP_H
#define NEGATION_EXP_H

#include "UnaryOpExp.h"
class NegationExp :
	public UnaryOpExp
{
public:
	NegationExp();
	~NegationExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //NEGATION_EXP_H
