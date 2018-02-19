#ifndef BUILTINS_HPP
#define BUILTINS_HPP

#include "parlex/builder.hpp"
#include "parlex/filter_function.hpp"

// Terminals
#include "parlex/detail/any_character.hpp"
#include "parlex/detail/basic_escape_sequence.hpp"
#include "parlex/detail/content.hpp"
#include "parlex/detail/not_double_quote.hpp"
#include "parlex/detail/not_newline.hpp"
#include "parlex/detail/unicode.hpp"

// Misc

namespace parlex {

// filter out all but the longest matches
filter_function const & longest();
// filter out all but the shortest matches
filter_function const & shortest();

// when passed to parser::parse as a progress handler, prints a text-based 
void progress_bar(int done, int outOf);

namespace detail {

class parser;
class builtin_terminals_t;

// get singleton
builtin_terminals_t const& builtin_terminals();

class builtin_terminals_t {

public:
	builtin_terminals_t(builtin_terminals_t const & copy) = delete;
	any_character_t const any_character;
	basic_escape_sequence_t basic_escape_sequence;
	content_t content;
	not_double_quote_t const not_double_quote;
	not_newline_t const not_newline;

	// Unicode categories
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

	std::map<std::string, recognizer const *> const recognizer_table;

	bool resolve_builtin_terminal(std::string const & name, terminal const * & ptr) const;

private:
	friend builtin_terminals_t const& builtin_terminals();
	builtin_terminals_t();
	std::map<std::string, recognizer const *> generate_lookup_table() const;

};

} // namespace detail
} // namespace parlex

#endif //BUILTINS_HPP
