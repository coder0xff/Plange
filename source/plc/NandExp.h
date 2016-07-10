#ifndef NAND_EXP_H
#define NAND_EXP_H

#include "BinaryOpExp.h"
class NandExp :
	public BinaryOpExp
{
public:
	NandExp();
	~NandExp();

	std::u32string get_name() const override;

};

#endif //NAND_EXP_H
