#include <iostream>
#include <cassert>

#include "builtins.hpp"
#include "state_machine.hpp"
#include "parser.hpp"
#include "abstract_syntax_graph.hpp"

void parser_test_1() {
	std::cout << "************ parser_test_1 ************" << std::endl;
	parlex::state_machine s("machine", 1);
	s.add_transition(0, parlex::builtins::any_character, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, U"a");
	std::cout << result.to_dot() << std::endl;
}


void parser_test_2() {
	std::cout << "************ parser_test_2 ************" << std::endl;
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal helloWorld(U"Hello, world!");
	s.add_transition(0, helloWorld, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, U"Hello, world!");
	std::cout << result.to_dot() << std::endl;
}

void parser_test_3() {
	std::cout << "************ parser_test_3 ************" << std::endl;
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal foo(U"Foo");
	s.add_transition(0, foo, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, U"bar");
	std::cout << result.to_dot() << std::endl;
}

void parser_test_4() {
	std::cout << "************ parser_test_4 ************" << std::endl;
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal hello(U"Hello");
	parlex::builtins::string_terminal world(U", world");
	s.add_transition(0, hello, 1);
	s.add_transition(1, world, 2);
	s.add_transition(2, parlex::builtins::any_character, 3);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, U"Hello, world!");
	std::cout << result.to_dot() << std::endl;
}

void parser_test_5() {
	std::cout << "************ parser_test_5 ************" << std::endl;
	parlex::state_machine s("num", 1);
	s.add_transition(0, parlex::builtins::decimal_digit, 1);
	s.add_transition(1, parlex::builtins::decimal_digit, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, U"982874599127");
	std::cout << result.to_dot() << std::endl;
}

void parser_test_6() {
	std::cout << "************ parser_test_6 ************" << std::endl;
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine csv("csv", 1);
	parlex::builtins::string_terminal comma(U",");
	csv.add_transition(0, num, 1);
	csv.add_transition(1, comma, 0);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(csv, U"1,2");
	std::cout << result.to_dot() << std::endl;
}

void parser_test_7() {
	std::cout << "************ parser_test_7 ************" << std::endl;
	parlex::state_machine ncsv("ncsv", 1);

	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(U"(");
	parlex::builtins::string_terminal close_paren(U")");
	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, ncsv, 2);
	paren.add_transition(2, close_paren, 3);

	ncsv.add_transition(0, num, 2);
	ncsv.add_transition(0, paren, 2);
	parlex::builtins::string_terminal comma(U",");
	ncsv.add_transition(2, comma, 1);
	ncsv.add_transition(1, num, 2);
	ncsv.add_transition(1, paren, 2);

	for (int i = 0; i < 1000; i++) {
		parlex::parser p(1);
		parlex::abstract_syntax_graph result = p.parse(ncsv, U"12,(34,56),789");
		std::string dot = result.to_dot();
		std::cout << dot << std::endl;
		std::cout << "checking iteration " << i << std::endl;
		assert(dot.length() > 100);
	}
}

//direct left recursion
void parser_test_8() {
	std::cout << "************ parser_test_8 ************" << std::endl;
	parlex::state_machine expr("expr", 1);

	parlex::state_machine factorial("factorial", 1);
	parlex::builtins::string_terminal bang(U"!");
	factorial.add_transition(0, expr, 1);
	factorial.add_transition(1, bang, 2);

	expr.add_transition(0, parlex::builtins::decimal_digit, 1);
	expr.add_transition(0, factorial, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(expr, U"1!");
	std::cout << result.to_dot() << std::endl;
}

//left recursion
void parser_test_100() {
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine expr("expr", 1);

	parlex::state_machine add("add", 1);
	parlex::builtins::string_terminal plus(U"+");
	add.add_transition(0, expr, 1);
	add.add_transition(1, plus, 2);
	add.add_transition(2, expr, 3);

	parlex::state_machine sub("sub", 1);
	parlex::builtins::string_terminal minus(U"-");
	sub.add_transition(0, expr, 1);
	sub.add_transition(1, minus, 2);
	sub.add_transition(2, expr, 3);

	parlex::state_machine mul("mul", 1);
	parlex::builtins::string_terminal asterisk(U"*");
	mul.add_transition(0, expr, 1);
	mul.add_transition(1, asterisk, 2);
	mul.add_transition(2, expr, 3);

	parlex::state_machine div("div", 1);
	parlex::builtins::string_terminal slash(U"/");
	div.add_transition(0, expr, 1);
	div.add_transition(1, slash, 2);
	div.add_transition(2, expr, 3);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(U"(");
	parlex::builtins::string_terminal close_paren(U")");
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
	parlex::abstract_syntax_graph result = p.parse(expr, U"1+2");
	std::cout << result.to_dot() << std::endl;
}


int main(void) {
	/*parser_test_1();
	parser_test_2();
	parser_test_3();
	parser_test_4();
	parser_test_5();*/
	parser_test_6();
	//parser_test_7();
	//parser_test_8();
}