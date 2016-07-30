#ifndef OR_EXP_HPP
#define OR_EXP_HPP

#include "BinaryOpExp.hpp"
class OrExp :
	public BinaryOpExp
{
public:
	OrExp();
	~OrExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //OR_EXP_HPP
