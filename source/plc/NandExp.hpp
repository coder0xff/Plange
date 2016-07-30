#ifndef NAND_EXP_HPP
#define NAND_EXP_HPP

#include "BinaryOpExp.hpp"
class NandExp :
	public BinaryOpExp
{
public:
	NandExp();
	~NandExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //NAND_EXP_HPP
