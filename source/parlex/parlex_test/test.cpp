#include <fstream>
#include <thread>
#include <codecvt>

#include "gtest/gtest.h"
#include "utf.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/parser.hpp"

#include "parlex/detail/wirth.hpp"
#include "parlex/detail/builtins.hpp"


using namespace parlex;
using namespace parlex::detail;

TEST(ParlexTest, smallest_test_0) {
	grammar const g(builder{
		"root", {
			production("root", literal(U"."))
		}
	});
	parser p(1);
	p.parse(g, U".").tree();
}

builder small_grammar_builder(
	"root",
	{
		production("root", sequence{reference("identifier"), literal(U".")}),
		production("identifier", sequence{reference("letter"), repetition(reference("letter"))})
	}
);

TEST(ParlexTest, small_test_0) {
	grammar const smallGrammar(small_grammar_builder);
	auto debugCheck = static_cast<state_machine const *>(&smallGrammar.get_recognizer(smallGrammar.lookup_recognizer_index("root")))->to_dot(smallGrammar.get_recognizers());
	parser p(1);
	auto result = p.parse(smallGrammar, U"A.");
}


TEST(ParlexTest, small_test_1) {
	grammar const smallGrammar(small_grammar_builder);
	parser p(1);
	auto result = p.parse(smallGrammar, U"AAAAAAAAAAAAAAAAAA.");
}

builder medium_grammar_builder(
	"root",
	{
		production("root", sequence {
			reference("identifier"),
			optional(reference("white_spaces")),
			literal(U"="),
			optional(reference("white_spaces")),
			reference("identifier"),
			literal(U".")
		}),
		production("identifier", sequence {
			reference("letter"),
			repetition(reference("letter"))
		}, associativity::NONE, longest()),
		production("white_spaces", sequence {
			reference("white_space"),
			repetition(reference("white_space"))
		}, associativity::NONE, longest())
	}
);

TEST(ParlexTest, medium_test_0) {
	grammar const smallGrammar(medium_grammar_builder);
	parser p(1);
	auto result = p.parse(smallGrammar, U"A=B.");
}

TEST(ParlexTest, medium_test_1) {
	grammar const smallGrammar(medium_grammar_builder);
	auto debugCheck = static_cast<state_machine const *>(&smallGrammar.get_recognizer(smallGrammar.lookup_recognizer_index("root")))->to_dot(smallGrammar.get_recognizers());
	parser p(1);
	auto result = p.parse(smallGrammar, U"AAAAAAAAAAA           =           BBBBBBBBBBBBB.");
}


TEST(ParlexTest, longest_filter_regression_test) {
	builder const b("production", {
		production("identifier",
			reference("letter"),
			associativity::NONE, longest()
		),

		production("production",
			sequence({
				reference("identifier"),
				literal(U"="),
				reference("identifier"),
			})
		)
	});
	grammar const g(b);
	parser p(1);
	auto result = p.parse(g, U"A=B");
	//auto debugTest = result.to_dot(wirth());
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

std::string wirth_in_itself = "\
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
	auto result = p.parse(wirth(), U"A=B.");
	//auto debugTest = result.to_dot(wirth());
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_1_5) {
	parser p(1);
	auto result = p.parse(wirth(), U"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=x.");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_2) {
	parser p(1);
	auto result = p.parse(wirth(), to_utf32(wirth_in_itself));
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3) {
	parser p;
	auto result = p.parse(wirth(), U"a=\"\\\\\".b=\"\".");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_3_1) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = {white_space} .", {}, {}, {});
}

TEST(ParlexTest, wirth_test_3_2) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = { {white_space} } .", {}, {}, {});
}

TEST(ParlexTest, wirth_test_3_5) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", U"EXPRESSION = { {white_space} \"|\" {white_space} } .", {}, {}, {});
}

TEST(ParlexTest, wirth_test_4) {
	parser p;
	auto grammar = wirth().load_grammar("SYNTAX", to_utf32(wirth_in_itself), {}, {}, {});
}

TEST(ParlexTest, wirth_test_5) {
	parser p;
	grammar const grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = \"a\".", {}, {}, {}));
	auto result = p.parse(grammar, U"b");
	if (result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_6) {
	parser p;
	grammar const grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter number.", {}, {}, {}));
	auto result = p.parse(grammar, U"a1");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_7) {
	parser p;
	grammar const grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter { number }.", {}, {}, {}));
	auto result = p.parse(grammar, U"a1234");
	EXPECT_TRUE(result.is_rooted());
}

TEST(ParlexTest, wirth_test_8) {
	parser p;
	grammar const grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter [ number ].", {}, {}, {}));
	auto result1 = p.parse(grammar, U"a");
	EXPECT_TRUE(result1.is_rooted());
	auto result2 = p.parse(grammar, U"a1");
	EXPECT_TRUE(result2.is_rooted());
}

TEST(ParlexTest, wirth_test_9) {
	parser p;
	grammar const grammar(wirth().load_grammar("SYNTAX", U"SYNTAX = letter ( number | c_string ).", {}, {}, {}));
	auto result1 = p.parse(grammar, U"a1");
	if (!result1.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	auto result2 = p.parse(grammar, U"a\"test\"");
	if (!result2.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_10) {
	parser p;
	grammar const grammar(wirth().load_grammar("ARRAY", U"\
ARRAY = \"[\" [EXPRESSION { \", \" EXPRESSION} ] \"]\".\
EXPRESSION = \"EXPRESSION\".", {}, {}, {}));
	auto result = p.parse(grammar, U"[]");
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
}

TEST(ParlexTest, wirth_test_11) {
	parser p;
	grammar grammar(wirth().load_grammar("STATEMENT_SCOPE", U"\
STATEMENT_SCOPE = {IC | STATEMENT}. \
IC = \"IC\".\
STATEMENT = \"STATEMENT\".", {}, {}, {}));
}

TEST(ParlexTest, wirth_test_12) {
	std::u32string const t = U"DIMENSIONAL_NUMBER | EMBEDDED_STRING";
	parser p(1);
	wirth().compile_expression(t);
}

TEST(ParlexTest, LeadingTagRegression) {
	std::u32string const t = U"$P";
	parser p(1);
	wirth().compile_expression(t);
}

TEST(ParlexTest, behavior_literal_wo_builtins) {
	builder const gBuilder("EXPR", {production("EXPR", literal(U"+"))});

	parser p(1);
	grammar const g(gBuilder, true);

	std::u32string const document = U"+";
	auto result = p.parse(g, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	//auto concreteDot = result.to_concrete_dot(document);
}

TEST(ParlexTest, behavior_literal_w_builtins) {
	builder const gBuilder("EXPR", {production("EXPR", literal(U"+"))});

	parser p(1);
	grammar const g(gBuilder);

	std::u32string const document = U"+";
	auto result = p.parse(g, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	//auto concreteDot = result.to_concrete_dot(document);
}

TEST(ParlexTest, behavior_sequence) {
	builder const gBuilder("EXPR", { production("EXPR", sequence({literal(U"+")})) });

	parser p(1);
	grammar const g(gBuilder);

	std::u32string const document = U"+";
	auto result = p.parse(g, document);
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	//auto concreteDot = result.to_concrete_dot(document);
}

TEST(ParlexTest, behavior_2) {
	builder const gBuilder("EXPR", {
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

	parser p(1);
	grammar const g(gBuilder);

	std::u32string const document = U"5+3*2";
	auto result = p.parse(g, document);
	//auto const debugTest = result.to_dot(g); // TODO: Remove debug code
	if (!result.is_rooted()) {
		throw std::logic_error("Test failed");
	}
	//auto concreteDot = result.to_concrete_dot(document);

}

TEST(ParlexTest, behavior_3) {
	builder const gBuilder("A", {
								   production("A", sequence({
												  optional(reference("white_space")),
												  reference("letter")
											  }))
	});

	parser p;
	grammar g(gBuilder);

}

TEST(ParlexTest, precedence_1) {
	builder const b("A", {
		production("A", 
			choice({
				reference("B"),
				reference("C")
			})
		),
		production("B", literal(U"x"), associativity::NONE, filter_function(), {"C"}),
		production("C", literal(U"x"))
	});
	grammar const g(b);
	parser p(1);
	auto result = p.parse(g, U"x").tree();	
}

TEST(ParlexTest, precedence_2) {
	builder const b("A", {
		production("A",
			sequence({
				literal(U"x"),
				optional(choice({
					sequence({ reference("A"), reference("A"),}),
					reference("B")
				}))
			})			
		),
		production("B", sequence({ literal(U"x"), reference("A")}), associativity::NONE, filter_function(),{"A"}),
	});
	grammar const g(b);
	parser p(1);
	auto result = p.parse(g, U"xxx").tree();
}
