#include "parlex/details/c_string.hpp"

#include "parlex/terminal.hpp"
#include "parlex/builtins.hpp"
#include "utils.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/abstract_syntax_graph.hpp"

namespace parlex {
namespace details {
	
c_string_t::c_string_t(filter_function const & longest, terminal const & octal_digit, terminal const & hexadecimal_digit) :
	state_machine("c_string", 0, 1, longest, none),
	backslash(to_utf32("\\")),
	double_quote(to_utf32("\"")),
	x(to_utf32("x")),
	octal_escape_sequence("octal_escape_sequence", 0, 3, longest),
	hex_escape_sequence("hex_escape_sequence", 0, 1, longest) {

	octal_escape_sequence.add_transition(0, backslash, 1);
	octal_escape_sequence.add_transition(1, octal_digit, 2);
	octal_escape_sequence.add_transition(2, octal_digit, 3);
	octal_escape_sequence.add_transition(3, octal_digit, 4);

	hex_escape_sequence.add_transition(0, backslash, 1);
	hex_escape_sequence.add_transition(1, x, 2);
	hex_escape_sequence.add_transition(2, hexadecimal_digit, 3);
	hex_escape_sequence.add_transition(3, hexadecimal_digit, 3);

	add_transition(0, double_quote, 1);
	add_transition(1, content, 1);
	add_transition(1, basic_escape_sequence, 1);
	add_transition(1, octal_escape_sequence, 1);
	add_transition(1, hex_escape_sequence, 1);
	add_transition(1, double_quote, 2);
}


std::u32string c_string_t::extract(std::u32string document, match const & m, abstract_syntax_graph const & asg) const {
	auto const & asgTableIterator = asg.permutations.find(m);
	throw_assert(asgTableIterator != asg.permutations.end());
	std::set<permutation> const & permutations = asgTableIterator->second;
	throw_assert(permutations.size() != 0);
	permutation const & p = *permutations.begin();
	std::u32string result;
	result.reserve(p.size());
	auto i = p.begin();
	++i;
	auto end = p.end();
	--end;
	for (; i != end; ++i) {
		if (&i->r == &content) {
			result.append(1, document[i->document_position]);
		}
		else if (&i->r == &basic_escape_sequence) {
			char32_t const c = document[i->document_position + 1];
			switch (c) {
			case '"':
			case '\'':
			case '?':
			case '\\':
				result.append(1, c);
				break;
			case 97:
				result.append(1, static_cast<char32_t>(7));
				break;
			case 98:
				result.append(1, static_cast<char32_t>(8));
				break;
			case 102:
				result.append(1, static_cast<char32_t>(12));
				break;
			case 110:
				result.append(1, static_cast<char32_t>(10));
				break;
			case 114:
				result.append(1, static_cast<char32_t>(13));
				break;
			case 116:
				result.append(1, static_cast<char32_t>(9));
				break;
			case 118:
				result.append(1, static_cast<char32_t>(11));
				break;
			}
		}
		else if (&i->r == &octal_escape_sequence) {
			char32_t c = 0;
			for (int j = 1; j < i->consumed_character_count; ++j) {
				c = c << 3;
				c += document[i->document_position + j] - '0';
			}
			result.append(1, c);
		}
		else if (&i->r == &hex_escape_sequence) {
			char32_t c = 0;
			for (int j = 1; j < i->consumed_character_count; ++j) {
				c = c << 4;
				char32_t const d = document[i->document_position + j];
				c += d < 'A' ? d - '0' : (d < 'a' ? d - 'A' : d - 'a'); //48 = '0'
			}
			result.append(1, c);
		}
	}
	return result;
}


c_string_t::content_t::content_t() : terminal("content", 1) {
}


bool c_string_t::content_t::test(std::u32string const & document, size_t documentPosition) const {
	return document[documentPosition] != 34 && document[documentPosition] != 92;
}


c_string_t::basic_escape_sequence_t::basic_escape_sequence_t() : terminal("basic_escape_sequence", 2) {

}

bool c_string_t::basic_escape_sequence_t::test(std::u32string const & document, size_t documentPosition) const {
	if (documentPosition + 1 >= document.length()) return false;
	auto const c = document[documentPosition + 1];
	return document[documentPosition] == 92 && (c == 34 || c == 39 || c == 63 || c == 92 || c == 97 || c == 98 || c == 102 || c == 110 || c == 114 || c == 116 || c == 118);
}

} //namespace details
} //namespace parlex

