#include <sstream>

#include "parlex/builtins.hpp"
#include "parlex/details/unicode.hpp"

namespace parlex {
namespace details {

bool any_character_t::test(std::u32string const & document, size_t documentPosition) const {
	return documentPosition < document.length();
}

size_t any_character_t::get_length() const {
	return 1;
}

std::string any_character_t::get_id() const {
	return "any_character";
}

}

namespace builtins {

parlex::details::any_character_t any_character;

string_terminal::string_terminal(std::u32string const & s) : s(s), length(s.length()), id(uni_trunc(s)) {}

bool string_terminal::test(std::u32string const & document, size_t const documentPosition) const {
	return document.compare(documentPosition, length, s) == 0;
}

size_t string_terminal::get_length() const {
	return length;
}

std::string string_terminal::get_id() const {
	return id;
}

filter_function greedy = [] (std::vector<permutation> const & permutations) {
	int selectedSize = 0;
	for (permutation const & p : permutations) {
		int size = p.back().documentPosition + p.back().consumed_character_count - p.front().documentPosition;
		if (size > selectedSize) {
			selectedSize = size;
		}
	}
	std::set<int> result;
	int counter = 0;
	for (permutation const & p : permutations) {
		int size = p.back().documentPosition + p.back().consumed_character_count - p.front().documentPosition;
		if (size == selectedSize) {
			result.insert(counter);
		}
		counter++;
	}
	return result;
};

details::all_t all;
details::alphanumeric_t alphanumeric;
details::close_punctuation_t close_punctuation;
details::connector_punctuation_t connector_punctuation;
details::control_t control;
details::currency_symbol_t currency_symbol;
details::dash_punctuation_t dash_punctuation;
details::decimal_digit_t decimal_digit;
details::enclosing_mark_t enclosing_mark;
details::final_quote_punctuation_t final_quote_punctuation;
details::format_t format;
details::hexadecimal_digit_t hexadecimal_digit;
details::initial_quote_punctuation_t initial_quote_punctuation;
details::latin_digit_t latin_digit;
details::letter_number_t letter_number;
details::letter_t letter;
details::line_separator_t line_separator;
details::lowercase_letter_t lowercase_letter;
details::math_symbol_t math_symbol;
details::modifier_letter_t modifier_letter;
details::modifier_symbol_t modifier_symbol;
details::nonspacing_mark_t nonspacing_mark;
details::number_t number;
details::open_punctuation_t open_punctuation;
details::other_letter_t other_letter;
details::other_number_t other_number;
details::other_punctuation_t other_punctuation;
details::other_symbol_t other_symbol;
details::paragraph_separator_t paragraph_separator;
details::printable_t printable;
details::public_use_t public_use;
details::space_separator_t space_separator;
details::spacing_combining_mark_t spacing_combining_mark;
details::surrogate_t surrogate;
details::titlecase_letter_t titlecase_letter;
details::uppercase_letter_t uppercase_letter;
details::white_space_t white_space;
details::white_space_control_t white_space_control;

}
}