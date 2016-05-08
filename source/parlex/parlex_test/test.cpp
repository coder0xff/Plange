#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <codecvt>

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/builtins.hpp"
#include "parlex/details/logging.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/utils.hpp"

void parser_test_1() {
	DBG("************ parser_test_1 ************");
	parlex::state_machine s("machine", 1);
	s.add_transition(0, parlex::builtins::any_character, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, to_utf32("a"));
	DBG(result.to_dot());
}

void parser_test_2() {
	DBG("************ parser_test_2 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal helloWorld(to_utf32("Hello, world!"));
	s.add_transition(0, helloWorld, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, to_utf32("Hello, world!"));
	DBG(result.to_dot());
}

void parser_test_3() {
	DBG("************ parser_test_3 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal foo(to_utf32("Foo"));
	s.add_transition(0, foo, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, to_utf32("bar"));
	DBG(result.to_dot());
}

void parser_test_4() {
	DBG("************ parser_test_4 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal hello(to_utf32("Hello"));
	parlex::builtins::string_terminal world(to_utf32(", world"));
	s.add_transition(0, hello, 1);
	s.add_transition(1, world, 2);
	s.add_transition(2, parlex::builtins::any_character, 3);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, to_utf32("Hello, world!"));
	DBG(result.to_dot());
}

void parser_test_5() {
	DBG("************ parser_test_5 ************");
	parlex::state_machine s("num", 1);
	s.add_transition(0, parlex::builtins::decimal_digit, 1);
	s.add_transition(1, parlex::builtins::decimal_digit, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, to_utf32("982874599127"));
	DBG(result.to_dot());
}

void parser_test_6() {
	DBG("************ parser_test_6 ************");
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine csv("csv", 1);
	parlex::builtins::string_terminal comma(to_utf32(","));
	csv.add_transition(0, num, 1);
	csv.add_transition(1, comma, 0);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(csv, to_utf32("1,2"));
	DBG(result.to_dot());
}

void parser_test_7() {
	DBG("************ parser_test_7 ************");
	parlex::state_machine nested_csv("nested_csv", 1);

	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(to_utf32("("));
	parlex::builtins::string_terminal close_paren(to_utf32(")"));
	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, nested_csv, 2);
	paren.add_transition(2, close_paren, 3);

	nested_csv.add_transition(0, num, 2);
	nested_csv.add_transition(0, paren, 2);
	parlex::builtins::string_terminal comma(to_utf32(","));
	nested_csv.add_transition(2, comma, 1);
	nested_csv.add_transition(1, num, 2);
	nested_csv.add_transition(1, paren, 2);

	for (int i = 0; i < 10; i++) {
		parlex::parser p(1);
		parlex::abstract_syntax_graph result = p.parse(nested_csv, to_utf32("12,(34,56),789"));
		std::string dot = result.to_dot();
		DBG(dot);
		assert(dot.length() > 100);
	}
}

//direct left recursion
void parser_test_8() {
	DBG("************ parser_test_8 ************");
	parlex::state_machine expr("expr", 1);

	parlex::state_machine factorial("factorial", 1);
	parlex::builtins::string_terminal bang(to_utf32("!"));
	factorial.add_transition(0, expr, 1);
	factorial.add_transition(1, bang, 2);

	expr.add_transition(0, parlex::builtins::decimal_digit, 1);
	expr.add_transition(0, factorial, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(expr, to_utf32("1!"));
	DBG(result.to_dot());
}

//indirect left recursion
void parser_test_9() {
	DBG("************ parser_test_9 ************");
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine expr("expr", 1);

	parlex::state_machine add("add", 1);
	parlex::builtins::string_terminal plus(to_utf32("+"));
	add.add_transition(0, expr, 1);
	add.add_transition(1, plus, 2);
	add.add_transition(2, expr, 3);

	parlex::state_machine sub("sub", 1);
	parlex::builtins::string_terminal minus(to_utf32("-"));
	sub.add_transition(0, expr, 1);
	sub.add_transition(1, minus, 2);
	sub.add_transition(2, expr, 3);

	parlex::state_machine mul("mul", 1);
	parlex::builtins::string_terminal asterisk(to_utf32("*"));
	mul.add_transition(0, expr, 1);
	mul.add_transition(1, asterisk, 2);
	mul.add_transition(2, expr, 3);

	parlex::state_machine div("div", 1);
	parlex::builtins::string_terminal slash(to_utf32("/"));
	div.add_transition(0, expr, 1);
	div.add_transition(1, slash, 2);
	div.add_transition(2, expr, 3);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(to_utf32("("));
	parlex::builtins::string_terminal close_paren(to_utf32(")"));
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
	parlex::abstract_syntax_graph result = p.parse(expr, to_utf32("1-2-3-4"));
	DBG(result.to_dot());
}

void parser_test_10() {
	DBG("************ parser_test_10 ************");
	parlex::state_machine identifier("identifier", 1);
	identifier.add_transition(0, parlex::builtins::letter, 1);
	parlex::builtins::string_terminal underscore(to_utf32("_"));
	identifier.add_transition(0, underscore, 1);
	identifier.add_transition(1, parlex::builtins::letter, 1);
	identifier.add_transition(1, underscore, 1);
	identifier.add_transition(1, parlex::builtins::number, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(identifier, to_utf32("hi"));
	DBG(result.to_dot());
}

void c_string_test_1() {
    std::u32string const input = to_utf32("\"abc123\\\"\""); //unescaped: "abc123\""
    parlex::parser p(1);
    parlex::abstract_syntax_graph result = p.parse(parlex::builtins::c_string, input);
    DBG(result.to_dot());
}

void c_string_test_2() {
	std::u32string const input = to_utf32("\"\\\\\""); // unescaped: "\\"
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::c_string, input);
	DBG(result.to_dot());
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
	DBG(result.to_dot());
}

void wirth_test_2() {
    parlex::parser p;
    parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, to_utf32(wirthInItself));
    DBG(result.to_dot());
}

void wirth_test_3() {
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, U"a=\"\\\\\".b=\"\".");
	std::string dot = result.to_dot();
}

void wirth_test_4() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", to_utf32(wirthInItself), {});
}

void wirth_test_5() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", U"SYNTAX = \"a\".", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), U"b");
	std::string dot = result.to_dot();
}

void wirth_test_6() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", U"SYNTAX = letter number.", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), U"a1");
	std::string dot = result.to_dot();
}

void wirth_test_7() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", U"SYNTAX = letter { number }.", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), U"a1234");
	std::string dot = result.to_dot();
}

void wirth_test_8() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", U"SYNTAX = letter [ number ].", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar.get_main_production(), U"a");
	std::string dot1 = result1.to_dot();
	parlex::abstract_syntax_graph result2 = p.parse(grammar.get_main_production(), U"a1");
	std::string dot2 = result2.to_dot();
}

void wirth_test_9() {
	auto grammar = parlex::builtins::parse_wirth("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result1 = p.parse(grammar.get_main_production(), U"a1");
	std::string dot1 = result1.to_dot();
	parlex::abstract_syntax_graph result2 = p.parse(grammar.get_main_production(), U"a\"test\"");
	std::string dot2 = result2.to_dot();
}

void wirth_test_10() {
	auto grammar = parlex::builtins::parse_wirth("ARRAY", U"\
ARRAY = \"[\" {IC} [EXPRESSION {{IC} \", \" {IC} EXPRESSION} {IC} ] \"]\".\
IC = \"IC\".\
EXPRESSION = \"EXPRESSION\".", {});
	parlex::parser p;
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), U"[]");
	std::string dot = result.to_dot();
}

void wirth_test_11() {
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {});
}

void plange_test_1() {
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(parlex::builtins::wirth, to_utf32(buffer.str()));
	std::string dot = result.to_dot();
}

void plange_test_2() {
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });
}

void plange_test_3() {
	//load Plange grammar
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });

	//try parsing a simple program
	parlex::parser p(1);
	std::u32string input = U"print(\"Hello, world!\");";
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), input);
	std::string dot = result.to_dot();
}

void plange_test_4() {
	//load Plange grammar
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });

	std::ifstream u("C:\\Users\\Brent\\Dropbox\\Plange\\source\\Examples\\intToString.pge");
	std::string str((std::istreambuf_iterator<char>(u)),
		std::istreambuf_iterator<char>());

	parlex::parser p;
	std::u32string input = to_utf32(str);
	parlex::abstract_syntax_graph result = p.parse(grammar.get_main_production(), input);
	std::string dot = result.to_dot();
}

void plange_test_5() {
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });

	parlex::parser p;

	std::ifstream u("C:\\Users\\Brent\\Dropbox\\Plange\\source\\Examples\\intToString.pge");
	std::string str((std::istreambuf_iterator<char>(u)),
		std::istreambuf_iterator<char>());

	std::u32string input1 = to_utf32(str + str);
	parlex::abstract_syntax_graph result1 = p.parse(grammar.get_main_production(), input1);

	std::u32string input2 = to_utf32(str + str + str);
	parlex::abstract_syntax_graph result2 = p.parse(grammar.get_main_production(), input2);

	std::u32string input3 = to_utf32(str + str + str + str);
	parlex::abstract_syntax_graph result3 = p.parse(grammar.get_main_production(), input3);
}

void plange_test_6() {
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });

	parlex::parser p;

	std::u32string input1 = U"1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;";
	parlex::abstract_syntax_graph result1 = p.parse(grammar.get_main_production(), input1);

	std::u32string input2 = U"1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;\n1+2+3;";
	parlex::abstract_syntax_graph result2 = p.parse(grammar.get_main_production(), input2);
}

void generate_test_1() {
	std::ifstream t("C:\\Users\\Brent\\Dropbox\\Plange\\documentation\\syntax.wsn");
	std::stringstream buffer;
	t.seekg(3);
	buffer << t.rdbuf();
	auto grammar = parlex::builtins::parse_wirth("STATEMENT_SCOPE", to_utf32(buffer.str()), { "IDENTIFIER", "WS" });
	std::ostringstream cppStream, hppStream;
	grammar.generate_cpp("plange", cppStream, hppStream);
	std::cout << "\n******************** cpp *******************\n";
	std::cout << cppStream.str() << "\n";
	std::cout << "\n******************** hpp *******************\n";
	std::cout << hppStream.str() << "\n";
}

int main(void) {
	/*parser_test_1();
	parser_test_2();
	parser_test_3();
	parser_test_4();
	parser_test_5();
	parser_test_6();
	parser_test_7();
	parser_test_8();
	parser_test_9();
	parser_test_10();
	c_string_test_1();
	c_string_test_2();
	wirth_test_1();
	wirth_test_2();
	wirth_test_3();
	wirth_test_4();
	wirth_test_5();
	wirth_test_6();
	wirth_test_7();
	wirth_test_8();
	wirth_test_9();
	wirth_test_10();
	wirth_test_11();
	plange_test_1();
	plange_test_2();
	plange_test_3();
	plange_test_4();
	plange_test_5();
	plange_test_6();*/
	generate_test_1();
}
