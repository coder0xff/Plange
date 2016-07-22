#ifndef MAPS_TO_EXP_H
#define MAPS_TO_EXP_H

#include "BinaryOpExp.h"
class MapsToExp :
	public BinaryOpExp
{
public:
	MapsToExp();
	~MapsToExp();
	value evaluate() const override;

	std::u32string get_name() const override;

};

#endif //MAPS_TO_EXP_H
