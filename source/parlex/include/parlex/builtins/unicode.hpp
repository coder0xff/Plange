#ifndef UNICODE_HPP
#define UNICODE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
	namespace details {

		class all_t : public terminal {
		public:
			all_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class alphanumeric_t : public terminal {
		public:
			alphanumeric_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class close_punctuation_t : public terminal {
		public:
			close_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class connector_punctuation_t : public terminal {
		public:
			connector_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class control_t : public terminal {
		public:
			control_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class currency_symbol_t : public terminal {
		public:
			currency_symbol_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class dash_punctuation_t : public terminal {
		public:
			dash_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class decimal_digit_t : public terminal {
		public:
			decimal_digit_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class enclosing_mark_t : public terminal {
		public:
			enclosing_mark_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class final_quote_punctuation_t : public terminal {
		public:
			final_quote_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class format_t : public terminal {
		public:
			format_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class octal_digit_t : public terminal {
		public:
			octal_digit_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class hexadecimal_digit_t : public terminal {
		public:
			hexadecimal_digit_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class initial_quote_punctuation_t : public terminal {
		public:
			initial_quote_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class latin_digit_t : public terminal {
		public:
			latin_digit_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class letter_number_t : public terminal {
		public:
			letter_number_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class letter_t : public terminal {
		public:
			letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class line_separator_t : public terminal {
		public:
			line_separator_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class lowercase_letter_t : public terminal {
		public:
			lowercase_letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class math_symbol_t : public terminal {
		public:
			math_symbol_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class modifier_letter_t : public terminal {
		public:
			modifier_letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class modifier_symbol_t : public terminal {
		public:
			modifier_symbol_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class nonspacing_mark_t : public terminal {
		public:
			nonspacing_mark_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class number_t : public terminal {
		public:
			number_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class open_punctuation_t : public terminal {
		public:
			open_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class other_letter_t : public terminal {
		public:
			other_letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class other_number_t : public terminal {
		public:
			other_number_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class other_punctuation_t : public terminal {
		public:
			other_punctuation_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class other_symbol_t : public terminal {
		public:
			other_symbol_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class paragraph_separator_t : public terminal {
		public:
			paragraph_separator_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class printable_t : public terminal {
		public:
			printable_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class public_use_t : public terminal {
		public:
			public_use_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class space_separator_t : public terminal {
		public:
			space_separator_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class spacing_combining_mark_t : public terminal {
		public:
			spacing_combining_mark_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class surrogate_t : public terminal {
		public:
			surrogate_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class titlecase_letter_t : public terminal {
		public:
			titlecase_letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class uppercase_letter_t : public terminal {
		public:
			uppercase_letter_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class white_space_t : public terminal {
		public:
			white_space_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

		class white_space_control_t : public terminal {
		public:
			white_space_control_t();
			bool test(std::u32string const & document, size_t documentPosition) const override final;
			size_t get_length() const override final;
		};

	}

	namespace builtins {

		extern details::all_t all;
		extern details::alphanumeric_t alphanumeric;
		extern details::close_punctuation_t close_punctuation;
		extern details::connector_punctuation_t connector_punctuation;
		extern details::control_t control;
		extern details::currency_symbol_t currency_symbol;
		extern details::dash_punctuation_t dash_punctuation;
		extern details::decimal_digit_t decimal_digit;
		extern details::enclosing_mark_t enclosing_mark;
		extern details::final_quote_punctuation_t final_quote_punctuation;
		extern details::format_t format;
		extern details::hexadecimal_digit_t hexadecimal_digit;
		extern details::initial_quote_punctuation_t initial_quote_punctuation;
		extern details::latin_digit_t latin_digit;
		extern details::letter_number_t letter_number;
		extern details::letter_t letter;
		extern details::line_separator_t line_separator;
		extern details::lowercase_letter_t lowercase_letter;
		extern details::math_symbol_t math_symbol;
		extern details::modifier_letter_t modifier_letter;
		extern details::modifier_symbol_t modifier_symbol;
		extern details::nonspacing_mark_t nonspacing_mark;
		extern details::number_t number;
		extern details::octal_digit_t octal_digit;
		extern details::open_punctuation_t open_punctuation;
		extern details::other_letter_t other_letter;
		extern details::other_number_t other_number;
		extern details::other_punctuation_t other_punctuation;
		extern details::other_symbol_t other_symbol;
		extern details::paragraph_separator_t paragraph_separator;
		extern details::printable_t printable;
		extern details::public_use_t public_use;
		extern details::space_separator_t space_separator;
		extern details::spacing_combining_mark_t spacing_combining_mark;
		extern details::surrogate_t surrogate;
		extern details::titlecase_letter_t titlecase_letter;
		extern details::uppercase_letter_t uppercase_letter;
		extern details::white_space_t white_space;
		extern details::white_space_control_t white_space_control;

	}
}

#endif
