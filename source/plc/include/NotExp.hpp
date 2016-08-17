#ifndef NOT_EXP_HPP
#define NOT_EXP_HPP

#include "UnaryOpExp.hpp"
class NotExp :
	public UnaryOpExp
{
public:
	NotExp(Expression const & subExpression);
	~NotExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NOT_EXP_HPP
