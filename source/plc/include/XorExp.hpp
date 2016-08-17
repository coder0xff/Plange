#ifndef XOR_EXP_HPP
#define XOR_EXP_HPP

#include "BinaryOpExp.hpp"
class XorExp :
	public BinaryOpExp
{
public:
	XorExp();
	~XorExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //XOR_EXP_HPP
