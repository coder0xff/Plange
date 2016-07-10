#pragma once
#include "value.h"

class plange
{
public:
	plange();
	~plange();
	static value& get_Float();
	static value& get_Float16();
	static value& get_Float32();
	static value& get_Float64();
	static value& get_Float128();
	static value& get_Int();
	static value& get_Int16();
	static value& get_Int32();
	static value& get_Int64();
	static value& get_Int128();
	static value& get_Real();
	static value& get_global(std::vector<std::u32string> qualifiers, std::u32string name);
};

