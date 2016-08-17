#ifndef NULL_COALESCE_EXP_HPP
#define NULL_COALESCE_EXP_HPP

#include "BinaryOpExp.hpp"
class NullCoalesceExp :
	public BinaryOpExp
{
public:
	NullCoalesceExp();
	~NullCoalesceExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NULL_COALESCE_EXP_HPP
