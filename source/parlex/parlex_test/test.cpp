#include <fstream>
#include <thread>
#include <codecvt>

#include "gtest/gtest.h"
#include "utf.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/raw_grammar.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/parser.hpp"

#include "parlex/detail/string_terminal.hpp"

#include "parlex/detail/builtins.hpp"
#include "parlex/detail/wirth.hpp"


using namespace parlex;
using namespace parlex::detail;

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
	abstract_syntax_semilattice result = p.parse(wirth(), U"a=x.");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_2) {
	parser p;
	abstract_syntax_semilattice result = p.parse(wirth(), to_utf32(wirthInItself));
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3) {
	parser p;
	abstract_syntax_semilattice result = p.parse(wirth(), U"a=\"\\\\\".b=\"\".");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3_1) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = {white_space} .", {}, {});
}

TEST(ParlexTest, wirth_test_3_2) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = { {white_space} } .", {}, {});
}

TEST(ParlexTest, wirth_test_3_5) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = { {white_space} \"|\" {white_space} } .", {}, {});
}

TEST(ParlexTest, wirth_test_4) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", to_utf32(wirthInItself), {}, {});
}

TEST(ParlexTest, wirth_test_5) {
	parser p;
	grammar grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {}));
	abstract_syntax_semilattice result = p.parse(grammar, U"b");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_6) {
	parser p;
	grammar grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {}));
	abstract_syntax_semilattice result = p.parse(grammar, U"a1");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_7) {
	parser p;
	grammar grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {}));
	abstract_syntax_semilattice result = p.parse(grammar, U"a1234");
	EXPECT_TRUE(result.is_rooted());
}

TEST(ParlexTest, wirth_test_8) {
	parser p;
	grammar grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {}));
	abstract_syntax_semilattice result1 = p.parse(grammar, U"a");
	EXPECT_TRUE(result1.is_rooted());
	abstract_syntax_semilattice result2 = p.parse(grammar, U"a1");
	EXPECT_TRUE(result2.is_rooted());
}

TEST(ParlexTest, wirth_test_9) {
	parser p;
	grammar grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {}));
	abstract_syntax_semilattice result1 = p.parse(grammar, U"a1");
	if (!result1.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	abstract_syntax_semilattice result2 = p.parse(grammar, U"a\"test\"");
	if (!result2.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_10) {
	parser p;
	grammar grammar(wirth().load_grammar("ARRAY", U"\
ARRAY = \"[\" [EXPRESSION { \", \" EXPRESSION} ] \"]\".\
EXPRESSION = \"EXPRESSION\".", {}, {}));
	abstract_syntax_semilattice result = p.parse(grammar, U"[]");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_11) {
	parser p;
	grammar grammar(wirth().load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {}));
}

TEST(ParlexTest, wirth_test_12) {
	std::u32string t = U"DIMENSIONAL_NUMBER | EMBEDDED_STRING";
	parser p(1);
	wirth().compile_expression(t);
}

TEST(ParlexTest, behavior_1) {
	builder g_builder("EXPR", {
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
	grammar g(g_builder);

	std::u32string document = U"5+3*2";
	abstract_syntax_semilattice result = p.parse(g, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	std::string concreteDot = result.to_concrete_dot(document);

}

TEST(ParlexTest, behavior_2) {
	builder g_builder("A", {
								   production("A", sequence({
												  optional(reference("white_space")),
												  reference("letter")
											  }))
	});

	parser p;
	grammar g(g_builder);

}

