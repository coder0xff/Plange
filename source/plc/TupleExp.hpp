#ifndef TUPLE_EXP_HPP
#define TUPLE_EXP_HPP

#include "CollectionExp.h"

class TupleExp :
	public CollectionExp
{
public:
	TupleExp();
	~TupleExp();
	value evaluate() const override;
};

#endif //TUPLE_EXP_HPP
