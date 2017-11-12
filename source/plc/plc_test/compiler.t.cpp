#include "compiler.hpp"
 
 #include <gtest/gtest.h>

#include "EXPRESSION.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "STATEMENT.hpp"
#include "MAPS_TO.hpp"
#include "MULTIPLICATION.hpp"

TEST(PlcCompiler, ParseTupleMapsToExpression) {
	auto result = plc::compiler::parse<plc::MAPS_TO>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsTo) {
	auto result = plc::compiler::parse<plc::MULTIPLICATION>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsToExpression) {
	auto result = plc::compiler::parse<plc::EXPRESSION>(U"a*b->c");
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
