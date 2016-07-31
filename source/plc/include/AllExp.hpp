#ifndef ALL_EXP_HPP
#define ALL_EXP_HPP

#include "UnaryOpExp.hpp"
class AllExp :
	public UnaryOpExp
{
public:
	AllExp(Expression const & subExpression);
	~AllExp();
	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //ALL_EXP_HPP
