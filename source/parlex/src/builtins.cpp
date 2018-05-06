#include <iostream>
#include <mutex>

#include "parlex/detail/builtins.hpp"

#include "utf.hpp"
#include "parlex/detail/string_terminal.hpp"

namespace parlex {

void progress_bar(uint32_t const done, uint32_t const outOf) {
	static std::mutex m;
	std::unique_lock<std::mutex> lock(m);
	auto const ticks = done * 25 / outOf;
	std::cout << "\r[" << std::string(ticks, '*') << std::string(25 - ticks, ' ') << "]";
}

static std::set<int> longest_f(std::u32string const & /*document*/, std::list<detail::derivation> const & derivations) {
	auto selectedSize = 0;
	for (auto const & p : derivations) {
		int const len = !p.empty() ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len > selectedSize) {
			selectedSize = len;
		}
	}
	std::set<int> result;
	auto counter = 0;
	for (auto const & p : derivations) {
		int const len = !p.empty() ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len == selectedSize) {
			result.insert(counter);
		}
		counter++;
	}
	return result;
}

filter_function const & longest() {
	static filter_function result(new std::function<std::set<int>(std::u32string const & /*document*/, std::list<detail::derivation> const &)>(longest_f));
	return result;
}

static std::set<int> shortest_f(std::u32string const & /*document*/, std::list<detail::derivation> const & derivations) {
	auto selectedSize = INTMAX_MAX;
	for (auto const & p : derivations) {
		int const len = !p.empty() ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len < selectedSize) {
			selectedSize = len;
		}
	}
	std::set<int> result;
	auto counter = 0;
	for (auto const & p : derivations) {
		int const len = !p.empty() ? p.back().document_position + p.back().consumed_character_count - p.front().document_position : 0;
		if (len == selectedSize) {
			result.insert(counter);
		}
		counter++;
	}
	return result;
}

filter_function const & shortest() {
	static filter_function result(new std::function<std::set<int>(std::u32string const & /*document*/, std::list<detail::derivation> const &)>(shortest_f));
	return result;
}

namespace detail {

any_character_t::any_character_t() : terminal("any_character", 1) {}

bool any_character_t::test(std::u32string const & document, uint32_t const documentPosition) const {
	return true;
}

basic_escape_sequence_t::basic_escape_sequence_t() : terminal ("basic_escape_sequence", 2) {}

bool basic_escape_sequence_t::test(std::u32string const & document, uint32_t const documentPosition) const {
	if (documentPosition + 1 >= document.length()) return false;
	auto const c = document[documentPosition + 1];
	return document[documentPosition] == '\\' && (c == '\"' || c == '\'' || c == '?' || c == '\\' || c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v');
}

content_t::content_t() : terminal("content", 1) {
}

bool content_t::test(std::u32string const & document, uint32_t const documentPosition) const {
	return document[documentPosition] != '\"' && document[documentPosition] != '\\';
}

not_double_quote_t::not_double_quote_t() : terminal("not_double_quote", 1) {
}

bool not_double_quote_t::test(std::u32string const & document, uint32_t const documentPosition) const {
	return document[documentPosition] == U'"';
}

not_newline_t::not_newline_t() : terminal("not_newline", 1) {
}

bool not_newline_t::test(std::u32string const & document, uint32_t const documentPosition) const {
	return document[documentPosition] != U'\n';
}

builtin_terminals_t const& builtin_terminals() {
	static builtin_terminals_t value;
	return value;
}

builtin_terminals_t::builtin_terminals_t() : recognizer_table(generate_lookup_table()) {
	
}

bool builtin_terminals_t::resolve_builtin_terminal(std::string const & name, terminal const *& ptr) const {
	auto const i = recognizer_table.find(name);
	if (i == recognizer_table.end()) {
		return false;
	}
	ptr = static_cast<terminal const *>(i->second); // NOLINT // it is always a terminal
	return true;
}

std::map<std::string, recognizer const *> builtin_terminals_t::generate_lookup_table() const {
	std::map<std::string, recognizer const *> result;
	terminal const * tableInitializer[] = {
		&all,
		&any_character,
		&alphanumeric,
		&basic_escape_sequence,
		&close_punctuation,
		&connector_punctuation,
		&content,
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

	for (auto item : tableInitializer) {
		auto const name = item->name;
		result[name] = item;
	}

	return result;
}

string_terminal::string_terminal(std::u32string const & s) : terminal("string_terminal_" + to_utf8(s), uint32_t(s.length())), s(s) {
}

bool string_terminal::test(std::u32string const & document, uint32_t const documentPosition) const {
	return document.compare(documentPosition, length, s) == 0;
}

std::u32string string_terminal::get_content() const {
	return s;
}

}

} // namespace parlex
