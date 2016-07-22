#ifndef COMPOSITION_EXP_H
#define COMPOSITION_EXP_H

#include "BinaryOpExp.h"
class CompositionExp :
	public BinaryOpExp
{
public:
	CompositionExp();
	~CompositionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //COMPOSITION_EXP_H
