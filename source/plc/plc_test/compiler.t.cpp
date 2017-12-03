#include "compiler.hpp"
 
 #include <gtest/gtest.h>

#include "EXPRESSION.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "STATEMENT.hpp"
#include "MAPS_TO.hpp"
#include "MULTIPLICATION.hpp"
#include "BINARY_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"

TEST(PlcCompiler, ParseTupleMapsToExpression) {
	auto result = plc::compiler::parse<plc::MAPS_TO>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsTo) {
	auto result = plc::compiler::parse<plc::MULTIPLICATION>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsToExpression) {
	plc::EXPRESSION result = plc::compiler::parse<plc::EXPRESSION>(U"a*b->c");
	ASSERT_TRUE(std::holds_alternative<erased<plc::BINARY_OP>>(result));
	plc::BINARY_OP const & binaryOp = *std::get<erased<plc::BINARY_OP>>(result);
	ASSERT_TRUE(std::holds_alternative<erased<plc::BINARY_LOGICAL_OP>>(binaryOp));
	plc::BINARY_LOGICAL_OP const & binaryLogicalOp = *std::get<erased<plc::BINARY_LOGICAL_OP>>(binaryOp);
	ASSERT_TRUE(std::holds_alternative<erased<plc::MAPS_TO>>(binaryLogicalOp));
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

TEST(PlcCompiler, ParseType) {
	auto source = U"myType := type {"
		"    public <Int> aVariable;"
		"};"
		"";
	auto result = plc::compiler::parse(source);
}

TEST(PlcCompiler, LoadSource) {
	auto source = U"print(\"Hello, world!\");";
	plc::source_code module("", source);
}