#ifndef LIST_EXP_HPP
#define LIST_EXP_HPP

#include "CollectionExp.hpp"

class ListExp :
	public CollectionExp
{
public:
	value evaluate(execution_context &exc) const override;
};

#endif //LIST_EXP_HPP
