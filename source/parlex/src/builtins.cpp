#include <iostream>
#include <mutex>

#include "parlex/detail/builtins.hpp"

#include "utf.hpp"

namespace parlex {
namespace detail {

any_character_t::any_character_t() : terminal("any_character", 1) {
}

bool any_character_t::test(std::u32string const & document, size_t documentPosition) const {
	return true;
}

not_double_quote_t::not_double_quote_t() : terminal("not_double_quote", 1) {
}

bool not_double_quote_t::test(std::u32string const & document, size_t documentPosition) const {
	return document[documentPosition] == U'"';
}

not_newline_t::not_newline_t() : terminal("not_newline", 1) {
}

bool not_newline_t::test(std::u32string const & document, size_t documentPosition) const {
	return document[documentPosition] != U'\n';
}

std::set<int> builtins_t::longest_f(std::u32string document, std::list<permutation> const & permutations) {
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
}

builtins_t const& builtins() {
	static builtins_t value;
	return value;
}

bool builtins_t::resolve_builtin(std::string const & name, recognizer const *& ptr) const {
	auto i = recognizer_table.find(name);
	if (i == recognizer_table.end()) {
		return false;
	}
	ptr = i->second;
	return true;
}

std::map<std::string, recognizer const *> builtins_t::generate_lookup_table() const {
	std::map<std::string, recognizer const *> result;
	recognizer const * table_initializer[] = {
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

	unsigned int count = sizeof table_initializer / sizeof *table_initializer;
	for (unsigned int i = 0; i < count; ++i) {
		recognizer const * item = table_initializer[i];
		std::string const name = item->id;
		result[name] = item;
	}

	return result;
}


builtins_t::builtins_t() : longest(new std::function<std::set<int>(std::u32string const & /*document*/, std::list<permutation> const &)>(longest_f)), c_string(*this), recognizer_table(generate_lookup_table()) {

}

void builtins_t::progress_bar(int done, int outOf) {
	static std::mutex m;
	std::unique_lock<std::mutex> lock(m);
	int ticks = done * 25 / outOf;
	std::cout << "\r[" << std::string(ticks, '*') << std::string(25 - ticks, ' ') << "]";
}

string_terminal::string_terminal(std::u32string const & s) : terminal(to_utf8(s), s.length()), s(s) {
}

bool string_terminal::test(std::u32string const & document, size_t documentPosition) const {
	return document.compare(documentPosition, length, s) == 0;
}

std::u32string string_terminal::get_content() const {
	return s;
}


} //namespace detail
} // namespace parlex
