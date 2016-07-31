#ifndef CASTS_EXP_HPP
#define CASTS_EXP_HPP

#include "BinaryOpExp.hpp"
class CastsExp :
	public BinaryOpExp
{
public:
	CastsExp();
	~CastsExp();
	value evaluate() const override;
	std::u32string get_name() const override;
};

#endif //CASTS_EXP_HPP
