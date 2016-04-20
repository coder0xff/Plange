#ifndef UNICODE_HPP
#define UNICODE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class all_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "all"; }
};

class alphanumeric_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "alphanumeric"; }
};

class close_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "close_punctuation"; }
};

class connector_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "connector_punctuation"; }
};

class control_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "control"; }
};

class currency_symbol_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "currency_symbol"; }
};

class dash_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "dash_punctuation"; }
};

class decimal_digit_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "decimal_digit"; }
};

class enclosing_mark_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "enclosing_mark"; }
};

class final_quote_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "final_quote_punctuation"; }
};

class format_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "format"; }
};

class octal_digit_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "octal_digit"; }
};

class hexadecimal_digit_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "hexadecimal_digit"; }
};

class initial_quote_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "initial_quote_punctuation"; }
};

class latin_digit_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "latin_digit"; }
};

class letter_number_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "letter_number"; }
};

class letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "letter"; }
};

class line_separator_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "line_separator"; }
};

class lowercase_letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "lowercase_letter"; }
};

class math_symbol_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "math_symbol"; }
};

class modifier_letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "modifier_letter"; }
};

class modifier_symbol_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "modifier_symbol"; }
};

class nonspacing_mark_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "nonspacing_mark"; }
};

class number_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "number"; }
};

class open_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "open_punctuation"; }
};

class other_letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "other_letter"; }
};

class other_number_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "other_number"; }
};

class other_punctuation_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "other_punctuation"; }
};

class other_symbol_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "other_symbol"; }
};

class paragraph_separator_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "paragraph_separator"; }
};

class printable_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "printable"; }
};

class public_use_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "public_use"; }
};

class space_separator_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "space_separator"; }
};

class spacing_combining_mark_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "spacing_combining_mark"; }
};

class surrogate_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "surrogate"; }
};

class titlecase_letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "titlecase_letter"; }
};

class uppercase_letter_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "uppercase_letter"; }
};

class white_space_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "white_space"; }
};

class white_space_control_t : public terminal {
public:
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;

	inline virtual size_t get_length() const final { return 1; }
	inline std::string get_id() const final { return "white_space_control"; }
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
