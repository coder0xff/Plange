#include <iostream>

#include "module.hpp"
#include "tclap/CmdLine.h"
#include "utils.hpp"

#pragma warning(push, 0)
#include <gtest/gtest.h>
#include "warnings.hpp"
#pragma warning(pop)


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

	auto m = std::make_unique<module>();

	for (auto const & pathname : realpaths) {
		m->add_source(pathname);
// 		auto emplaceResult = parses.emplace(std::piecewise_construct, forward_as_tuple(pathname), std::forward_as_tuple(new source_code(pathname)));
// 		throw_assert(emplaceResult.second);
// 		sources.emplace_back(*emplaceResult.first->second);
	}

	m->compile(outputFilename);

	return 0;
}
