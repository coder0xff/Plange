#include <fstream>

#include "parlex/parser.hpp"
#include "plange_grammar.hpp"
#include "tclap/CmdLine.h"
#include "utils.hpp"

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

	parlex::parser p;
	parlex::grammar const & g = get_plange();

	for (std::string filename : filenames) {
		std::ifstream ifs(filename, std::ios::binary);
		if (!ifs) {
			std::cerr << ("Could not open file: " + filename);
			throw std::exception(("Could not open file: " + filename).c_str());
		}
		std::u32string s = read_with_bom(ifs);
		parlex::abstract_syntax_graph asg = p.parse(g, s);
		if (!asg.is_rooted()) {
			std::cerr << (filename + " could not be parsed.\n");
			throw std::exception((filename + " could not be parsed.\n").c_str());
		}
	}

	return 0;
}