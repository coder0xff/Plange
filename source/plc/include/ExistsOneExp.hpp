#ifndef EXISTS_ONE_EXP_HPP
#define EXISTS_ONE_EXP_HPP

#include "UnaryOpExp.hpp"
class ExistsOneExp :
	public UnaryOpExp
{
public:
	ExistsOneExp(Expression const & subExpression);
	~ExistsOneExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //EXISTS_ONE_EXP_HPP
