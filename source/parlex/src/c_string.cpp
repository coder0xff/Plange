#include "parlex/terminal.hpp"
#include "parlex/builtins.hpp"
#include "parlex/details/unicode_op.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/builtins.hpp"

namespace parlex {
namespace builtins {
parlex::state_machine c_string("c_string", 1, parlex::builtins::greedy);
}}

namespace  {

class non_double_quote_t : public parlex::terminal {
    virtual bool test(std::u32string const & document, size_t documentPosition) const final {
        if (documentPosition >= document.length()) return false;
        return document[documentPosition] != 34;
    }
    virtual size_t get_length() const final { return 1; }
    virtual std::string get_id() const final { return "non_double_quote"; }
} non_double_quote;

class basic_escape_sequence_t : public parlex::terminal {
    virtual bool test(std::u32string const & document, size_t documentPosition) const final {
        if (documentPosition + 1 >= document.length()) return false;
        char32_t const c = document[documentPosition + 1];
        return document[documentPosition] == 92 && (c == 34 || c == 39 || c == 63 || c == 92 || c == 97 || c == 98 || c == 102 || c == 110 || c == 114 || c == 116 || c == 118);
    }
    virtual size_t get_length() const final { return 2; }
    virtual std::string get_id() const final { return "basic_escape_sequence"; }
} basic_escape_sequence;

parlex::builtins::string_terminal backslash(uni_grow("\\"));
parlex::builtins::string_terminal double_quote(uni_grow("\""));

parlex::state_machine octal_escape_sequence("octal_escape_sequence", 3, parlex::builtins::greedy);
parlex::state_machine hex_escape_sequence("hex_escape_sequence", 1, parlex::builtins::greedy);

int build() {
    octal_escape_sequence.add_transition(0, backslash, 1);
    octal_escape_sequence.add_transition(1, parlex::builtins::octal_digit, 2);
    octal_escape_sequence.add_transition(2, parlex::builtins::octal_digit, 3);
    octal_escape_sequence.add_transition(3, parlex::builtins::octal_digit, 4);

    hex_escape_sequence.add_transition(0, backslash, 1);
    hex_escape_sequence.add_transition(1, parlex::builtins::hexadecimal_digit, 2);
    hex_escape_sequence.add_transition(2, parlex::builtins::hexadecimal_digit, 2);

    parlex::builtins::c_string.add_transition(0, double_quote, 1);
    parlex::builtins::c_string.add_transition(1, non_double_quote, 1);
    parlex::builtins::c_string.add_transition(1, basic_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, octal_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, hex_escape_sequence, 1);
    parlex::builtins::c_string.add_transition(1, double_quote, 2);

    return 0;
}

int dont_care = build();
}
