#ifndef PRE_DEC_EXP_H
#define PRE_DEC_EXP_H

#include "UnaryOpExp.h"
class PreDecExp :
	public UnaryOpExp
{
public:
	PreDecExp();
	~PreDecExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //PRE_DEC_EXP_H
