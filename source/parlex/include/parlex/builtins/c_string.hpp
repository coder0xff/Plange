#ifndef C_STRING_HPP
#define C_STRING_HPP

#include "parlex/state_machine.hpp"
#include "parlex/abstract_syntax_graph.hpp"

namespace parlex {
namespace builtins {

class c_string_t : public state_machine {
public:
	c_string_t();
	static std::u32string extract(std::u32string document, match const & m, parlex::abstract_syntax_graph const & asg);

};

extern c_string_t c_string;

}
}

#endif // C_STRING_HPP
