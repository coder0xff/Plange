#ifndef PLC_COMPILER_HPP
#define PLC_COMPILER_HPP

#include "parlex/details/abstract_syntax_semilattice.hpp"
#include "source_code.hpp"

namespace plc {
class module;

class compiler
	{
	public:
		compiler();
		void inject_c_std_lib(module & m);
		static parlex::details::abstract_syntax_graph parse(std::u32string const & source);
	private:
		source_code c_std_lib_source;
	};
}

#endif //PLC_UTILS_HPP
