#ifndef COMPLEMENT_EXP_HPP
#define COMPLEMENT_EXP_HPP

#include "UnaryOpExp.hpp"
class ComplementExp :
	public UnaryOpExp
{
public:
	ComplementExp(Expression const & subExpression);
	~ComplementExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //COMPLEMENT_EXP_HPP
