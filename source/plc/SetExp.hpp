#ifndef SET_EXP_HPP
#define SET_EXP_HPP

#include "CollectionExp.h"

class SetExp :
	public CollectionExp
{
public:
	value evaluate() const override;
};

#endif //SET_EXP_HPP
