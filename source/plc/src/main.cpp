#include <fstream>
#include <stdlib.h>
#include <iostream>

#include "stdafx.hpp"
#include "parser.hpp"
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
#include "module.hpp"
#pragma warning(pop)


int main(int argc, const char* argv[]) {
	using namespace plc;
	std::string output_filename;
	std::vector<std::string> filenames;
	try {
		TCLAP::CmdLine cmd("Plange compiler", ' ', "0.1");
		TCLAP::ValueArg<std::string> output_file_arg("o", "output", "the path to write the output to", true, "a", "a path string");
		TCLAP::UnlabeledMultiArg<std::string> files_arg("filenames", "the files to compile", true, "filename", cmd);
		cmd.parse(argc, argv);
		filenames = files_arg.getValue();
		output_filename = output_file_arg.getValue();
	} catch (TCLAP::ArgException& e) // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}

	std::vector<std::string> realpaths;
	for (auto filename : filenames) {
		realpaths.push_back(realpath(filename));
	}

	std::map<std::string, std::unique_ptr<source_code>> parses;
	std::vector<std::reference_wrapper<source_code const>> sources;
	std::unique_ptr<module> m;

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
		auto emplaceResult = parses.emplace(std::piecewise_construct, forward_as_tuple(filename), std::forward_as_tuple(new source_code(filename)));
		throw_assert(emplaceResult.second);
		sources.emplace_back(*emplaceResult.first->second);
	}

	m.reset(new module(sources));

	m->compile(output_filename);

	return 0;
}
