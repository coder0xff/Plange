#include <fstream>
#include <stdlib.h>
#include <iostream>

#include "parlex/parser.hpp"
#include "plange_grammar.hpp"
#include "tclap/CmdLine.h"
#include "utils.hpp"
#include "Errors.h"
#include "Warnings.h"
#include "SourceCode.h"

#pragma warning(push, 0)
#include "llvm/IR/Module.h"
#pragma warning(pop)

std::string realpath(std::string fileName) {
	struct free_delete
	{
		void operator()(char * x) const { free(static_cast<void *>(x)); }
	};

#ifdef _MSC_VER
	std::unique_ptr<char, free_delete> buffer(_fullpath(nullptr, fileName.c_str(), _MAX_PATH));
#else
	std::unique_ptr<char, free_delete> buffer(realpath(fileName.c_str(), nullptr));
#endif
	return buffer.get();
}

int main(int argc, const char* argv[]) {
	std::vector<std::string> filenames;
	try {
		TCLAP::CmdLine cmd("Plange compiler", ' ', "0.1");
		TCLAP::UnlabeledMultiArg<std::string> files_arg("filenames", "the files to compile", true, "filename", cmd);
		cmd.parse(argc, argv);
		filenames = files_arg.getValue();
	}
	catch (TCLAP::ArgException &e)  // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}

	std::vector<std::string> realpaths;
	for (std::string filename : filenames) {
		realpaths.push_back(realpath(filename));
	}

	parlex::parser p;
	std::map<std::string, std::unique_ptr<SourceCode>> parses;

	for (std::string filename : realpaths) {
		if (parses.count(filename)) {
			emit_DuplicateFileIgnored(filename);
			continue;
		}

		std::ifstream ifs(filename, std::ios::binary);
		if (!ifs) {
			emit_CouldNotOpenFile(filename);
		}
		std::u32string s = read_with_bom(ifs);

		bool inserted = parses.emplace(std::piecewise_construct, std::forward_as_tuple(filename), std::forward_as_tuple(new SourceCode(filename, s, p))).second;
		assert(inserted);
	}

	std::unique_ptr<llvm::Module> module(new llvm::Module("module", llvm::getGlobalContext()));

	for (auto const & nameAndParse : parses) {
		std::string const & pathname = nameAndParse.first;
		SourceCode const & source = *nameAndParse.second;

	}

	return 0;
}