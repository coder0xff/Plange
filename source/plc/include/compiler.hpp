#ifndef PLC_UTILS_HPP
#define PLC_UTILS_HPP

#include "source_code.hpp"

namespace plc {
class module;

class compiler
	{
	public:
		compiler();
		void inject_c_std_lib(module & m);
	private:
		source_code c_std_lib_source;
	};
}

#endif //PLC_UTILS_HPP
