#include "parlex/builtins/wirth.hpp"
#include "parlex/builtins/string_terminal.hpp"
#include "parlex/details/unicode_op.hpp"
#include "parlex/builtins.hpp"

namespace parlex {
namespace builtins {

parlex::state_machine wirth("wirth", 1);

}
}

namespace {
    class not_newline_t : public parlex::terminal {
    public:
        virtual ~not_newline_t() = default;
        virtual bool test(std::u32string const & document, size_t documentPosition) const final {
            return documentPosition < document.length() && document[documentPosition] != (char32_t)'\n';
        }
        virtual size_t get_length() const final { return 1; }
        virtual std::string get_id() const final { return "not_newline"; }
    } not_newline;

    parlex::builtins::string_terminal space(uni_grow(" "));
    parlex::builtins::string_terminal newline(uni_grow("\n"));
    parlex::builtins::string_terminal hash(uni_grow("#"));
    parlex::builtins::string_terminal period(uni_grow("."));
    parlex::builtins::string_terminal equals(uni_grow("="));
    parlex::builtins::string_terminal quote(uni_grow("\""));
    parlex::builtins::string_terminal pipe(uni_grow("|"));
    parlex::builtins::string_terminal openSquare(uni_grow("["));
    parlex::builtins::string_terminal closeSquare(uni_grow("]"));
    parlex::builtins::string_terminal openParen(uni_grow("("));
    parlex::builtins::string_terminal closeParen(uni_grow(")"));
    parlex::builtins::string_terminal openCurly(uni_grow("{"));
    parlex::builtins::string_terminal closeCurly(uni_grow("}"));

    parlex::state_machine whiteSpaceDfa("whiteSpace", 1, parlex::builtins::greedy);
    parlex::state_machine commentDfa("comment", 1);
    parlex::state_machine productionDfa("production", 1);
    parlex::state_machine expressionDfa("expression", 1);
    parlex::state_machine termDfa("term", 1);
    parlex::state_machine factorDfa("factor", 1);
    parlex::state_machine identifierDfa("identifier", 1, parlex::builtins::greedy);

    int build() {
        parlex::builtins::wirth.add_transition(0, productionDfa, 0);
        parlex::builtins::wirth.add_transition(0, whiteSpaceDfa, 0);
        parlex::builtins::wirth.add_transition(0, commentDfa, 0);

        whiteSpaceDfa.add_transition(0, space, 1);
        whiteSpaceDfa.add_transition(0, newline, 1);
		whiteSpaceDfa.add_transition(1, space, 1);
		whiteSpaceDfa.add_transition(1, newline, 1);

        commentDfa.add_transition(0, hash, 1);
        commentDfa.add_transition(1, not_newline, 1);
        commentDfa.add_transition(1, newline, 2);

        productionDfa.add_transition(0, identifierDfa, 1);

		productionDfa.add_transition(1, whiteSpaceDfa, 2);
        productionDfa.add_transition(2, equals, 3);
		productionDfa.add_transition(1, equals, 3);
        
		productionDfa.add_transition(3, whiteSpaceDfa, 4);
        productionDfa.add_transition(4, expressionDfa, 5);
		productionDfa.add_transition(3, expressionDfa, 5);

        productionDfa.add_transition(5, whiteSpaceDfa, 6);
        productionDfa.add_transition(6, period, 7);
		productionDfa.add_transition(5, period, 7);

        expressionDfa.add_transition(0, termDfa, 3);
		expressionDfa.add_transition(1, termDfa, 3);
		expressionDfa.add_transition(1, whiteSpaceDfa, 0);
		expressionDfa.add_transition(2, pipe, 1);
		expressionDfa.add_transition(3, pipe, 1);
		expressionDfa.add_transition(3, whiteSpaceDfa, 2);

        termDfa.add_transition(0, factorDfa, 1);
        termDfa.add_transition(1, whiteSpaceDfa, 0);

        factorDfa.add_transition(0, identifierDfa, 13);
        factorDfa.add_transition(0, parlex::builtins::c_string, 13);

		factorDfa.add_transition(0, openSquare, 1);
        factorDfa.add_transition(1, whiteSpaceDfa, 2);
		factorDfa.add_transition(1, expressionDfa, 3);
		factorDfa.add_transition(2, expressionDfa, 3);
		factorDfa.add_transition(3, whiteSpaceDfa, 4);
		factorDfa.add_transition(3, closeSquare, 13);
		factorDfa.add_transition(4, closeSquare, 13);

		factorDfa.add_transition(0, openParen, 5);
        factorDfa.add_transition(5, whiteSpaceDfa, 6);
		factorDfa.add_transition(5, expressionDfa, 7);
		factorDfa.add_transition(6, expressionDfa, 7);
		factorDfa.add_transition(7, whiteSpaceDfa, 8);
		factorDfa.add_transition(7, closeParen, 13);
		factorDfa.add_transition(8, closeParen, 13);
        
		factorDfa.add_transition(0, openCurly, 9);
        factorDfa.add_transition(9, whiteSpaceDfa, 10);
		factorDfa.add_transition(9, expressionDfa, 11);
		factorDfa.add_transition(10, expressionDfa, 11);
        factorDfa.add_transition(11, whiteSpaceDfa, 12);
		factorDfa.add_transition(11, closeCurly, 13);
		factorDfa.add_transition(12, closeCurly, 13);

        identifierDfa.add_transition(0, parlex::builtins::letter, 1);
        identifierDfa.add_transition(1, parlex::builtins::letter, 1);

        return 0;
    }

    int dont_care = build();

}

