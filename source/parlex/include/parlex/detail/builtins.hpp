#ifndef BUILTINS_HPP
#define BUILTINS_HPP

#include "parlex/filter_function.hpp"

// Terminals
#include "parlex/detail/any_character.hpp"
#include "parlex/detail/unicode.hpp"
#include "parlex/detail/not_double_quote.hpp"
#include "parlex/detail/not_newline.hpp"

// Misc
#include "parlex/detail/c_string.hpp"

namespace parlex {
namespace detail {

class parser;
class builtins_t;

// get singleton
builtins_t const& builtins();

class builtins_t {

public:
	builtins_t(builtins_t const & copy) = delete;
	static void progress_bar(int done, int outOf);

	filter_function longest;

	any_character_t const any_character;
	not_double_quote_t const not_double_quote;
	not_newline_t const not_newline;

	all_t const all;
	alphanumeric_t const alphanumeric;
	close_punctuation_t const close_punctuation;
	connector_punctuation_t const connector_punctuation;
	control_t const control;
	currency_symbol_t const currency_symbol;
	dash_punctuation_t const dash_punctuation;
	decimal_digit_t const decimal_digit;
	enclosing_mark_t const enclosing_mark;
	final_quote_punctuation_t const final_quote_punctuation;
	format_t const format;
	hexadecimal_digit_t const hexadecimal_digit;
	initial_quote_punctuation_t const initial_quote_punctuation;
	latin_digit_t const latin_digit;
	letter_number_t const letter_number;
	letter_t const letter;
	line_separator_t const line_separator;
	lowercase_letter_t const lowercase_letter;
	math_symbol_t const math_symbol;
	modifier_letter_t const modifier_letter;
	modifier_symbol_t const modifier_symbol;
	nonspacing_mark_t const nonspacing_mark;
	number_t const number;
	octal_digit_t const octal_digit;
	open_punctuation_t const open_punctuation;
	other_letter_t const other_letter;
	other_number_t const other_number;
	other_punctuation_t const other_punctuation;
	other_symbol_t const other_symbol;
	paragraph_separator_t const paragraph_separator;
	printable_t const printable;
	public_use_t const public_use;
	space_separator_t const space_separator;
	spacing_combining_mark_t const spacing_combining_mark;
	surrogate_t const surrogate;
	titlecase_letter_t const titlecase_letter;
	uppercase_letter_t const uppercase_letter;
	white_space_t const white_space;
	white_space_control_t const white_space_control;

	c_string_t const c_string;

	std::map<std::string, recognizer const *> const recognizer_table;

	bool resolve_builtin(std::string const & name, recognizer const *& ptr) const;

private:
	friend builtins_t const& builtins();
	builtins_t();
	std::map<std::string, recognizer const *> generate_lookup_table() const;

	// satisfies filter_function
	static std::set<int> longest_f(std::u32string document, std::list<permutation> const & permutations);
};


} // namespace detail
} // namespace parlex

#endif //BUILTINS_HPP
