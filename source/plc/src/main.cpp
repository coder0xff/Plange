#include "stdafx.hpp"

#include <fstream>
#include <iostream>

#include "compiler.hpp"
#include "module.hpp"
#include "scope.hpp"
#include "source_code.hpp"
#include "tclap/CmdLine.h"
#include "utf.hpp"
#include "utils.hpp"

#pragma warning(push, 0)
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <gtest/gtest.h>
#pragma warning(pop)


int main(int argc, char * argv[]) {
	if (argc > 1 && strcmp(argv[1], "--test") != std::string::npos) {
		// All arguments following --test are passed to gtest.
		for (auto arg_index = 2; arg_index < argc; ++arg_index) {
			argv[arg_index - 1] = argv[arg_index];
		}
		--argc;
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	using namespace plc;
	std::string output_filename;
	std::vector<std::string> filenames;
	try {
		TCLAP::CmdLine cmd("Plange compiler", ' ', "0.1");
		TCLAP::ValueArg<std::string> output_file_arg("o", "output", "the file to write the output to", true, "a", "a path string");
		TCLAP::UnlabeledMultiArg<std::string> files_arg("filenames", "the files to compile", true, "filename", cmd);
		cmd.parse(argc, argv);
		filenames = files_arg.getValue();
		output_filename = output_file_arg.getValue();
	} catch (TCLAP::ArgException& e) // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for argument " << e.argId() << std::endl;
	}

	std::set<std::string> realpaths;
	for (auto filename : filenames) {
		bool didInsert = realpaths.insert(realpath(filename)).second;
		if (!didInsert) { // duplicate file
			WARNING(DuplicateFileIgnored, filename);
		};
	}

	auto m = std::make_unique<module>();

	for (auto pathname : realpaths) {
		m->add_source(pathname);
// 		auto emplaceResult = parses.emplace(std::piecewise_construct, forward_as_tuple(pathname), std::forward_as_tuple(new source_code(pathname)));
// 		throw_assert(emplaceResult.second);
// 		sources.emplace_back(*emplaceResult.first->second);
	}

	m->compile(output_filename);

	return 0;
}
