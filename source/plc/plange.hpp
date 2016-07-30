#ifndef PLANGE_HPP
#define PLANGE_HPP

#include "value.h"
#include "Expression.h"

class plange
{
public:
	plange();
	~plange();
	static bool is_Collection(const Expression& v);
	static bool is_Integral(const Expression& v);
	static value& get_Float();
	static value& get_Float16();
	static value& get_Float32();
	static value& get_Float64();
	static value& get_Float128();
	static value& get_Int();
	static value& get_Int8();
	static value& get_Int16();
	static value& get_Int32();
	static value& get_Int64();
	static value& get_Int128();
	static value& get_Real();
	static value& get_global(std::vector<std::u32string> qualifiers, std::u32string name);
};

#endif //PLANGE_HPP
