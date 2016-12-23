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
#include "scope.hpp"

#pragma warning(push, 0)
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include "compiler.hpp"
#pragma warning(pop)


int main(int argc, const char* argv[]) {
	using namespace plc;
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
	for (auto filename : filenames) {
		realpaths.push_back(realpath(filename));
	}

	parlex::parser p;
	std::map<std::string, std::unique_ptr<source_code>> parses;
	std::vector<std::reference_wrapper<source_code const>> sources;

	for (auto filename : realpaths) {
		if (parses.count(filename)) {
			WARNING(DuplicateFileIgnored, filename);
			continue;
		}

		std::ifstream ifs(filename, std::ios::binary);
		if (!ifs) {
			ERROR(CouldNotOpenFile, filename);
		}
		std::u32string s = read_with_bom(ifs);
		auto emplaceResult = parses.emplace(std::piecewise_construct, forward_as_tuple(filename), std::forward_as_tuple(new source_code(filename, s, p)));
		assert(emplaceResult.second);
		sources.emplace_back(*emplaceResult.first->second);
	}

	compile(sources);

	return 0;
}
