#ifndef IFF_EXP_H
#define IFF_EXP_H

#include "BinaryOpExp.h"
class IffExp :
	public BinaryOpExp
{
public:
	IffExp();
	~IffExp();

	std::u32string get_name() const override;

};

#endif //IFF_EXP_H
