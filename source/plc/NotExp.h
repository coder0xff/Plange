#ifndef NOT_EXP_H
#define NOT_EXP_H

#include "UnaryOpExp.h"
class NotExp :
	public UnaryOpExp
{
public:
	NotExp();
	~NotExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //NOT_EXP_H
