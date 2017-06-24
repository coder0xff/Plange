#include "compiler.hpp"

#pragma warning(push, 0)
#include <llvm/IR/IRBuilder.h>
#pragma warning(pop)

#include "document.hpp"
#include "errors.hpp"
#include "natural_value.hpp"
#include "utils.hpp"
#include "symbol.hpp"
#include "scope.hpp"
#include "stdafx.hpp"
#include "utf.hpp"

namespace plc {

// std::string describe_code_span(source_code const& source, parlex::details::match const& m) {
// 	std::string result = source.pathname == "" ? "[generated]" : source.pathname;
// 	result += ":";
// 	std::pair<int, int>
// 		start = source.get_line_number_and_column(m.document_position),
// 		end = source.get_line_number_and_column(m.document_position + m.consumed_character_count - 1);
// 	result += std::to_string(start.first) + ":" + std::to_string(start.second) + "-";
// 	if (end.first == start.first) {
// 		result += std::to_string(end.second);
// 	} else {
// 		result += std::to_string(end.first) + ":" + std::to_string(end.second);
// 	}
// 	return result;
// }

std::shared_ptr<analytic_value> do_concrete_invoke(llvm::Function * function, std::vector<llvm::Value *> arguments, scope& parent, llvm::BasicBlock * unwindDest, llvm::IRBuilder<> & builder) {
	ERROR(NotImplemented, "");
	/*auto nextBlock = llvm::BasicBlock::Create(llvmContext, "", &parent.getLLVMFunction(), nullptr);
	auto result = std::static_pointer_cast<analytic_value>(std::make_shared<concrete_value>(builder.CreateInvoke(function, nextBlock, unwindDest, arguments, "")));
	builder.SetInsertPoint(nextBlock);
	return result;*/
}

std::shared_ptr<analytic_value> eval_expression(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder);

std::shared_ptr<analytic_value> eval_parenthetical_invocation(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
	ERROR(NotImplemented, "");
/*
	std::vector<llvm::Value *> arguments;
	auto func = eval_expression(source, source.get_parts(parts[0]), parent, unwindDest, builder)->try_concretion();
	if (!func) {
		ERROR(NotImplemented, describe_code_span(source, parts[0]) + "Non-concrete function invocations are not implemented.");
	}
	auto llvmFunc = dynamic_cast<llvm::Function *>(func->underlying.get());
	if (!llvmFunc) {
		ERROR(ExpressionIsNotAFunction, source.pathname + describe_code_span(source, parts[0]));
	}

	for (size_t i = 1; i < parts.size(); ++i) { //0 is the function to invoke
		if (parts[i].r.id == "EXPRESSION") {
			auto argument = eval_expression(source, source.get_parts(parts[i]), parent, unwindDest, builder)->try_concretion();
			if (!argument) {
				ERROR(UnsupportedBootstrapFunctionality, "non-concrete function arguments are not available");
			}
			arguments.push_back(argument->underlying.get());
		}
	}
	return do_concrete_invoke(llvmFunc, arguments, parent, &unwindDest, builder);*/
}

// std::shared_ptr<analytic_value> eval_invocation(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	auto expressionType = &parts[0].r;
// 	if (expressionType == &PARENTHETICAL_INVOCATION) {
// 		return eval_parenthetical_invocation(source, source.get_parts(parts[0]), parent, unwindDest, builder);
// 	}
// 	ERROR(NotImplemented, "");
// }
// 
// std::shared_ptr<analytic_value> eval_identifier(const source_code& source, const std::u32string& name, const scope& parent, const llvm::BasicBlock & unwindDest, const llvm::IRBuilder<>& builder) {
// 	auto i = parent.symbols.find(name);
// 	if (i == parent.symbols.end()) {
// 		ERROR(UnknownSymbol, to_utf8(name));
// 	}
// 	return i->second.value;
// }
// 
// std::shared_ptr<analytic_value> eval_expression(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	auto expressionType = &parts[0].r;
// 
// 	if (expressionType == &ALLOCATION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &ARRAY) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &ASM_FUNCTION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &BINARY_OP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &BOOL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CAST) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CEILING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &COMPLEMENT) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CONDITIONAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &DELTA) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &DIMENSIONAL_NUMBER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &EMBEDDED_STRING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &EQUALITY_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FACTORIAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FLOOR) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FUNCTION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &GREATER_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &IDENTIFIER) {
// 		return eval_identifier(source, source.get_text(parts[0]), parent, unwindDest, builder);
// 	} else if (expressionType == &IF) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &INVOCATION) {
// 		return eval_invocation(source, source.get_parts(parts[0]), parent, unwindDest, builder);
// 	} else if (expressionType == &LESSER_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &LIST) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MAGNITUDE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MAP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MEMBER_ACCESS) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &NEAREST_INTEGER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &NON_NEG_NUMBER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &PARENTHETICAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &RADICAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &RANGE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SET) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SET_COMPREHENSION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &STRING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SUBSET_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SUPERSET_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &TUPLE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &TYPE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &UNARY_OP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &VECTOR_NORM) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.id == "null") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.id == "this") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.id == "this_func") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.id == "this_type") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else {
// 		ERROR(Unknown, "invalid expression type " + expressionType->id);
// 	}
// }
// 
// void eval_statement(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	ERROR(NotImplemented, "");
// /*
// 	auto p = parts[0];
// 	if (&p.r == &ASSIGNMENT_CHAIN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &DEFINITION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &DO) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &EXPRESSION) {
// 		auto expression_value = eval_expression(source, source.get_parts(p), parent, unwindDest, builder);
// 		auto concrete = expression_value->try_concretion();
// 		if (!concrete) {
// 			ERROR(NotImplemented, "Non-concrete statement-scope expressions are not implemented.");
// 		}
// 		auto asFunc = dynamic_cast<llvm::Function *>(concrete->underlying.get());
// 		if (asFunc) {
// 			auto funcType = asFunc->getFunctionType();
// 			if (funcType->getNumParams() == 0 && funcType->getReturnType()->isVoidTy()) {
// 				do_concrete_invoke(asFunc, std::vector<llvm::Value *>(), parent, &unwindDest, builder);
// 			}
// 		}
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FOR) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FOR_COLLECTION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FREE) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &IMPORT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &LOOP) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &RETURN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &THROW) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &TRY) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &TYPE_CONSTRAINT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (p.r.id == "break") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (p.r.id == "continue") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else {
// 		ERROR(Unknown, "invalid statement type " + p.r.id);
// 	}
// */
// }

symbol_table flatten_symbol_tables(symbol_table const & parent, symbol_table const & child) {
	symbol_table results;
	for (auto const & i : parent) {
		auto emplaceResult = results.emplace(i.first, std::move(i.second.delocalize())).second;
		throw_assert(emplaceResult);
	}
	for (auto symbol : child) {
		auto i = results.find(symbol.first);
		if (i == results.end()) {
			results.emplace(symbol.first, symbol.second);
		} else {
			if (!!i->second.value && symbol.second.isVariable) {
				ERROR(CannotAssignToConstant, to_utf8(symbol.first));
			}
			if (!!symbol.second.value) {
				ERROR(RedifinitionOfSymbol, to_utf8(symbol.first));
			}
		}
	}
	return results;
}

// symbol_table compute_assignment_chain_symbol_table(source_code const& source, std::vector<parlex::details::match> const& parts) {
// 	symbol_table results;
// 	for (auto const & part : parts) {
// 		if (&part.r == &IDENTIFIER) {
// 			std::u32string name = source.get_text(part);
// 			auto emplaceResult = results.emplace(name, symbol(name, nullptr, true, true)).second;
// 			throw_assert(emplaceResult);
// 		}
// 	}
// 	return results;
// }
//
// symbol compute_definition_symbol(source_code const& source, std::vector<parlex::details::match> const& parts, scope & parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	std::u32string name;
// 	std::shared_ptr<analytic_value> value;
// 	for (auto const & part : parts) {
// 		if (&part.r == &IDENTIFIER) {
// 			name = source.get_text(part);
// 		} else if (&part.r == &EXPRESSION) {
// 			value = eval_expression(source, source.get_parts(part), parent, unwindBlock, builder);
// 		}
// 	}
// 	ERROR(NotImplemented, "");
// }
// 
// symbol_table compute_statement_symbol_table(source_code const& source, std::vector<parlex::details::match> const& parts, scope & parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	auto p = parts[0];
// 	if (&p.r == &ASSIGNMENT_CHAIN) {
// 		return compute_assignment_chain_symbol_table(source, source.get_parts(p));
// 	}
// 	if (&p.r == &DEFINITION) {
// 		symbol_table results;
// 		auto result = compute_definition_symbol(source, source.get_parts(p), parent, unwindBlock, builder);
// 		results.insert(make_pair(result.name, result));
// 		return results;
// 	}
// 	if (&p.r == &DO) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &EXPRESSION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FOR) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FOR_COLLECTION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FREE) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &IMPORT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &LOOP) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &RETURN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &THROW) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &TRY) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &TYPE_CONSTRAINT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (p.r.id == "break") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (p.r.id == "continue") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	ERROR(Unknown, "invalid statement type " + p.r.id);
// }
// 
// symbol_table compute_scope_symbol_table(source_code const& source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	symbol_table results;
// 	for (auto part : parts) {
// 		if (&part.r == &STATEMENT) {
// 			symbol_table ofStatement = compute_statement_symbol_table(source, source.get_parts(part), parent, unwindBlock, builder);
// 		}
// 	}
// 	return flatten_symbol_tables(parent.symbols, results);
// }

std::shared_ptr<analytic_value> eval_statement_scope(source_code const & source, std::vector<parlex::details::match> const& parts, scope& parent, llvm::BasicBlock & unwindBlock) {
	ERROR(NotImplemented, "");
/*
	auto result = std::make_shared<scope>(source, parent);
	auto entryPointBlock = llvm::BasicBlock::Create(llvmContext, "", &parent.getLLVMFunction());
	llvm::IRBuilder<> scopeBuilder(entryPointBlock);
	for (auto part : parts) {
		if (&part.r == &STATEMENT) {
			eval_statement(source, source.get_parts(part), *result, unwindBlock, scopeBuilder);
		}
	}
	return result;*/
}

void compile(std::vector<std::reference_wrapper<source_code const>> sources) {
	/*
	std::vector<llvm::Type*> mainFuncArgTypes = {
		llvm::Type::getInt32Ty(llvmContext),
		llvm::Type::getInt8PtrTy(llvmContext)->getPointerTo()
	};

	auto mainFuncType = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(llvmContext),
		mainFuncArgTypes,
		false);

	llvm::Function * mainFunc = llvm::Function::Create(mainFuncType, llvm::Function::ExternalLinkage, "main", &module);
	scope rootScope(mainFunc);
	llvm::IRBuilder<> builder(llvmContext);

	auto unwindBlock = llvm::BasicBlock::Create(llvmContext, "unwind", mainFunc);
	builder.SetInsertPoint(unwindBlock);
	builder.CreateLandingPad(llvm::Type::getVoidTy(llvmContext), 0);

	auto entryPointBlock = llvm::BasicBlock::Create(llvmContext, "entry_point", mainFunc);
	builder.SetInsertPoint(entryPointBlock);

	for (auto source : sources) {
		eval_statement_scope(source.get(), source.get().get_parts(source.get().asg.root), rootScope, *unwindBlock);
	}
	*/

}

compiler::compiler() : c_std_lib_source(__FILE__ "../../stdlib/Plange.CStdLib._pg")
{

}



// void compiler::inject_c_std_lib(module & m)
// {
// 	std::shared_ptr<scope> cStdLibScope(new scope(m, &c_std_lib_source, &m.global));
// 
// 	auto cStdLibTopStatementScopeParts = c_std_lib_source.get_parts(c_std_lib_source.asg.root);
// 	for (auto const& topStatementScopePart : cStdLibTopStatementScopeParts) {
// 		if (&topStatementScopePart.r == &plc::STATEMENT) {
// 			auto statementParts = c_std_lib_source.get_parts(topStatementScopePart);
// 			auto firstStatementPart = statementParts[0];
// 			if (&firstStatementPart.r == &plc::TYPE_CONSTRAINT) {
// 				auto typeContraintParts = c_std_lib_source.get_parts(firstStatementPart);
// 				auto typeContraintHeadPart = typeContraintParts[0];
// 
// 			}
// 		}
// 	}
// 
// 	symbol cStdLib(U"CStdLib", cStdLibScope, false);
// 	bool didAddSymbol = m.global.add_symbol(cStdLib);
// 	throw_assert(didAddSymbol);
// }

}
