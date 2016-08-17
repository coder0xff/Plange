#ifndef TUPLE_EXP_HPP
#define TUPLE_EXP_HPP

#include "CollectionExp.hpp"

class TupleExp :
	public CollectionExp
{
public:
	TupleExp();
	~TupleExp();
	value evaluate(execution_context &exc) const override;
};

#endif //TUPLE_EXP_HPP
