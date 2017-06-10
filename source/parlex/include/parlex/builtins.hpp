#ifndef BUILTINS_HPP
#define BUILTINS_HPP

// Terminals
#include "parlex/details/any_character.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/details/unicode.hpp"
#include "parlex/details/not_double_quote.hpp"
#include "parlex/details/not_newline.hpp"
#include "parlex/details/wirth.hpp"

// Misc
#include "parlex/details/c_string.hpp"

namespace parlex {

class parser;

class builtins_t {

public:
	using string_terminal = details::string_terminal;

	builtins_t(parser const & p);
	static void progress_bar(int done, int outOf);

	filter_function longest;

	details::any_character_t any_character;
	details::not_double_quote_t not_double_quote;
	details::not_newline_t not_newline;

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
	details::octal_digit_t octal_digit;
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

	details::c_string_t c_string;

	std::map<std::string, recognizer const *> const recognizer_table;

	details::wirth_t wirth;

	bool resolve_builtin(std::string const & name, recognizer const *& ptr) const;

private:
	std::map<std::string, recognizer const *> generate_lookup_table() const;

	// satisfies filter_function
	static std::set<int> longest_f(std::u32string document, std::list<permutation> const & permutations);
};

}

#endif
