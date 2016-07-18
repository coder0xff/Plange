#ifndef ADDITION_EXP_H
#define ADDITION_EXP_H

#include "BinaryOpExp.h"

class AdditionExp : public BinaryOpExp {
public:
	AdditionExp();
	~AdditionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //ADDITON_EXP_H
