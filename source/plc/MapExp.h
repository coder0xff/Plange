#ifndef MAP_EXP_H
#define MAP_EXP_H

#include "Expression.h"
#include <map>

class MapExp :
	public Expression
{
public:
	MapExp();
	MapExp(MapExp const & other);
	~MapExp();
	std::map<std::unique_ptr<Expression>, std::unique_ptr<Expression>> elements;
	value evaluate() const override;
};

#endif //MAP_EXP_H
