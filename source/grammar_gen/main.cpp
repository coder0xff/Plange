/****************************************************
 *
 * Given the path of the Plange/source directory as a
 * command-line argument, generates
 * Plange/source/plc/include/plange_grammar.hpp and
 * Plange/source/plc/src/plange_grammar.cpp
 * 
 ****************************************************/

#include <yaml-cpp/yaml.h>
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include "parlex/details/parser.hpp"
#include "parlex/details/grammar.hpp"
#include "parlex/details/builtins.hpp"
#include "parlex/builder.hpp"
#include "utf.hpp"
#include "parlex/cpp_generator.hpp"
#include "parlex/details/wirth.hpp"

inline std::string trim(std::string str)
{
	str.erase(0, str.find_first_not_of(" \n\t\t"));       //prefixing spaces
	str.erase(str.find_last_not_of(" \n\t\r") + 1);         //suffixing spaces
	return str;
}

// takes one argument pointing to the directory containing syntax.yml
int main(int argc, const char* argv[]) {
	throw_assert(argc == 2);
	std::string workingDir = argv[1];
	std::string filename = workingDir + "/syntax.yml";
	std::ifstream ifs(filename, std::ios::binary);
	throw_assert(bool(ifs));
	std::u32string syntaxYaml = read_with_bom(move(ifs));
	YAML::Node spec = YAML::Load(to_utf8(syntaxYaml));

	parlex::details::parser p;
	std::map<std::string, parlex::details::wirth_t::production> defs;
	for (auto const & elem : spec) {
		std::string name = elem.first.as<std::string>();
		auto data = elem.second;
		std::cout << "parsing " << name << "\n";
		std::string syntax = trim(data["syntax"].as<std::string>());
		std::cout << "syntax " << syntax << "\n";
		std::u32string source = to_utf32(syntax);
		auto assoc = parlex::associativity::none;
		if (data["assoc"]) {
			std::string assocName = data["assoc"].as<std::string>();
			if (assocName == "either") {
				assoc = parlex::associativity::any;
			} else if (assocName == "left") {
				assoc = parlex::associativity::left;
			} else if (assocName == "right") {
				assoc = parlex::associativity::right;
			} else {
				throw std::logic_error(("invalid assoc value " + assocName).c_str());
			}
		}
		parlex::filter_function filter;
		if (data["filter"]) {
			std::string filterName = data["filter"].as<std::string>();
			if (filterName == "longest") {
				filter = parlex::details::builtins().longest;
			} else {
				throw std::logic_error(("unrecognized filter " + filterName).c_str());
			}
		}
		std::set<std::string> precedences;
		if (data["precedes"]) {
			for (auto element : data["precedes"]) {
				precedences.insert(element.as<std::string>());
			}
		}
		defs.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, precedences));
	}
	parlex::builder g = parlex::wirth().load_grammar("STATEMENT_SCOPE", defs);
	std::ofstream cppStream(workingDir + "/plc/src/plange_grammar.cpp.inc");
	std::ofstream hppStream(workingDir + "/plc/include/plange_grammar.hpp.inc");
	auto files = parlex::cpp_generator::generate("plange", g);
	auto write_files = [&](std::string const & plcDir, parlex::cpp_generator::file_dictionary const & filesToWrite)
	{
		for (auto const & file : filesToWrite) {
			std::string filePathname = workingDir + "/" + plcDir + "/" + file.first;
			std::ofstream s(filePathname);
			if (!s) {
				throw std::runtime_error("couldn't open file for writing");
			}
			s << file.second;
		}
	};
	write_files("plc/include/document", files.headers);
	write_files("plc/src/document", files.sources);

}
