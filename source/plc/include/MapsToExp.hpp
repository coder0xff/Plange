#ifndef MAPS_TO_EXP_HPP
#define MAPS_TO_EXP_HPP

#include "BinaryOpExp.hpp"
class MapsToExp :
	public BinaryOpExp
{
public:
	MapsToExp();
	~MapsToExp();
	value evaluate() const override;

	std::u32string get_name() const override;

};

#endif //MAPS_TO_EXP_HPP
