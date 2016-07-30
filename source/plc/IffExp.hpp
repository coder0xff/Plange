#ifndef IFF_EXP_HPP
#define IFF_EXP_HPP

#include "BinaryOpExp.hpp"
class IffExp :
	public BinaryOpExp
{
public:
	IffExp();
	~IffExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //IFF_EXP_HPP
