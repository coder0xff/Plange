#include <fstream>
#include <stdlib.h>
#include <iostream>

#include "stdafx.hpp"
#include "parlex/parser.hpp"
#include "plange_grammar.hpp"
#include "tclap/CmdLine.h"
#include "utils.hpp"
#include "source_code.hpp"
#include "stdlib.hpp"

#pragma warning(push, 0)
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#pragma warning(pop)


void eval_parenthetical_invocation(parlex::match match, source_code const &sourceCode, llvm::IRBuilder<> &builder) {
	parlex::permutation parts = *sourceCode.graph.permutations.find(match)->second.begin();
	parlex::match funcVal = parts[0];
	std::vector<parlex::match> arguments;
	for (size_t i = 1; i < parts.size(); ++i) {
		if (parts[i].r.get_id() == "EXPRESSION") {
			arguments.push_back(parts[i]);
		}
	}
}

void eval_invocation(parlex::match match, source_code const &sourceCode, llvm::IRBuilder<> &builder) {
	parlex::permutation parts = *sourceCode.graph.permutations.find(match)->second.begin();
	std::string partType = parts[0].r.get_id();
	if (partType == "PARENTHETICAL_INVOCATION") {
		eval_parenthetical_invocation(parts[0], sourceCode, builder);
	}
}

void eval_expression(parlex::match match, source_code const &sourceCode, llvm::IRBuilder<> &builder) {
	parlex::permutation parts = *sourceCode.graph.permutations.find(match)->second.begin();
	std::string partType = parts[0].r.get_id();
	if (partType == "INVOCATION") {
		eval_invocation(parts[0], sourceCode, builder);
	}
}

int main(int argc, const char* argv[]) {
	std::vector<std::string> filenames;
	try {
		TCLAP::CmdLine cmd("Plange compiler", ' ', "0.1");
		TCLAP::UnlabeledMultiArg<std::string> files_arg("filenames", "the files to compile", true, "filename", cmd);
		cmd.parse(argc, argv);
		filenames = files_arg.getValue();
	} catch (TCLAP::ArgException& e) // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}

	std::vector<std::string> realpaths;
	for (std::string filename : filenames) {
		realpaths.push_back(realpath(filename));
	}

	parlex::parser p;
	std::map<std::string, std::unique_ptr<source_code>> parses;

	for (std::string filename : realpaths) {
		if (parses.count(filename)) {
			WARNING(DuplicateFileIgnored, filename);
			continue;
		}

		std::ifstream ifs(filename, std::ios::binary);
		if (!ifs) {
			ERROR(CouldNotOpenFile, filename);
		}
		std::u32string s = read_with_bom(ifs);
		bool inserted = parses.emplace(std::piecewise_construct, std::forward_as_tuple(filename), std::forward_as_tuple(new source_code(filename, s, p))).second;
		assert(inserted);
	}

	llvm::LLVMContext llvmContext;
	std::unique_ptr<llvm::Module> module(new llvm::Module("module", llvmContext));
	loadStdLib(&*module);
	llvm::IRBuilder<> builder(llvmContext);

	std::vector<llvm::Type*> mainFuncArgTypes = {
		llvm::Type::getInt32Ty(llvmContext),
		llvm::Type::getInt8PtrTy(llvmContext)->getPointerTo()
	};
	
	llvm::FunctionType *mainFuncType = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(llvmContext),
		mainFuncArgTypes,
		false);
	llvm::Function *mainFunc = llvm::Function::Create(mainFuncType, llvm::Function::ExternalLinkage, "main", &*module);
	llvm::BasicBlock *entryPointBlock = llvm::BasicBlock::Create(llvmContext, "entrypoint", mainFunc);
	builder.SetInsertPoint(entryPointBlock);

	for (auto const &path : realpaths) {
		source_code const& source = *parses[path];
		parlex::match root = source.graph.root;
		parlex::permutation top = *source.graph.permutations.find(root)->second.begin();
		for (parlex::match statementMatch : top) {
			if (statementMatch.r.get_id() == "STATEMENT") {
				parlex::permutation statementParts = *source.graph.permutations.find(statementMatch)->second.begin();
				std::string statementType = statementParts[0].r.get_id();
				if (statementType == "DEFINITION") {
					
				}
				if (statementType == "ASSIGNMENT") {

				} else if (statementType == "EXPRESSION") {
					eval_expression(statementParts[0], source, builder);
				}
			}
		}
	}

	return 0;
}
