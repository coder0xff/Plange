#ifndef PRE_INC_EXP_H
#define PRE_INC_EXP_H

#include "UnaryOpExp.h"
class PreIncExp :
	public UnaryOpExp
{
public:
	PreIncExp();
	~PreIncExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //PRE_INC_EXP_H
