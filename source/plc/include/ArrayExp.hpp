#ifndef ARRAY_EXP_HPP
#define ARRAY_EXP_HPP

#include "CollectionExp.hpp"

class ArrayExp :
	public CollectionExp {
public:
	value evaluate() const override;
};

#endif //ARRAY_EXP_HPP
