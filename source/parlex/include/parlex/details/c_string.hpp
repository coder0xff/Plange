#ifndef C_STRING_HPP
#define C_STRING_HPP

#include "parlex/details/abstract_syntax_semilattice.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/details/raw_state_machine.hpp"
#include "parlex/details/terminal.hpp"

namespace parlex {
namespace details {

class builtins_t;

class c_string_t : public raw_state_machine {
public:
	void extract_step(std::u32string const & document, std::u32string * result, recognizer const * r, size_t document_position, size_t consumed_character_count) const;
	std::u32string extract(std::u32string const & document, ast_node const & n) const;
	std::u32string extract(std::u32string const & document, match const & m, abstract_syntax_semilattice const & asg) const;

private:
	friend class builtins_t;
	c_string_t(builtins_t const &);

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

	raw_state_machine octal_escape_sequence;
	raw_state_machine hex_escape_sequence;

};

}

}

#endif // C_STRING_HPP
