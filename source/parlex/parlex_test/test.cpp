#include <cassert>

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/builtins.hpp"
#include "parlex/details/logging.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/unicode.hpp"

void parser_test_1() {
	DBG("************ parser_test_1 ************");
	parlex::state_machine s("machine", 1);
	s.add_transition(0, parlex::builtins::any_character, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, uni_grow("a"));
	DBG(result.to_dot());
}


void parser_test_2() {
	DBG("************ parser_test_2 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal helloWorld(uni_grow("Hello, world!"));
	s.add_transition(0, helloWorld, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, uni_grow("Hello, world!"));
	DBG(result.to_dot());
}

void parser_test_3() {
	DBG("************ parser_test_3 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal foo(uni_grow("Foo"));
	s.add_transition(0, foo, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, uni_grow("bar"));
	DBG(result.to_dot());
}

void parser_test_4() {
	DBG("************ parser_test_4 ************");
	parlex::state_machine s("machine", 1);
	parlex::builtins::string_terminal hello(uni_grow("Hello"));
	parlex::builtins::string_terminal world(uni_grow(", world"));
	s.add_transition(0, hello, 1);
	s.add_transition(1, world, 2);
	s.add_transition(2, parlex::builtins::any_character, 3);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, uni_grow("Hello, world!"));
	DBG(result.to_dot());
}

void parser_test_5() {
	DBG("************ parser_test_5 ************");
	parlex::state_machine s("num", 1);
	s.add_transition(0, parlex::builtins::decimal_digit, 1);
	s.add_transition(1, parlex::builtins::decimal_digit, 1);
	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(s, uni_grow("982874599127"));
	DBG(result.to_dot());
}

void parser_test_6() {
	DBG("************ parser_test_6 ************");
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine csv("csv", 1);
	parlex::builtins::string_terminal comma(uni_grow(","));
	csv.add_transition(0, num, 1);
	csv.add_transition(1, comma, 0);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(csv, uni_grow("1,2"));
	DBG(result.to_dot());
}

void parser_test_7() {
	DBG("************ parser_test_7 ************");
	parlex::state_machine nested_csv("nested_csv", 1);

	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(uni_grow("("));
	parlex::builtins::string_terminal close_paren(uni_grow(")"));
	paren.add_transition(0, open_paren, 1);
	paren.add_transition(1, nested_csv, 2);
	paren.add_transition(2, close_paren, 3);

	nested_csv.add_transition(0, num, 2);
	nested_csv.add_transition(0, paren, 2);
	parlex::builtins::string_terminal comma(uni_grow(","));
	nested_csv.add_transition(2, comma, 1);
	nested_csv.add_transition(1, num, 2);
	nested_csv.add_transition(1, paren, 2);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(nested_csv, uni_grow("12,(34,56),789"));
	std::string dot = result.to_dot();
	DBG(dot);
	assert(dot.length() > 100);
}

//direct left recursion
void parser_test_8() {
	DBG("************ parser_test_8 ************");
	parlex::state_machine expr("expr", 1);

	parlex::state_machine factorial("factorial", 1);
	parlex::builtins::string_terminal bang(uni_grow("!"));
	factorial.add_transition(0, expr, 1);
	factorial.add_transition(1, bang, 2);

	expr.add_transition(0, parlex::builtins::decimal_digit, 1);
	expr.add_transition(0, factorial, 1);

	parlex::parser p(1);
	parlex::abstract_syntax_graph result = p.parse(expr, uni_grow("1!"));
	DBG(result.to_dot());
}

//indirect left recursion
void parser_test_100() {
	parlex::state_machine num("num", 1);
	num.add_transition(0, parlex::builtins::decimal_digit, 1);
	num.add_transition(1, parlex::builtins::decimal_digit, 1);

	parlex::state_machine expr("expr", 1);

	parlex::state_machine add("add", 1);
	parlex::builtins::string_terminal plus(uni_grow("+"));
	add.add_transition(0, expr, 1);
	add.add_transition(1, plus, 2);
	add.add_transition(2, expr, 3);

	parlex::state_machine sub("sub", 1);
	parlex::builtins::string_terminal minus(uni_grow("-"));
	sub.add_transition(0, expr, 1);
	sub.add_transition(1, minus, 2);
	sub.add_transition(2, expr, 3);

	parlex::state_machine mul("mul", 1);
	parlex::builtins::string_terminal asterisk(uni_grow("*"));
	mul.add_transition(0, expr, 1);
	mul.add_transition(1, asterisk, 2);
	mul.add_transition(2, expr, 3);

	parlex::state_machine div("div", 1);
	parlex::builtins::string_terminal slash(uni_grow("/"));
	div.add_transition(0, expr, 1);
	div.add_transition(1, slash, 2);
	div.add_transition(2, expr, 3);

	parlex::state_machine paren("paren", 1);
	parlex::builtins::string_terminal open_paren(uni_grow("("));
	parlex::builtins::string_terminal close_paren(uni_grow(")"));
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
	parlex::abstract_syntax_graph result = p.parse(expr, uni_grow("1+2"));
	DBG(result.to_dot());
}


int main(void) {
	parser_test_1();
	parser_test_2();
	parser_test_3();
	parser_test_4();
	parser_test_5();
	parser_test_6();
	parser_test_7();
	parser_test_8();
}