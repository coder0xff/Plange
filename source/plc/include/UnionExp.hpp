#ifndef UNION_EXP_HPP
#define UNION_EXP_HPP

#include "BinaryOpExp.hpp"
class UnionExp :
	public BinaryOpExp
{
public:
	UnionExp();
	~UnionExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //UNION_EXP_HPP
