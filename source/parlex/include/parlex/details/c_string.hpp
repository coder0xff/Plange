#ifndef C_STRING_HPP
#define C_STRING_HPP

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
class builtins_t;

namespace details {

class c_string_t : public state_machine {
public:
	c_string_t(builtins_t const & builtins);
	std::u32string extract(std::u32string document, match const & m, abstract_syntax_graph const & asg) const;

private:
	class content_t : public terminal {
	public:
		content_t();
		bool test(std::u32string const & document, size_t documentPosition) const override final;
	} content;

	class basic_escape_sequence_t : public terminal {
	public:
		basic_escape_sequence_t();
		bool test(std::u32string const & document, size_t documentPosition) const override final;

	} basic_escape_sequence;

	string_terminal backslash;
	string_terminal double_quote;
	string_terminal x;

	state_machine octal_escape_sequence;
	state_machine hex_escape_sequence;

};

}

}

#endif // C_STRING_HPP
