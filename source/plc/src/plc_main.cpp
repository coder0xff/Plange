// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <iostream>

#include "gtest/gtest.h"

#include "module.hpp"
#include "tclap/CmdLine.h"
#include "utils.hpp"

#include "warnings.hpp"
#include "compiler.hpp"

int main(int argc, char * argv[]) {
	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		// All arguments following --test are passed to gtest.
		for (auto argIndex = 2; argIndex < argc; ++argIndex) {
			argv[argIndex - 1] = argv[argIndex];
		}
		--argc;
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	using namespace plc;
	std::string outputFilename;
	std::vector<std::string> filenames;
	try {
		TCLAP::CmdLine cmd("Plange compiler", ' ', "0.1");
		TCLAP::ValueArg<std::string> outputFileArg("o", "output", "the file to write the output to", true, "a", "a path string");
		TCLAP::UnlabeledMultiArg<std::string> filesArg("filenames", "the files to compile", true, "filename", cmd);
		cmd.parse(argc, argv);
		filenames = filesArg.getValue();
		outputFilename = outputFileArg.getValue();
	} catch (TCLAP::ArgException& e) // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for argument " << e.argId() << std::endl;
	}

	std::set<std::string> realpaths;
	for (auto filename : filenames) {
		auto const didInsert = realpaths.insert(realpath(filename)).second;
		if (!didInsert) { // duplicate file
			WARNING(DuplicateFileIgnored, filename);
		};
	}

	compiler c;
	auto m = std::make_unique<module>(&c);

	for (auto const & pathname : realpaths) {
		m->add_source(pathname);
// 		auto emplaceResult = parses.emplace(std::piecewise_construct, forward_as_tuple(pathname), std::forward_as_tuple(new source_code(pathname)));
// 		throw_assert(emplaceResult.second);
// 		sources.emplace_back(*emplaceResult.first->second);
	}

	m->compile(outputFilename);

	return 0;
}
