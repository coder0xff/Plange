#ifndef SET_EXP_H
#define SET_EXP_H

#include "CollectionExp.h"

class SetExp :
	public CollectionExp
{
public:
	value evaluate() const override;
};

#endif //SET_EXP_H
