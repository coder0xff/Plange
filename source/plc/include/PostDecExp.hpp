#ifndef POST_DEC_EXP_HPP
#define POST_DEC_EXP_HPP

#include "UnaryOpExp.hpp"
class PostDecExp :
	public UnaryOpExp
{
public:
	PostDecExp(Expression const & subExpression);
	~PostDecExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //POST_DEC_EXP_HPP
