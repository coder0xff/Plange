#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <codecvt>

#include "gtest/gtest.h"
#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/builtins.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/builder.hpp"
#include "utils.hpp"
#include "parlex/compiled_grammar.hpp"

TEST(ParlexTest, parser_test_1) {
	//DBG("************ parser_test_1 ************");
	parlex::grammar g("machine");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, parlex::builtins::any_character, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"a");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_2) {
	//DBG("************ parser_test_2 ************");
	parlex::grammar g("machine");

	parlex::builtins::string_terminal & helloWorld = g.add_literal(U"Hello, world!");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, helloWorld, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_3) {
	//DBG("************ parser_test_3 ************");
	parlex::grammar g("machine");

	parlex::builtins::string_terminal & foo = g.add_literal(U"Foo");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, foo, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"bar");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_4) {
	//DBG("************ parser_test_4 ************");
	parlex::grammar g("machine");

	parlex::builtins::string_terminal & hello = g.add_literal(U"Hello");
	parlex::builtins::string_terminal & world = g.add_literal(U", world");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, hello, 1);
	s.add_transition(1, world, 2);
	s.add_transition(2, parlex::builtins::any_character, 3);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_5) {
	//DBG("************ parser_test_5 ************");
	parlex::grammar g("machine");
	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, parlex::builtins::decimal_digit, 1);
	s.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"982874599127");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_6) {
	//DBG("************ parser_test_6 ************");
	parlex::grammar g("csv");

	parlex::builtins::string_terminal & comma = g.add_literal(U",");

	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & csv = g.add_production("csv", 0, 1);

	csv.add_transition(0, num, 1);
	csv.add_transition(1, comma, 0);

	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"1,2");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_7) {
	//DBG("************ parser_test_7 ************");
	parlex::grammar g("nested_csv");

	parlex::builtins::string_terminal & open_paren = g.add_literal(U"(");
	parlex::builtins::string_terminal & close_paren = g.add_literal(U")");
	parlex::builtins::string_terminal & comma = g.add_literal(U",");

	parlex::state_machine & nested_csv = g.add_production("nested_csv", 0, 1);
	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, nested_csv, 2);
	paren.add_transition(2, close_paren, 3);

	nested_csv.add_transition(0, num, 2);
	nested_csv.add_transition(0, paren, 2);
	nested_csv.add_transition(2, comma, 1);
	nested_csv.add_transition(1, num, 2);
	nested_csv.add_transition(1, paren, 2);

	for (int i = 0; i < 10; i++) {
		parlex::parser p(1);
		parlex::abstract_syntax_graph result = p.parse(g, U"12,(34,56),789");
		if (!result.is_rooted()) {
			throw std::logic_error("Test failed");
		}
	}
}

//direct left recursion
TEST(ParlexTest, parser_test_8) {
	//DBG("************ parser_test_8 ************");
	parlex::grammar g("expr");

	parlex::builtins::string_terminal & bang = g.add_literal(U"!");

	parlex::state_machine & expr = g.add_production("expr", 0, 1);
	parlex::state_machine & factorial = g.add_production("factorial", 0, 1);

	factorial.add_transition(0, expr, 1);
	factorial.add_transition(1, bang, 2);

	expr.add_transition(0, parlex::builtins::decimal_digit, 1);
	expr.add_transition(0, factorial, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"1!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

//indirect left recursion
TEST(ParlexTest, parser_test_9) {
	//DBG("************ parser_test_9 ************");
	parlex::grammar g("expr");

	parlex::builtins::string_terminal & plus = g.add_literal(U"+");
	parlex::builtins::string_terminal & minus = g.add_literal(U"-");
	parlex::builtins::string_terminal & asterisk = g.add_literal(U"*");
	parlex::builtins::string_terminal & slash = g.add_literal(U"/");
	parlex::builtins::string_terminal & open_paren = g.add_literal(U"(");
	parlex::builtins::string_terminal & close_paren = g.add_literal(U")");

	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & expr = g.add_production("expr", 0, 1);
	parlex::state_machine & add = g.add_production("add", 0, 1);
	parlex::state_machine & sub = g.add_production("sub", 0, 1);
	parlex::state_machine & mul = g.add_production("mul", 0, 1);
	parlex::state_machine & div = g.add_production("div", 0, 1);
	parlex::state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	add.add_transition(0, expr, 1);
	add.add_transition(1, plus, 2);
	add.add_transition(2, expr, 3);

	sub.add_transition(0, expr, 1);
	sub.add_transition(1, minus, 2);
	sub.add_transition(2, expr, 3);

	mul.add_transition(0, expr, 1);
	mul.add_transition(1, asterisk, 2);
	mul.add_transition(2, expr, 3);

	div.add_transition(0, expr, 1);
	div.add_transition(1, slash, 2);
	div.add_transition(2, expr, 3);

	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, expr, 2);
	paren.add_transition(2, close_paren, 3);

	expr.add_transition(0, num, 1);
	expr.add_transition(0, add, 1);
	expr.add_transition(0, sub, 1);
	expr.add_transition(0, mul, 1);
	expr.add_transition(0, div, 1);
	expr.add_transition(0, paren, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"1-2-3-4");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_10) {
	//DBG("************ parser_test_10 ************");
	parlex::grammar g("identifier");

	parlex::builtins::string_terminal & underscore = g.add_literal(U"_");

	parlex::state_machine & identifier = g.add_production("identifier", 0, 1);

	identifier.add_transition(0, parlex::builtins::letter, 1);
	identifier.add_transition(0, underscore, 1);
	identifier.add_transition(1, parlex::builtins::letter, 1);
	identifier.add_transition(1, underscore, 1);
	identifier.add_transition(1, parlex::builtins::number, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"hi");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_1) {
	parlex::grammar g("s");

	parlex::state_machine & s = g.add_production("s", 0, 1);
	
	s.add_transition(0, parlex::builtins::c_string, 1);

    parlex::parser p(1);
    parlex::abstract_syntax_graph result = p.parse(g, U"\"abc123\\\"\"");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_2) {
	parlex::grammar g("s");

	parlex::state_machine & s = g.add_production("s", 0, 1);

	s.add_transition(0, parlex::builtins::c_string, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"\"\\\\\"");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

    std::string wirthInItself = "\
SYNTAX     = {white_space} { PRODUCTION {white_space} } . \
PRODUCTION = IDENTIFIER {white_space} \"=\" {white_space} EXPRESSION {white_space} \".\" . \
EXPRESSION = TERM { {white_space} \"|\" {white_space} TERM } . \
TERM       = FACTOR { {white_space} FACTOR } . \
FACTOR     = IDENTIFIER \
           | c_string \
           | \"[\" {white_space} EXPRESSION {white_space} \"]\" \
           | \"(\" {white_space} EXPRESSION {white_space} \")\" \
           | \"{\" {white_space} EXPRESSION {white_space} \"}\" . \
IDENTIFIER = letter { letter } .";

TEST(ParlexTest, wirth_test_1) {
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, U"a=x.");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_2) {
    parlex::parser p;
    parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, to_utf32(wirthInItself));
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3) {
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, U"a=\"\\\\\".b=\"\".");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_4) {
	auto grammar = parlex::load_grammar("SYNTAX", to_utf32(wirthInItself), {}, {});
}

TEST(ParlexTest, wirth_test_5) {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"b");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_6) {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_7) {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1234");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_8) {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar, U"a");
	if (!result1.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	parlex::abstract_syntax_graph result2 = p.parse(grammar, U"a1");
	if (!result2.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_9) {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar, U"a1");
	if (!result1.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	parlex::abstract_syntax_graph result2 = p.parse(grammar, U"a\"test\"");
	if (!result2.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_10) {
	auto grammar = parlex::load_grammar("ARRAY", U"\
ARRAY = \"[\" {IC} [EXPRESSION {{IC} \", \" {IC} EXPRESSION} {IC} ] \"]\".\
IC = \"IC\".\
EXPRESSION = \"EXPRESSION\".", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"[]");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_11) {
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {});
}

parlex::builtins::string_terminal plusSign(U"+");
parlex::builtins::string_terminal timesSign(U"*");

DECLARE_STATE_MACHINE(ADD, 0);
DECLARE_STATE_MACHINE(MUL, 0);
DECLARE_STATE_MACHINE(EXPR, 0);

DEFINE_STATE_MACHINE(ADD,
	DFA_STATE 0:
		DFA_EDGE(EXPR, 1);
		break;
	DFA_STATE 1:
		DFA_EDGE(plusSign, 2);
		break;
	DFA_STATE 2:
		DFA_EDGE(EXPR, 3);
		break;
	DFA_STATE 3:
		DFA_ACCEPT;
		break;
)

DEFINE_STATE_MACHINE(MUL, 
	DFA_STATE 0:
		DFA_EDGE(EXPR, 1);
		break;
	DFA_STATE 1:
		DFA_EDGE(timesSign, 2);
		break;
	DFA_STATE 2:
		DFA_EDGE(EXPR, 3);
		break;
	DFA_STATE 3:
		DFA_ACCEPT;
		break;
)

DEFINE_STATE_MACHINE(EXPR,
	DFA_STATE 0:
		DFA_EDGE(ADD, 1);
		DFA_EDGE(MUL, 1);
		DFA_EDGE(parlex::builtins::number, 1);
		break;
	DFA_STATE 1:
		DFA_ACCEPT;
		break;
)

COMPILED_GRAMMAR(
	compiledGrammar1, 
	EXPR, 
	({ EXPR, MUL, ADD, }),
	({ 
		GRAMMAR_PRECEDENCE(MUL, ADD),
	})
);

TEST(ParlexTest, compiled_1) {
	std::u32string document = U"5+3*2";
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(compiledGrammar1, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	std::string concreteDot = result.to_concrete_dot(document);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
