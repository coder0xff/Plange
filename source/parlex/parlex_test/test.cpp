#include <fstream>
#include <thread>
#include <codecvt>

#include "gtest/gtest.h"

#include "parlex/builder.hpp"
#include "parlex/correlated_grammar.hpp"
#include "parlex/grammar.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"

#include "utf.hpp"


using namespace parlex;

TEST(ParlexTest, parser_test_1) {
	//DBG("************ parser_test_1 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "machine");

	state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, &p.builtins.any_character, 1);

	abstract_syntax_graph result = p.parse(g, U"a");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_2) {
	//DBG("************ parser_test_2 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "machine");

	builtins_t::string_terminal & helloWorld = g.get_or_add_literal(U"Hello, world!");

	state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, &helloWorld, 1);

	abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_3) {
	//DBG("************ parser_test_3 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "machine");

	builtins_t::string_terminal & foo = g.get_or_add_literal(U"Foo");

	state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, &foo, 1);

	abstract_syntax_graph result = p.parse(g, U"bar");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_4) {
	//DBG("************ parser_test_4 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "machine");

	builtins_t::string_terminal & hello = g.get_or_add_literal(U"Hello");
	builtins_t::string_terminal & world = g.get_or_add_literal(U", world");

	state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, &hello, 1);
	s.add_transition(1, &world, 2);
	s.add_transition(2, &p.builtins.any_character, 3);

	abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_5) {
	//DBG("************ parser_test_5 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "machine");
	state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, &p.builtins.decimal_digit, 1);
	s.add_transition(1, &p.builtins.decimal_digit, 1);

	abstract_syntax_graph result = p.parse(g, U"982874599127");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_6) {
	//DBG("************ parser_test_6 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "csv");

	builtins_t::string_terminal & comma = g.get_or_add_literal(U",");

	state_machine & num = g.add_production("num", 0, 1);
	state_machine & csv = g.add_production("csv", 0, 1);

	csv.add_transition(0, &num, 1);
	csv.add_transition(1, &comma, 0);

	num.add_transition(0, &p.builtins.decimal_digit, 1);
	num.add_transition(1, &p.builtins.decimal_digit, 1);

	abstract_syntax_graph result = p.parse(g, U"1,2");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_7) {
	//DBG("************ parser_test_7 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "nested_csv");

	builtins_t::string_terminal & open_paren = g.get_or_add_literal(U"(");
	builtins_t::string_terminal & close_paren = g.get_or_add_literal(U")");
	builtins_t::string_terminal & comma = g.get_or_add_literal(U",");

	state_machine & nested_csv = g.add_production("nested_csv", 0, 1);
	state_machine & num = g.add_production("num", 0, 1);
	state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, &p.builtins.decimal_digit, 1);
	num.add_transition(1, &p.builtins.decimal_digit, 1);

	paren.add_transition(0, &open_paren, 1);
	paren.add_transition(1, &nested_csv, 2);
	paren.add_transition(2, &close_paren, 3);

	nested_csv.add_transition(0, &num, 2);
	nested_csv.add_transition(0, &paren, 2);
	nested_csv.add_transition(2, &comma, 1);
	nested_csv.add_transition(1, &num, 2);
	nested_csv.add_transition(1, &paren, 2);

	for (int i = 0; i < 10; i++) {
		abstract_syntax_graph result = p.parse(g, U"12,(34,56),789");
		if (!result.is_rooted()) {
			throw std::logic_error("Test failed");
		}
	}
}

//direct left recursion
TEST(ParlexTest, parser_test_8) {
	//DBG("************ parser_test_8 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "expr");

	builtins_t::string_terminal & bang = g.get_or_add_literal(U"!");

	state_machine & expr = g.add_production("expr", 0, 1);
	state_machine & factorial = g.add_production("factorial", 0, 1);

	factorial.add_transition(0, &expr, 1);
	factorial.add_transition(1, &bang, 2);

	expr.add_transition(0, &p.builtins.decimal_digit, 1);
	expr.add_transition(0, &factorial, 1);

	abstract_syntax_graph result = p.parse(g, U"1!");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

//indirect left recursion
TEST(ParlexTest, parser_test_9) {
	//DBG("************ parser_test_9 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "expr");

	builtins_t::string_terminal & plus = g.get_or_add_literal(U"+");
	builtins_t::string_terminal & minus = g.get_or_add_literal(U"-");
	builtins_t::string_terminal & asterisk = g.get_or_add_literal(U"*");
	builtins_t::string_terminal & slash = g.get_or_add_literal(U"/");
	builtins_t::string_terminal & open_paren = g.get_or_add_literal(U"(");
	builtins_t::string_terminal & close_paren = g.get_or_add_literal(U")");

	state_machine & num = g.add_production("num", 0, 1);
	state_machine & expr = g.add_production("expr", 0, 1);
	state_machine & add = g.add_production("add", 0, 1);
	state_machine & sub = g.add_production("sub", 0, 1);
	state_machine & mul = g.add_production("mul", 0, 1);
	state_machine & div = g.add_production("div", 0, 1);
	state_machine & paren = g.add_production("paren", 0, 1);

	num.add_transition(0, &p.builtins.decimal_digit, 1);
	num.add_transition(1, &p.builtins.decimal_digit, 1);

	add.add_transition(0, &expr, 1);
	add.add_transition(1, &plus, 2);
	add.add_transition(2, &expr, 3);

	sub.add_transition(0, &expr, 1);
	sub.add_transition(1, &minus, 2);
	sub.add_transition(2, &expr, 3);

	mul.add_transition(0, &expr, 1);
	mul.add_transition(1, &asterisk, 2);
	mul.add_transition(2, &expr, 3);

	div.add_transition(0, &expr, 1);
	div.add_transition(1, &slash, 2);
	div.add_transition(2, &expr, 3);

	paren.add_transition(0, &open_paren, 1);
	paren.add_transition(1, &expr, 2);
	paren.add_transition(2, &close_paren, 3);

	expr.add_transition(0, &num, 1);
	expr.add_transition(0, &add, 1);
	expr.add_transition(0, &sub, 1);
	expr.add_transition(0, &mul, 1);
	expr.add_transition(0, &div, 1);
	expr.add_transition(0, &paren, 1);

	abstract_syntax_graph result = p.parse(g, U"1-2-3-4");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, parser_test_10) {
	//DBG("************ parser_test_10 ************");
	parser p(1);
	parlex::grammar g(p.builtins, "identifier");

	builtins_t::string_terminal & underscore = g.get_or_add_literal(U"_");

	state_machine & identifier = g.add_production("identifier", 0, 1);

	identifier.add_transition(0, &p.builtins.letter, 1);
	identifier.add_transition(0, &underscore, 1);
	identifier.add_transition(1, &p.builtins.letter, 1);
	identifier.add_transition(1, &underscore, 1);
	identifier.add_transition(1, &p.builtins.number, 1);

	abstract_syntax_graph result = p.parse(g, U"hi");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_1) {
	parser p(1);
	parlex::grammar g(p.builtins, "s");

	state_machine & s = g.add_production("s", 0, 1);

	s.add_transition(0, &p.builtins.c_string, 1);

	abstract_syntax_graph result = p.parse(g, U"\"abc123\\\"\"");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, c_string_test_2) {
	parser p(1);
	parlex::grammar g(p.builtins, "s");

	state_machine & s = g.add_production("s", 0, 1);

	s.add_transition(0, &p.builtins.c_string, 1);

	abstract_syntax_graph result = p.parse(g, U"\"\\\\\"");
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
	parser p(1);
	abstract_syntax_graph result = p.parse(p.builtins.wirth, U"a=x.");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_2) {
	parser p;
	abstract_syntax_graph result = p.parse(p.builtins.wirth, to_utf32(wirthInItself));
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3) {
	parser p;
	abstract_syntax_graph result = p.parse(p.builtins.wirth, U"a=\"\\\\\".b=\"\".");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3_1) {
	parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"EXPRESSION = {white_space} .", {}, {});
}

TEST(ParlexTest, wirth_test_3_2) {
	parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"EXPRESSION = { {white_space} } .", {}, {});
}

TEST(ParlexTest, wirth_test_3_5) {
	parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", U"EXPRESSION = { {white_space} \"|\" {white_space} } .", {}, {});
}

TEST(ParlexTest, wirth_test_4) {
	parser p;
	auto grammar = p.builtins.wirth.load_grammar("SYNTAX", to_utf32(wirthInItself), {}, {});
}

TEST(ParlexTest, wirth_test_5) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {}));
	abstract_syntax_graph result = p.parse(grammar, U"b");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_6) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {}));
	abstract_syntax_graph result = p.parse(grammar, U"a1");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_7) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {}));
	abstract_syntax_graph result = p.parse(grammar, U"a1234");
	EXPECT_TRUE(result.is_rooted());
}

TEST(ParlexTest, wirth_test_8) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {}));
	abstract_syntax_graph result1 = p.parse(grammar, U"a");
	EXPECT_TRUE(result1.is_rooted());
	abstract_syntax_graph result2 = p.parse(grammar, U"a1");
	EXPECT_TRUE(result2.is_rooted());
}

TEST(ParlexTest, wirth_test_9) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {}));
	abstract_syntax_graph result1 = p.parse(grammar, U"a1");
	if (!result1.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	abstract_syntax_graph result2 = p.parse(grammar, U"a\"test\"");
	if (!result2.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_10) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("ARRAY", U"\
ARRAY = \"[\" [EXPRESSION { \", \" EXPRESSION} ] \"]\".\
EXPRESSION = \"EXPRESSION\".", {}, {}));
	abstract_syntax_graph result = p.parse(grammar, U"[]");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_11) {
	parser p;
	correlated_grammar grammar(p.builtins, p.builtins.wirth.load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {}));
}

TEST(ParlexTest, wirth_test_12) {
	std::u32string t = U"DIMENSIONAL_NUMBER | EMBEDDED_STRING";
	parser p(1);
	p.builtins.wirth.compile_expression(t);
}

using namespace builder;

TEST(ParlexTest, behavior_1) {
	builder::grammar g_builder("EXPR", {
		                           production("ADD", sequence({reference("EXPR"), literal(U"+"), reference("EXPR")})),
		                           production("MUL", sequence({reference("EXPR"), literal(U"*"), reference("EXPR")})),
		                           production("EXPR",
		                                      choice({
			                                      reference("ADD"),
			                                      reference("MUL"),
			                                      sequence({
				                                      reference("number"),
				                                      repetition(reference("number"))
			                                      })
		                                      })
		                           ),
	                           });

	parser p;
	correlated_grammar g(p.builtins, g_builder);

	std::u32string document = U"5+3*2";
	abstract_syntax_graph result = p.parse(g, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	std::string concreteDot = result.to_concrete_dot(document);

}

TEST(ParlexTest, behavior_2) {
	builder::grammar g_builder("A", {
		production("A", sequence({
			optional(reference("white_space")),
			reference("letter")
		}))
	});

	parser p;
	correlated_grammar g(p.builtins, g_builder);

}

/*
int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
*/
