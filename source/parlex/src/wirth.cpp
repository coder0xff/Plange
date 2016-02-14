#include "parlex/builtins/wirth.hpp"
#include "parlex/builtins/string_terminal.hpp"
#include "parlex/details/unicode_op.hpp"
#include "parlex/builtins.hpp"

parlex::state_machine wirth("syntax", 1);

namespace {

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

    parlex::state_machine productionDfa("production", 1);
    parlex::state_machine expressionDfa("expression", 1);
    parlex::state_machine termDfa("term", 1);
    parlex::state_machine factorDfa("factor", 1);
    parlex::state_machine identifierDfa("identifier", 1, parlex::builtins::greedy);

    int build() {
        wirth.add_transition(0, productionDfa, 0);

        productionDfa.add_transition(0, identifierDfa, 1);
        productionDfa.add_transition(1, equals, 2);
        productionDfa.add_transition(2, expressionDfa, 3);
        productionDfa.add_transition(3, period, 4);

        expressionDfa.add_transition(0, termDfa, 1);
        expressionDfa.add_transition(1, pipe, 0);

        termDfa.add_transition(0, factorDfa, 1);
        termDfa.add_transition(1, factorDfa, 1);

        factorDfa.add_transition(0, identifierDfa, 7);
        factorDfa.add_transition(0, parlex::builtins::c_string, 7);
        factorDfa.add_transition(0, openSquare, 1);
        factorDfa.add_transition(1, expressionDfa, 2);
        factorDfa.add_transition(2, closeSquare, 7);
        factorDfa.add_transition(0, openParen, 3);
        factorDfa.add_transition(3, expressionDfa, 4);
        factorDfa.add_transition(4, closeParen, 7);
        factorDfa.add_transition(0, openCurly, 5);
        factorDfa.add_transition(5, expressionDfa, 6);
        factorDfa.add_transition(6, closeCurly, 7);

        identifierDfa.add_transition(0, parlex::builtins::letter, 1);
        identifierDfa.add_transition(1, parlex::builtins::letter, 1);

        return 0;
    }

    int dont_care = build();

}

