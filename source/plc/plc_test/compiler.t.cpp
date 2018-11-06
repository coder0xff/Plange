﻿#include "compiler.hpp"

#include <experimental/filesystem>

#include "gtest/gtest.h"

#include "parlex/detail/parser.hpp"
#include "utf.hpp"

#include "grammar.hpp"
#include "module.hpp"
#include "plc_utils.hpp"


#ifdef _MSC_VER
#	define EXECUTABLE_EXTENSION ".exe"
#else
#	define EXECUTABLE_EXTENSION ""
#endif

static std::string const & stdlibs_dir() {
	static auto result = to_utf8(canonical(std::experimental::filesystem::path(__FILE__).remove_filename().append("/../../stdlib/"))) + std::string("/");
	return result;
}

static std::string const & examples_dir() {
	static auto result = to_utf8(canonical(std::experimental::filesystem::path(__FILE__).remove_filename().append("/../../../examples/"))) + std::string("/");
	return result;
}

TEST(PlcCompiler, ParseTupleMapsToExpression) {
	auto result = plc::compiler::parse<plc::MAPS_TO>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsTo) {
	auto result = plc::compiler::parse<plc::MULTIPLICATION>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsToExpression) {
	auto result = plc::compiler::parse<plc::EXPRESSION>(U"a*b->c");
	ASSERT_TRUE(std::holds_alternative<val<plc::BINARY_OP>>(result));
	plc::BINARY_OP const & binaryOp = *std::get<val<plc::BINARY_OP>>(result);
	ASSERT_TRUE(std::holds_alternative<val<plc::BINARY_LOGICAL_OP>>(binaryOp));
	plc::BINARY_LOGICAL_OP const & binaryLogicalOp = *std::get<val<plc::BINARY_LOGICAL_OP>>(binaryOp);
	ASSERT_TRUE(std::holds_alternative<val<plc::MAPS_TO>>(binaryLogicalOp));
}

TEST(PlcCompiler, ParseTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"<a> b");
}

TEST(PlcCompiler, ParseBinaryFunctionTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"<a * b -> c> d");
}

TEST(PlcCompiler, ParseExternBinaryFunctionTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"extern <a * b -> c> d");
}
 
TEST(PlcCompiler, ParseExternBinaryFunctionTypeConstraintStatement) {
	auto result = plc::compiler::parse<plc::STATEMENT>(U"extern <a * b -> c> d;");
}

TEST(PlcCompiler, ParseCompound) {
	auto result = plc::compiler::parse<plc::EXPRESSION>(U"a|b|c");
}

TEST(PlcCompiler, ParseHelloWorld) {
	auto result = plc::compiler::parse(U"print(\"Hello, world!\");");
}

TEST(PlcCompiler, ParseDefinition) {
	auto result = plc::compiler::parse(U"x:=1;");
}

TEST(PlcCompiler, ParseType) {
	auto const source = U"myType := type {"
		"    public <Int> aVariable;"
		"};"
		"";
	auto result = plc::compiler::parse(source);
}

TEST(PlcCompiler, ParseFILEPointer) {
	auto const source = U"FILEPointer := type_abstraction(Pointer<Void>);\n";
	auto result = plc::compiler::parse(source);
}

TEST(PlcCompiler, ParseInvocation) {
	auto const source = U"x()";
	plc::source_code::parse<plc::INVOCATION>(source);
}

TEST(PlcCompiler, ParentheticalInvocation) {
	auto const source = U"()";
	plc::source_code::parse<plc::PARENTHETICAL_INVOCATION>(source);
}

TEST(PlcCompiler, ParseIdentifier) {
	auto const source = U"x";
	plc::source_code::parse<plc::IDENTIFIER>(source);
}

TEST(PlcCompiler, ParsePrintHelloWorld) {
	auto const source = U"print(\"Hello, world!\");";
	plc::source_code("", source);
}

TEST(PlcCompiler, ParseType2) {
	auto const source = U"<Type> Div_t := type { <CInt> quot; <CInt> rem; };";
	plc::source_code("", source);
}

TEST(PlcCompiler, ParseAddAssign) {
	auto const source = U"x<-a+b;";
	plc::source_code("", source);
}

TEST(PlcCompiler, ParseAddAssign2) {
	auto const source = U"x←a+b;";
	parlex::detail::parser p(1);
	auto assl = p.parse(plc::plange_grammar::get(), source);
	ASSERT_TRUE(assl.is_rooted());
	ASSERT_TRUE(assl.variation_count() == 1);
	auto ast = assl.tree();
}

TEST(PlcCompiler, ParseTypeWithMemberOffset) {
	auto const source = U"type {<a>b@0;};";
	parlex::detail::parser p(1);
	auto assl = p.parse(plc::plange_grammar::get(), source);
	ASSERT_TRUE(assl.is_rooted());
	ASSERT_TRUE(assl.variation_count() == 1);
	auto ast = assl.tree();
}

TEST(PlcCompiler, ParseCStdLibGenerated) {
	auto const filePathname = stdlibs_dir() + "Plange.CStdLib.Generated._pg";
	static parlex::detail::parser p;
	auto const document = plc::read_utf_file(filePathname);
	auto assl = p.parse(plc::plange_grammar::get(), document);
	ASSERT_TRUE(assl.is_rooted());
	ASSERT_TRUE(assl.variation_count() == 1);
	auto ast = assl.tree();
}

TEST(PlcCompiler, LoadCStdLibGenerated) {
	auto const filePathname = stdlibs_dir() + "Plange.CStdLib.Generated._pg";
	auto result = plc::source_code(filePathname);
}

TEST(PlcCompiler, LoadCStdLib) {
	auto const filePathname = stdlibs_dir() + "Plange.CStdLib._pg";
	auto result = plc::source_code(filePathname);
}

static void parse_example(std::string const & exampleName) {
	auto const filePathname = examples_dir() + exampleName;
	static parlex::detail::parser p;
	auto assl = p.parse(plc::plange_grammar::get(), plc::read_utf_file(filePathname));
	ASSERT_TRUE(assl.is_rooted());
	ASSERT_TRUE(assl.variation_count() == 1);
	auto ast = assl.tree();
}

static void load_example(std::string const & exampleName) {
	auto const filePathname = examples_dir() + exampleName;
	auto result = plc::source_code(filePathname);
}

TEST(PlcCompiler, ParseEmbeddedCommentExample) {
	parse_example("embeddedComment.pge");
}

TEST(PlcCompiler, LoadEmbeddedCommentExample) {
	load_example("embeddedComment.pge");
}

TEST(PlcCompiler, ParseEmbeddedCommentExample2) {
	parse_example("embeddedComment2.pge");
}

TEST(PlcCompiler, LoadEmbeddedCommentExample2) {
	load_example("embeddedComment2.pge");
}

TEST(PlcCompiler, LoadIntToStringExample) {
	load_example("intToString.pge");
}

// This test is excessive, and takes a long time to complete. Only turn it on when you want that.
//TEST(PlcCompiler, ParseIntToStringStressTestExample) {
//	perf_timer perf(__func__);
//
//	parse_example("intToStringStressTest.pge");
//}

static void run_example(std::string const & exampleName, std::string const & expectedOutput) {
	auto const tempDir = to_utf8(canonical(std::experimental::filesystem::temp_directory_path()));
	auto const outputFilename = tempDir + "/" + exampleName + EXECUTABLE_EXTENSION;
	plc::compiler::build(outputFilename, { examples_dir() + exampleName });
	auto const result = exec(outputFilename);
	ASSERT_EQ(0, result.second);
	ASSERT_EQ(expectedOutput, result.first);
	std::experimental::filesystem::remove(outputFilename);
}

TEST(PlcCompiler, PutsHelloWorld) {
	run_example("putsHelloWorld.pge", "Hello, world!");
}