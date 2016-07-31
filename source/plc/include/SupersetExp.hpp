#ifndef SUPERSET_EXP_HPP
#define SUPERSET_EXP_HPP

#include "BinaryOpExp.hpp"
class SupersetExp :
	public BinaryOpExp
{
public:
	SupersetExp();
	~SupersetExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SUPERSET_EXP_HPP
