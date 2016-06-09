#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <codecvt>

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/builtins.hpp"
#include "logging.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"
#include "utils.hpp"

void parser_test_1() {
	//DBG("************ parser_test_1 ************");
	parlex::grammar g("machine");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, parlex::builtins::any_character, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"a");
	assert(result.is_rooted());
}

void parser_test_2() {
	//DBG("************ parser_test_2 ************");
	parlex::grammar g("machine");

	parlex::builtins::string_terminal & helloWorld = g.add_literal(U"Hello, world!");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, helloWorld, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"Hello, world!");
	assert(result.is_rooted());
}

void parser_test_3() {
	//DBG("************ parser_test_3 ************");
	parlex::grammar g("machine");

	parlex::builtins::string_terminal & foo = g.add_literal(U"Foo");

	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, foo, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"bar");
	assert(!result.is_rooted());
}

void parser_test_4() {
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
	assert(result.is_rooted());
}

void parser_test_5() {
	//DBG("************ parser_test_5 ************");
	parlex::grammar g("machine");
	parlex::state_machine & s = g.add_production("machine", 0, 1);

	s.add_transition(0, parlex::builtins::decimal_digit, 1);
	s.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"982874599127");
	assert(result.is_rooted());
}

void parser_test_6() {
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
	assert(result.is_rooted());
}

void parser_test_7() {
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
		assert(result.is_rooted());
	}
}

//direct left recursion
void parser_test_8() {
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
	assert(result.is_rooted());
}

//indirect left recursion
void parser_test_9() {
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
	assert(result.is_rooted());
}

void parser_test_10() {
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
	assert(result.is_rooted());
}

void c_string_test_1() {
	parlex::grammar g("s");

	parlex::state_machine & s = g.add_production("s", 0, 1);
	
	s.add_transition(0, parlex::builtins::c_string, 1);

    parlex::parser p(1);
    parlex::abstract_syntax_graph result = p.parse(g, U"\"abc123\\\"\"");
	assert(result.is_rooted());
}

void c_string_test_2() {
	parlex::grammar g("s");

	parlex::state_machine & s = g.add_production("s", 0, 1);

	s.add_transition(0, parlex::builtins::c_string, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(g, U"\"\\\\\"");
	assert(result.is_rooted());
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

void wirth_test_1() {
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, U"a=x.");
	assert(result.is_rooted());
}

void wirth_test_2() {
    parlex::parser p;
    parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, to_utf32(wirthInItself));
	assert(result.is_rooted());
}

void wirth_test_3() {
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, U"a=\"\\\\\".b=\"\".");
	assert(result.is_rooted());
}

void wirth_test_4() {
	auto grammar = parlex::load_grammar("SYNTAX", to_utf32(wirthInItself), {}, {});
}

void wirth_test_5() {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"b");
	assert(!result.is_rooted());
}

void wirth_test_6() {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1");
	assert(result.is_rooted());
}

void wirth_test_7() {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"a1234");
	assert(result.is_rooted());
}

void wirth_test_8() {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar, U"a");
	assert(result1.is_rooted());
	parlex::abstract_syntax_graph result2 = p.parse(grammar, U"a1");
	assert(result2.is_rooted());
}

void wirth_test_9() {
	auto grammar = parlex::load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar, U"a1");
	assert(result1.is_rooted());
	parlex::abstract_syntax_graph result2 = p.parse(grammar, U"a\"test\"");
	assert(result2.is_rooted());
}

void wirth_test_10() {
	auto grammar = parlex::load_grammar("ARRAY", U"\
ARRAY = \"[\" {IC} [EXPRESSION {{IC} \", \" {IC} EXPRESSION} {IC} ] \"]\".\
IC = \"IC\".\
EXPRESSION = \"EXPRESSION\".", {}, {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, U"[]");
	assert(result.is_rooted());
}

void wirth_test_11() {
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {});
}

void plange_test_1() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, contents);
	assert(result.is_rooted());
}

void plange_test_2() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });
}

void plange_test_3() {
	//load Plange grammar
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });

	//try parsing a simple program
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(grammar, U"print(\"Hello, world!\");");
	assert(result.is_rooted());
}

void plange_test_4() {
	//load Plange grammar
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });

	std::u32string input = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\Examples\\intToString.pge"));

	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar, input);
	assert(result.is_rooted());
}

void plange_test_5() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });

	parlex::parser p;

	std::ifstream u("C:\\Users\\Brent\\Dropbox\\Plange\\source\\Examples\\intToString.pge");
	std::u32string str = read_with_bom(u);

	std::u32string input1 = str + str;
	parlex::abstract_syntax_graph result1 = p.parse(grammar, input1);
	assert(result1.is_rooted());

	std::u32string input2 = str + str + str;
	parlex::abstract_syntax_graph result2 = p.parse(grammar, input2);
	assert(result2.is_rooted());

	std::u32string input3 = str + str + str + str;
	parlex::abstract_syntax_graph result3 = p.parse(grammar, input3);
	assert(result3.is_rooted());
}

void plange_test_6() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });

	parlex::parser p;

	std::u32string input1 = U"1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;";
	parlex::abstract_syntax_graph result1 = p.parse(grammar, input1);
	assert(result1.is_rooted());

	std::u32string input2 = U"1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;";
	parlex::abstract_syntax_graph result2 = p.parse(grammar, input2);
	assert(result2.is_rooted());
}

void generate_test_1() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });

	std::ostringstream cppStream, hppStream;
	grammar.generate_cpp("plange", "STATEMENT_SCOPE", cppStream, hppStream);
	std::cout << "\n******************** cpp *******************\n";
	std::cout << cppStream.str() << "\n";
	std::cout << "\n******************** hpp *******************\n";
	std::cout << hppStream.str() << "\n";
}

void generate_test_2() {
	std::u32string contents = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", contents, {}, { "IDENTIFIER", "WS" });
	std::ofstream cppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\plc\\plange_grammar.cpp");
	std::ofstream hppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\plc\\plange_grammar.hpp");
	grammar.generate_cpp("plange", "STATEMENT_SCOPE", cppStream, hppStream);
}

void generate_test_3() {
	std::u32string associativityString = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\operator-associativity.txt"));
	std::map<std::string, parlex::associativity> associativities = parlex::load_associativities(associativityString);
	std::u32string grammarString = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn"));
	auto grammar = parlex::load_grammar("STATEMENT_SCOPE", grammarString, associativities, { "IDENTIFIER", "WS" });
	parlex::load_precedence(grammar, read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\operator-precedence.txt")));
	std::ofstream cppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\plc\\plange_grammar.cpp");
	std::ofstream hppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\plc\\plange_grammar.hpp");
	grammar.generate_cpp("plange", "STATEMENT_SCOPE", cppStream, hppStream);
}

//This code is destructive. Use with care.
/*void generate_associativity_parser() {
	std::u32string grammarString = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\associativity.wsn"));
	auto grammar = parlex::load_grammar("SYNTAX", grammarString, { "IDENTIFIER" });

	std::ofstream cppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\parlex\\src\\associativity_grammar.cpp");
	assert(cppStream);

	std::ofstream hppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\parlex\\include\\parlex\\builtins\\associativity_grammar.hpp");
	assert(hppStream);

	grammar.generate_cpp("associativity", "SYNTAX", cppStream, hppStream, "parlex/builtins/");
}*/

//This code is destructive. Use with care.
/*void generate_precedence_parser() {
	std::u32string grammarString = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\precedence.wsn"));
	auto grammar = parlex::load_grammar("SYNTAX", grammarString, { "IDENTIFIER" });

	std::ofstream cppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\parlex\\src\\precedence_grammar.cpp");
	assert(cppStream);

	std::ofstream hppStream("C:\\Users\\Brent\\Dropbox\\Plange\\source\\parlex\\include\\parlex\\builtins\\precedence_grammar.hpp");
	assert(hppStream);

	grammar.generate_cpp("precedence", "SYNTAX", cppStream, hppStream, "parlex/builtins/");
}*/

void precedence_test_1() {
	auto assocs = parlex::load_associativities(
		U"ADD:l\n"
		U"SUB:l\n"
		U"MUL:l\n"
		U"DIV:l\n"
		U"POW:r\n");
	parlex::grammar g = parlex::load_grammar("ADD",
		U"INTEGER = decimal_digit { decimal_digit }.\n"
		U"NEG = \"-\" EXP.\n"
		U"ADD = EXP \"+\" EXP.\n"
		U"SUB = EXP \"-\" EXP.\n"
		U"MUL = EXP \"*\" EXP.\n"
		U"DIV = EXP \"/\" EXP.\n"
		U"POW = EXP \"^\" EXP.\n"
		U"EXP = ADD | SUB | MUL | DIV | POW | NEG | INTEGER.\n"
		, assocs, { "INTEGER" });
	parlex::load_precedence(g,
		U"MUL:ADD\n"
		U"DIV:ADD\n"
		U"MUL:SUB\n"
		U"DIV:SUB\n"
		U"POW:ADD\n"
		U"POW:SUB\n"
		U"POW:MUL\n"
		U"POW:DIV\n"
		U"POW:NEG\n"
	);
}

void precedence_test_2() {
	auto assocs = parlex::load_associativities(
		U"ADD:l\n"
		U"SUB:l\n"
		U"MUL:l\n"
		U"DIV:l\n"
		U"POW:r\n");
	parlex::grammar g = parlex::load_grammar("EXP",
		U"INTEGER = decimal_digit { decimal_digit }.\n"
		U"NEG = \"-\" EXP.\n"
		U"ADD = EXP \"+\" EXP.\n"
		U"SUB = EXP \"-\" EXP.\n"
		U"MUL = EXP \"*\" EXP.\n"
		U"DIV = EXP \"/\" EXP.\n"
		U"POW = EXP \"^\" EXP.\n"
		U"EXP = ADD | SUB | MUL | DIV | POW | NEG | INTEGER.\n"
		, assocs, { "INTEGER" });
	parlex::load_precedence(g,
		U"MUL:ADD\n"
		U"DIV:ADD\n"
		U"MUL:SUB\n"
		U"DIV:SUB\n"
		U"POW:ADD\n"
		U"POW:SUB\n"
		U"POW:MUL\n"
		U"POW:DIV\n"
		U"POW:NEG\n"
	);
	parlex::parser p;
	auto asg = p.parse(g, U"3*5^7^9+2");
	auto check = asg.to_dot();
	assert(asg.is_rooted());
}


void precedence_test_10() {
	parlex::parser p;
	auto asg = p.parse(parlex::builtins::get_precedence_grammar(), read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\operator-precedence.txt")));
	auto check = asg.to_dot();
	assert(asg.is_rooted());
}

void precedence_test_11() {
}

void associativity_test_10() {
	parlex::parser p;
	std::u32string document = read_with_bom(std::ifstream("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\operator-associativity.txt"));
	auto asg = p.parse(parlex::builtins::get_precedence_grammar(), document);
	auto check = asg.to_dot();
	assert(asg.is_rooted());
}

int main(void) {

#define RUN_TEST(name) \
	std::cout << "********** " << #name << "           **********\n"; \
	name(); \
	std::cout << "********** " << #name << " completed **********\n";

	/*RUN_TEST(parser_test_1);
	RUN_TEST(parser_test_2);
	RUN_TEST(parser_test_3);
	RUN_TEST(parser_test_4);
	RUN_TEST(parser_test_5);
	RUN_TEST(parser_test_6);
	RUN_TEST(parser_test_7);
	RUN_TEST(parser_test_8);
	RUN_TEST(parser_test_9);
	RUN_TEST(parser_test_10);
	RUN_TEST(c_string_test_1);
	RUN_TEST(c_string_test_2);
	RUN_TEST(wirth_test_1);
	RUN_TEST(wirth_test_2);
	RUN_TEST(wirth_test_3);
	RUN_TEST(wirth_test_4);
	RUN_TEST(wirth_test_5);
	RUN_TEST(wirth_test_6);
	RUN_TEST(wirth_test_7);
	RUN_TEST(wirth_test_8);
	RUN_TEST(wirth_test_9);
	RUN_TEST(wirth_test_10);
	RUN_TEST(wirth_test_11);
	RUN_TEST(plange_test_1);
	RUN_TEST(plange_test_2);
	RUN_TEST(plange_test_3);
	RUN_TEST(plange_test_4);
	RUN_TEST(plange_test_5);
	RUN_TEST(plange_test_6);
	RUN_TEST(generate_test_1);
	RUN_TEST(generate_test_2);*/
	//RUN_TEST(generate_test_3);
	//RUN_TEST(generate_precedence_parser);
	//RUN_TEST(generate_associativity_parser);
	//RUN_TEST(precedence_test_1);
	RUN_TEST(precedence_test_2);
	//RUN_TEST(associativity_test_1);
}
