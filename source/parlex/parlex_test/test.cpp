#include <fstream>
#include <thread>
#include <codecvt>

#include "gtest/gtest.h"
#include "abstract_syntax_graph.hpp"
#include "builtins.hpp"
#include "parser.hpp"
#include "state_machine.hpp"
#include "builder.hpp"
#include "utils.hpp"
#include "compiled_grammar.hpp"

TEST(ParlexTest, parser_test_1) {
	//DBG("************ parser_test_1 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "machine");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, p.builtins.any_character, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"a");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_2) {
	//DBG("************ parser_test_2 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "machine");

	parlex::builtins_t::string_terminal & helloWorld = g.add_literal(U"Hello, world!");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, helloWorld, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_3) {
	//DBG("************ parser_test_3 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "machine");

	parlex::builtins_t::string_terminal & foo = g.add_literal(U"Foo");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, foo, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"bar");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_4) {
	//DBG("************ parser_test_4 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "machine");

	parlex::builtins_t::string_terminal & hello = g.add_literal(U"Hello");
	parlex::builtins_t::string_terminal & world = g.add_literal(U", world");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, hello, 1);
	s.add_transition(1, world, 2);
	s.add_transition(2, p.builtins.any_character, 3);

	parlex::abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_5) {
	//DBG("************ parser_test_5 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "machine");
	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, p.builtins.decimal_digit, 1);
	s.add_transition(1, p.builtins.decimal_digit, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"982874599127");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_6) {
	//DBG("************ parser_test_6 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "csv");

	parlex::builtins_t::string_terminal & comma = g.add_literal(U",");

	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & csv = g.add_production("csv", 0, 1);

	csv.add_transition(0, num, 1);
	csv.add_transition(1, comma, 0);

	num.add_transition(0, p.builtins.decimal_digit, 1);
	num.add_transition(1, p.builtins.decimal_digit, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"1,2");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_7) {
	//DBG("************ parser_test_7 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "nested_csv");

	parlex::builtins_t::string_terminal & open_paren = g.add_literal(U"(");
	parlex::builtins_t::string_terminal & close_paren = g.add_literal(U")");
	parlex::builtins_t::string_terminal & comma = g.add_literal(U",");

	parlex::state_machine & nested_csv = g.add_production("nested_csv", 0, 1);
	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, p.builtins.decimal_digit, 1);
	num.add_transition(1, p.builtins.decimal_digit, 1);

	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, nested_csv, 2);
	paren.add_transition(2, close_paren, 3);

	nested_csv.add_transition(0, num, 2);
	nested_csv.add_transition(0, paren, 2);
	nested_csv.add_transition(2, comma, 1);
	nested_csv.add_transition(1, num, 2);
	nested_csv.add_transition(1, paren, 2);

	for (int i = 0; i < 10; i++) {
		parlex::abstract_syntax_graph result = p.parse(g, U"12,(34,56),789");
		if (!result.is_rooted()) {
			throw std::logic_error("Test failed");
		}
	}
}

//direct left recursion
TEST(ParlexTest, parser_test_8) {
	//DBG("************ parser_test_8 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "expr");

	parlex::builtins_t::string_terminal & bang = g.add_literal(U"!");

	parlex::state_machine & expr = g.add_production("expr", 0, 1);
	parlex::state_machine & factorial = g.add_production("factorial", 0, 1);

	factorial.add_transition(0, expr, 1);
	factorial.add_transition(1, bang, 2);

	expr.add_transition(0, p.builtins.decimal_digit, 1);
	expr.add_transition(0, factorial, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"1!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

//indirect left recursion
TEST(ParlexTest, parser_test_9) {
	//DBG("************ parser_test_9 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "expr");

	parlex::builtins_t::string_terminal & plus = g.add_literal(U"+");
	parlex::builtins_t::string_terminal & minus = g.add_literal(U"-");
	parlex::builtins_t::string_terminal & asterisk = g.add_literal(U"*");
	parlex::builtins_t::string_terminal & slash = g.add_literal(U"/");
	parlex::builtins_t::string_terminal & open_paren = g.add_literal(U"(");
	parlex::builtins_t::string_terminal & close_paren = g.add_literal(U")");

	parlex::state_machine & num = g.add_production("num", 0, 1);
	parlex::state_machine & expr = g.add_production("expr", 0, 1);
	parlex::state_machine & add = g.add_production("add", 0, 1);
	parlex::state_machine & sub = g.add_production("sub", 0, 1);
	parlex::state_machine & mul = g.add_production("mul", 0, 1);
	parlex::state_machine & div = g.add_production("div", 0, 1);
	parlex::state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, p.builtins.decimal_digit, 1);
	num.add_transition(1, p.builtins.decimal_digit, 1);

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

	parlex::abstract_syntax_graph result = p.parse(g, U"1-2-3-4");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_10) {
	//DBG("************ parser_test_10 ************");
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "identifier");

	parlex::builtins_t::string_terminal & underscore = g.add_literal(U"_");

	parlex::state_machine & identifier = g.add_production("identifier", 0, 1);

	identifier.add_transition(0, p.builtins.letter, 1);
	identifier.add_transition(0, underscore, 1);
	identifier.add_transition(1, p.builtins.letter, 1);
	identifier.add_transition(1, underscore, 1);
	identifier.add_transition(1, p.builtins.number, 1);

	parlex::abstract_syntax_graph result = p.parse(g, U"hi");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_1) {
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "s");

	parlex::state_machine & s = g.add_production("s", 0, 1);
	
	s.add_transition(0, p.builtins.c_string, 1);

    parlex::abstract_syntax_graph result = p.parse(g, U"\"abc123\\\"\"");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_2) {
	parlex::parser p(1);
	parlex::grammar g(p.builtins, "s");

	parlex::state_machine & s = g.add_production("s", 0, 1);

	s.add_transition(0, p.builtins.c_string, 1);

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
	parlex::abstract_syntax_graph result = p.parse(p.builtins.wirth, U"a=x.");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_2) {
    parlex::parser p;
    parlex::abstract_syntax_graph result = p.parse(p.builtins.wirth, to_utf32(wirthInItself));
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3) {
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(p.builtins.wirth, U"a=\"\\\\\".b=\"\".");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_4) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", to_utf32(wirthInItself), {}, {});
}

TEST(ParlexTest, wirth_test_5) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {});
	parlex::abstract_syntax_graph result = p.parse(grammar, U"b");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_6) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {});
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_7) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {});
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1234");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_8) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {});
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
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {});
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
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("ARRAY", U"\
ARRAY = \"[\" {IC} [EXPRESSION {{IC} \", \" {IC} EXPRESSION} {IC} ] \"]\".\
IC = \"IC\".\
EXPRESSION = \"EXPRESSION\".", {}, {});
	parlex::abstract_syntax_graph result = p.parse(grammar, U"[]");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_11) {
	parlex::parser p;
	auto grammar = p.builtins.wirth.load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {});
}

parlex::builtins_t::string_terminal plusSign(U"+");
parlex::builtins_t::string_terminal timesSign(U"*");

DECLARE_DFA(ADD);
DECLARE_DFA(MUL);
DECLARE_DFA(EXPR);

DECLARE_GRAMMAR(compiledGrammar1);

DEFINE_DFA(ADD,
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
, 0
);

DEFINE_DFA(MUL, 
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
, 0
);

parlex::parser p;

DEFINE_DFA(EXPR,
	DFA_STATE 0:
		DFA_EDGE(ADD, 1);
		DFA_EDGE(MUL, 1);
		DFA_EDGE(p.builtins.number, 1);
		break;
	DFA_STATE 1:
		DFA_ACCEPT;
		break;
, 0
);

DEFINE_GRAMMAR(
	p.builtins,
	compiledGrammar1, 
	EXPR, 
	({ EXPR, MUL, ADD, }),
	({ 
		GRAMMAR_PRECEDENCE(MUL, ADD),
	})
);

TEST(ParlexTest, compiled_1) {
	std::u32string document = U"5+3*2";
	parlex::abstract_syntax_graph result = p.parse(compiledGrammar1, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	std::string concreteDot = result.to_concrete_dot(document);
}

/*
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
*/
