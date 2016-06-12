#include <sstream>
#include <iostream>
#include <mutex>

#include "parlex/builtins.hpp"
#include "utils.hpp"

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

bool not_double_quote_t::test(std::u32string const & document, size_t documentPosition) const {
	return documentPosition < document.length() && document[documentPosition] == U'"';
}

size_t not_double_quote_t::get_length() const {
	return 1;
}

std::string not_double_quote_t::get_id() const {
	return "not_double_quote";
}

bool not_newline_t::test(std::u32string const & document, size_t documentPosition) const {
	return documentPosition < document.length() && document[documentPosition] != U'\n';
}

size_t not_newline_t::get_length() const {
	return 1;
}

std::string not_newline_t::get_id() const {
	return "not_newline";
}

} //namespace details

namespace builtins {

void progress_bar(int done, int outOf) {
	static std::mutex m;
	std::unique_lock<std::mutex> lock(m);
	int ticks = done * 25 / outOf;
	std::cout << "\r[" << std::string(ticks, '*') << std::string(25 - ticks, ' ') << "]";
};

parlex::details::any_character_t any_character;
parlex::details::not_double_quote_t not_double_quote;
parlex::details::not_newline_t not_newline;

string_terminal::string_terminal(std::u32string const & s) : s(s), length(s.length()), id(to_utf8(s)) {}

bool string_terminal::test(std::u32string const & document, size_t const documentPosition) const {
	return document.compare(documentPosition, length, s) == 0;
}

size_t string_terminal::get_length() const {
	return length;
}

std::string string_terminal::get_id() const {
	return id;
}

std::u32string string_terminal::get_content() const {
	return s;
}

filter_function greedy = [] (std::list<permutation> const & permutations) {
	int selectedSize = 0;
	for (permutation const & p : permutations) {
		int len = p.size() > 0 ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len > selectedSize) {
			selectedSize = len;
		}
	}
	std::set<int> result;
	int counter = 0;
	for (permutation const & p : permutations) {
		int len = p.size() > 0 ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len == selectedSize) {
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

std::map<std::string, recognizer *> const & get_builtins_table() {
	static std::map<std::string, recognizer *> result;
	if (result.size() == 0) {
		recognizer * table_initializer[] = {
			&all,
			&any_character,
			&alphanumeric,
			&c_string,
			&close_punctuation,
			&connector_punctuation,
			&control,
			&currency_symbol,
			&dash_punctuation,
			&decimal_digit,
			&enclosing_mark,
			&final_quote_punctuation,
			&format,
			&octal_digit,
			&hexadecimal_digit,
			&initial_quote_punctuation,
			&latin_digit,
			&letter_number,
			&letter,
			&line_separator,
			&lowercase_letter,
			&not_double_quote,
			&not_newline,
			&math_symbol,
			&modifier_letter,
			&modifier_symbol,
			&nonspacing_mark,
			&number,
			&open_punctuation,
			&other_letter,
			&other_number,
			&other_punctuation,
			&other_symbol,
			&paragraph_separator,
			&printable,
			&public_use,
			&space_separator,
			&spacing_combining_mark,
			&surrogate,
			&titlecase_letter,
			&uppercase_letter,
			&white_space,
			&white_space_control
		};

		unsigned int count = sizeof(table_initializer) / sizeof(*table_initializer);
		for (unsigned int i = 0; i < count; ++i) {
			recognizer * item = table_initializer[i];
			std::string const name = item->get_id();
			result[name] = item;
		}
	}
	return result;
}

bool resolve_builtin(std::string const & name, parlex::recognizer const *& ptr)
{
	static std::map<std::string, recognizer *> builtins_table = get_builtins_table();
	auto i = builtins_table.find(name);
	if (i == builtins_table.end()) {
		return false;
	}
	else {
		ptr = i->second;
		return true;
	}
}

} //namespace builtins
}

