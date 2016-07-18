#ifndef ARRAY_EXP_H
#define ARRAY_EXP_H

#include "CollectionExp.h"

class ArrayExp :
	public CollectionExp {
public:
	value evaluate() const override;
};

#endif //ARRAY_EXP_H
