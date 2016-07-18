#ifndef TUPLE_EXP_H
#define TUPLE_EXP_H

#include "CollectionExp.h"

class TupleExp :
	public CollectionExp
{
public:
	TupleExp();
	~TupleExp();
	value evaluate() const override;
};

#endif //TUPLE_EXP_H
