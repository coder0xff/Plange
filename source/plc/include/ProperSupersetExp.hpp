#ifndef PROPER_SUPERSET_EXP_HPP
#define PROPER_SUPERSET_EXP_HPP

#include "BinaryOpExp.hpp"
class ProperSupersetExp :
	public BinaryOpExp
{
public:
	ProperSupersetExp();
	~ProperSupersetExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //PROPER_SUPERSET_EXP_HPP
