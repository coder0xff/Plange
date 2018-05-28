#include "parlex/detail/c_string.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/abstract_syntax_semilattice.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/grammar.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

c_string_t const & c_string() {
	static c_string_t result;
	return result;
}

c_string_t::c_string_t() : sub_builder({
	production("c_string", sequence {
		literal(U"\""),
		repetition(
			choice{
				reference("content"),
				reference("basic_escape_sequence"),
				reference("octal_escape_sequence"),
				reference("hex_escape_sequence")
			}
		),
		literal(U"\"")
	}),
	production("octal_escape_sequence", sequence {
		literal(U"\\"),
		reference("octal_digit"),
		reference("octal_digit"),
		reference("octal_digit")
	}),
	production("hex_escape_sequence", sequence {
		literal(U"\\x"),
		reference("hexadecimal_digit"),
		repetition(reference("hexadecimal_digit"))
	}, associativity::NONE, longest())
})
{}

void c_string_t::extract_step(std::u32string const & document, std::u32string * result, grammar const & g, size_t const recognizerIndex, size_t const documentPosition, size_t const consumedCharacterCount) {
	if (recognizerIndex == g.lookup_recognizer_index("content")) {
		result->append(1, document[documentPosition]);
	} else if (recognizerIndex == g.lookup_recognizer_index("basic_escape_sequence")) {
		auto const c = document[documentPosition + 1];
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
	} else if (recognizerIndex == g.lookup_recognizer_index("octal_escape_sequence")) {
		char32_t c = 0;
		for (size_t j = 1; j < consumedCharacterCount; ++j) {
			c = c << 3;
			c += document[documentPosition + j] - '0';
		}
		result->append(1, c);
	} else if (recognizerIndex == g.lookup_recognizer_index("hex_escape_sequence")) {
		char32_t c = 0;
		for (size_t j = 1; j < consumedCharacterCount; ++j) {
			c = c << 4;
			auto const d = document[documentPosition + j];
			c += d < 'A' ? d - '0' : (d < 'a' ? d - 'A' : d - 'a'); //48 = '0'
		}
		result->append(1, c);
	}
}

std::u32string c_string_t::extract(grammar const & g, std::u32string const & document, ast_node const & n) {
	throw_assert(n.recognizer_index == g.lookup_recognizer_index("c_string"));
	std::u32string result;
	result.reserve(n.children.size());
	auto i = n.children.begin();
	++i; //advance past opening double quote
	auto end = n.children.end();
	--end; //most to closing double quote
	for (; i != end; ++i) {
		extract_step(document, &result, g, i->l->recognizer_index, i->document_position, i->consumed_character_count);
	}
	return result;
}

std::u32string c_string_t::extract(grammar const & g, std::u32string const & document, match const & m, abstract_syntax_semilattice const & asg) {
	throw_assert(m.recognizer_index == g.lookup_recognizer_index("c_string"));
	auto const & asgTableIterator = asg.derivations_of_matches.find(m);
	throw_assert(asgTableIterator != asg.derivations_of_matches.end());
	auto const & derivations = asgTableIterator->second;
	throw_assert(!derivations.empty());
	auto const & p = *derivations.begin();
	std::u32string result;
	result.reserve(p.size());
	auto i = p.begin();
	++i;
	auto end = p.end();
	--end;
	for (; i != end; ++i) {
		extract_step(document, &result, g, i->recognizer_index, i->document_position, i->consumed_character_count);
	}
	return result;
}

} //namespace detail
} //namespace parlex
