#ifndef EXISTS_ONE_EXP_H
#define EXISTS_ONE_EXP_H

#include "UnaryOpExp.h"
class ExistsOneExp :
	public UnaryOpExp
{
public:
	ExistsOneExp();
	~ExistsOneExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //EXISTS_ONE_EXP_H
