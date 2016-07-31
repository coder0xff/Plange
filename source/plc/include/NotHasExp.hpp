#ifndef NOT_HPPAS_EXP_HPP
#define NOT_HPPAS_EXP_HPP

#include "BinaryOpExp.hpp"
class NotHasExp :
	public BinaryOpExp
{
public:
	NotHasExp();
	~NotHasExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //NOT_HPPAS_EXP_HPP
