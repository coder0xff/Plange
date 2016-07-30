#ifndef SUBSET_EXP_HPP
#define SUBSET_EXP_HPP

#include "BinaryOpExp.hpp"
class SubsetExp :
	public BinaryOpExp
{
public:
	SubsetExp();
	~SubsetExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SUBSET_EXP_HPP
