#ifndef ADDITION_EXP_HPP
#define ADDITION_EXP_HPP

#include "BinaryOpExp.hpp"

class AdditionExp : public BinaryOpExp {
public:
	AdditionExp();
	~AdditionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //ADDITON_EXP_HPP
