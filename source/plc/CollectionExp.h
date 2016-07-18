#ifndef COLLECTION_EXP_H
#define COLLECTION_EXP_H

#include "Expression.h"
#include <vector>
#include <memory>

class CollectionExp :
	public Expression {
public:
	CollectionExp();
	CollectionExp(CollectionExp const & other);
	~CollectionExp() = default;
	std::vector<std::unique_ptr<Expression>> elements;
	virtual value evaluate() const = 0;
};

#endif //COLLECTION_EXP_H
