#ifndef PROPER_SUBSET_EXP_HPP
#define PROPER_SUBSET_EXP_HPP

#include "BinaryOpExp.hpp"
class ProperSubsetExp :
	public BinaryOpExp
{
public:
	ProperSubsetExp();
	~ProperSubsetExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //PROPER_SUBSET_EXP_HPP