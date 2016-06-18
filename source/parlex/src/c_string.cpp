#include <cassert>
#include <sstream>

#include "parlex/terminal.hpp"
#include "parlex/builtins.hpp"
#include "utils.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/builtins.hpp"
#include "parlex/abstract_syntax_graph.hpp"

namespace parlex {
namespace builtins {

c_string_t c_string;

}
}

namespace  {

class content_t : public parlex::terminal {
    virtual bool test(std::u32string const & document, size_t documentPosition) const final {
        if (documentPosition >= document.length()) return false;
        return document[documentPosition] != 34 && document[documentPosition] != 92;
    }
    virtual size_t get_length() const final { return 1; }
    virtual std::string get_id() const final { return "content"; }
} content;

class basic_escape_sequence_t : public parlex::terminal {
    virtual bool test(std::u32string const & document, size_t documentPosition) const final {
        if (documentPosition + 1 >= document.length()) return false;
        char32_t const c = document[documentPosition + 1];
        return document[documentPosition] == 92 && (c == 34 || c == 39 || c == 63 || c == 92 || c == 97 || c == 98 || c == 102 || c == 110 || c == 114 || c == 116 || c == 118);
    }
    virtual size_t get_length() const final { return 2; }
    virtual std::string get_id() const final { return "basic_escape_sequence"; }
} basic_escape_sequence;

parlex::builtins::string_terminal backslash(to_utf32("\\"));
parlex::builtins::string_terminal double_quote(to_utf32("\""));
parlex::builtins::string_terminal x(to_utf32("x"));

parlex::state_machine octal_escape_sequence("octal_escape_sequence", 0, 3, parlex::builtins::greedy);
parlex::state_machine hex_escape_sequence("hex_escape_sequence", 0, 1, parlex::builtins::greedy);

int build() {
    octal_escape_sequence.add_transition(0, backslash, 1);
    octal_escape_sequence.add_transition(1, parlex::builtins::octal_digit, 2);
    octal_escape_sequence.add_transition(2, parlex::builtins::octal_digit, 3);
    octal_escape_sequence.add_transition(3, parlex::builtins::octal_digit, 4);

    hex_escape_sequence.add_transition(0, backslash, 1);
	hex_escape_sequence.add_transition(1, x, 2);
    hex_escape_sequence.add_transition(2, parlex::builtins::hexadecimal_digit, 3);
    hex_escape_sequence.add_transition(3, parlex::builtins::hexadecimal_digit, 3);

    parlex::builtins::c_string.add_transition(0, double_quote, 1);
    parlex::builtins::c_string.add_transition(1, content, 1);
    parlex::builtins::c_string.add_transition(1, basic_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, octal_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, hex_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, double_quote, 2);

    return 0;
}

int dont_care = build();
}

namespace parlex {
	namespace builtins {

		c_string_t::c_string_t() : state_machine("c_string", 0, 1, parlex::builtins::greedy) { }

		std::u32string c_string_t::extract(std::u32string document, match const & m, abstract_syntax_graph const & asg)
		{
			auto const & asgTableIterator = asg.permutations.find(m);
			assert(asgTableIterator != asg.permutations.end());
			std::set<permutation> const & permutations = asgTableIterator->second;
			assert(permutations.size() != 0);
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
				} else if (&i->r == &basic_escape_sequence) {
					char32_t const c = document[i->document_position + 1];
					switch (c) {
					case '"':
					case '\'':
					case '?':
					case '\\':
						result.append(1, c);
						break;
					case 97:
						result.append(1, (char32_t)7);
						break;
					case 98:
						result.append(1, (char32_t)8);
						break;
					case 102:
						result.append(1, (char32_t)12);
						break;
					case 110:
						result.append(1, (char32_t)10);
						break;
					case 114:
						result.append(1, (char32_t)13);
						break;
					case 116:
						result.append(1, (char32_t)9);
						break;
					case 118:
						result.append(1, (char32_t)11);
						break;
					}
				} else if (&i->r == &octal_escape_sequence) {
					char32_t c = 0;
					for (int j = 1; j < i->consumed_character_count; ++j) {
						c = c << 3;
						c += document[i->document_position + j] - '0';
					}
					result.append(1, c);
				} else if (&i->r == &hex_escape_sequence) {
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

	}
}

