#include "parlex/details/c_string.hpp"

#include "parlex/details/abstract_syntax_semilattice.hpp"
#include "parlex/details/builtins.hpp"

#include "parlex/details/terminal.hpp"

#include "utils.hpp"
#include "utf.hpp"
#include "parlex/details/behavior.hpp"

namespace parlex {
namespace details {

c_string_t::c_string_t(builtins_t const & builtins) :
	raw_state_machine("c_string", 0, 1, builtins.longest, associativity::none),
	backslash(to_utf32("\\")),
	double_quote(to_utf32("\"")),
	x(to_utf32("x")),
	octal_escape_sequence("octal_escape_sequence", 0, 3, builtins.longest),
	hex_escape_sequence("hex_escape_sequence", 0, 1, builtins.longest) {

	octal_escape_sequence.add_transition(0, &backslash, 1);
	octal_escape_sequence.add_transition(1, &builtins.octal_digit, 2);
	octal_escape_sequence.add_transition(2, &builtins.octal_digit, 3);
	octal_escape_sequence.add_transition(3, &builtins.octal_digit, 4);

	hex_escape_sequence.add_transition(0, &backslash, 1);
	hex_escape_sequence.add_transition(1, &x, 2);
	hex_escape_sequence.add_transition(2, &builtins.hexadecimal_digit, 3);
	hex_escape_sequence.add_transition(3, &builtins.hexadecimal_digit, 3);

	add_transition(0, &double_quote, 1);
	add_transition(1, &content, 1);
	add_transition(1, &basic_escape_sequence, 1);
	add_transition(1, &octal_escape_sequence, 1);
	add_transition(1, &hex_escape_sequence, 1);
	add_transition(1, &double_quote, 2);
}

void c_string_t::extract_step(std::u32string const & document, std::u32string * result, recognizer const * r, size_t document_position, size_t consumed_character_count) const {
	if (r == &content) {
		result->append(1, document[document_position]);
	} else if (r == &basic_escape_sequence) {
		char32_t const c = document[document_position + 1];
		switch (c) {
		case '"':
		case '\'':
		case '?':
		case '\\':
			result->append(1, c);
			break;
		case 'a':
			result->append(1, static_cast<char32_t>(7));
			break;
		case 'b':
			result->append(1, static_cast<char32_t>(8));
			break;
		case 'f':
			result->append(1, static_cast<char32_t>(12));
			break;
		case 'n':
			result->append(1, static_cast<char32_t>(10));
			break;
		case 'r':
			result->append(1, static_cast<char32_t>(13));
			break;
		case 't':
			result->append(1, static_cast<char32_t>(9));
			break;
		case 'v':
			result->append(1, static_cast<char32_t>(11));
			break;
		default: 
			throw;
		}
	} else if (r == &octal_escape_sequence) {
		char32_t c = 0;
		for (size_t j = 1; j < consumed_character_count; ++j) {
			c = c << 3;
			c += document[document_position + j] - '0';
		}
		result->append(1, c);
	} else if (r == &hex_escape_sequence) {
		char32_t c = 0;
		for (size_t j = 1; j < consumed_character_count; ++j) {
			c = c << 4;
			char32_t const d = document[document_position + j];
			c += d < 'A' ? d - '0' : (d < 'a' ? d - 'A' : d - 'a'); //48 = '0'
		}
		result->append(1, c);
	}
}

std::u32string c_string_t::extract(std::u32string const & document, ast_node const & n) const {
	throw_assert(&n.r == this);
	std::u32string result;
	result.reserve(n.children.size());
	auto i = n.children.begin();
	++i; //advance past opening double quote
	auto end = n.children.end();
	--end; //most to closing double quote
	for (; i != end; ++i) {
		extract_step(document, &result, &i->r, i->document_position, i->consumed_character_count);
	}
	return result;
}

std::u32string c_string_t::extract(std::u32string const & document, match const & m, abstract_syntax_semilattice const & asg) const {
	throw_assert(&m.r == this);
	auto const & asgTableIterator = asg.permutations_of_matches.find(m);
	throw_assert(asgTableIterator != asg.permutations_of_matches.end());
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
		extract_step(document, &result, &i->r, i->document_position, i->consumed_character_count);
	}
	return result;
}


c_string_t::content_t::content_t() : terminal("content", 1) {
}

bool c_string_t::content_t::test(std::u32string const & document, size_t documentPosition) const {
	return document[documentPosition] != '\"' && document[documentPosition] != '\\';
}

c_string_t::basic_escape_sequence_t::basic_escape_sequence_t() : terminal("basic_escape_sequence", 2) {

}

bool c_string_t::basic_escape_sequence_t::test(std::u32string const & document, size_t documentPosition) const {
	if (documentPosition + 1 >= document.length()) return false;
	auto const c = document[documentPosition + 1];
	return document[documentPosition] == '\\' && (c == '\"' || c == '\'' || c == '?' || c == '\\' || c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v');
}

} //namespace details
} //namespace parlex
