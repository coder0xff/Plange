#ifndef BUILTINS_HPP
#define BUILTINS_HPP

// Terminals
#include "parlex/details/any_character.hpp"
#include "parlex/details/unicode.hpp"
#include "parlex/details/not_double_quote.hpp"
#include "parlex/details/not_newline.hpp"

// Misc
#include "parlex/details/c_string.hpp"

namespace parlex {

class parser;
class builtins_t;

// get singleton
builtins_t const& builtins();

class builtins_t {

public:
	builtins_t(builtins_t const & copy) = delete;
	static void progress_bar(int done, int outOf);

	filter_function longest;

	details::any_character_t const any_character;
	details::not_double_quote_t const not_double_quote;
	details::not_newline_t const not_newline;

	details::all_t const all;
	details::alphanumeric_t const alphanumeric;
	details::close_punctuation_t const close_punctuation;
	details::connector_punctuation_t const connector_punctuation;
	details::control_t const control;
	details::currency_symbol_t const currency_symbol;
	details::dash_punctuation_t const dash_punctuation;
	details::decimal_digit_t const decimal_digit;
	details::enclosing_mark_t const enclosing_mark;
	details::final_quote_punctuation_t const final_quote_punctuation;
	details::format_t const format;
	details::hexadecimal_digit_t const hexadecimal_digit;
	details::initial_quote_punctuation_t const initial_quote_punctuation;
	details::latin_digit_t const latin_digit;
	details::letter_number_t const letter_number;
	details::letter_t const letter;
	details::line_separator_t const line_separator;
	details::lowercase_letter_t const lowercase_letter;
	details::math_symbol_t const math_symbol;
	details::modifier_letter_t const modifier_letter;
	details::modifier_symbol_t const modifier_symbol;
	details::nonspacing_mark_t const nonspacing_mark;
	details::number_t const number;
	details::octal_digit_t const octal_digit;
	details::open_punctuation_t const open_punctuation;
	details::other_letter_t const other_letter;
	details::other_number_t const other_number;
	details::other_punctuation_t const other_punctuation;
	details::other_symbol_t const other_symbol;
	details::paragraph_separator_t const paragraph_separator;
	details::printable_t const printable;
	details::public_use_t const public_use;
	details::space_separator_t const space_separator;
	details::spacing_combining_mark_t const spacing_combining_mark;
	details::surrogate_t const surrogate;
	details::titlecase_letter_t const titlecase_letter;
	details::uppercase_letter_t const uppercase_letter;
	details::white_space_t const white_space;
	details::white_space_control_t const white_space_control;

	details::c_string_t const c_string;

	std::map<std::string, recognizer const *> const recognizer_table;

	bool resolve_builtin(std::string const & name, recognizer const *& ptr) const;

private:
	friend builtins_t const& builtins();
	builtins_t();
	std::map<std::string, recognizer const *> generate_lookup_table() const;

	// satisfies filter_function
	static std::set<int> longest_f(std::u32string document, std::list<permutation> const & permutations);
};


} // namespace parlex

#endif //BUILTINS_HPP
