#ifndef LIST_EXP_H
#define LIST_EXP_H

#include "CollectionExp.h"

class ListExp :
	public CollectionExp
{
public:
	value evaluate() const override;
};

#endif //LIST_EXP_H
