#ifndef COMPOSITION_EXP_HPP
#define COMPOSITION_EXP_HPP

#include "BinaryOpExp.hpp"
class CompositionExp :
	public BinaryOpExp
{
public:
	CompositionExp();
	~CompositionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //COMPOSITION_EXP_HPP
