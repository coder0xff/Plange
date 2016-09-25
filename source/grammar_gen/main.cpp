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
#include <cassert>
#include <fstream>
#include <iostream>
#include "parlex/builtins.hpp"

inline std::string trim(std::string str)
{
	str.erase(0, str.find_first_not_of(" \n\t\t"));       //prefixing spaces
	str.erase(str.find_last_not_of(" \n\t\r") + 1);         //suffixing spaces
	return str;
}

int main(int argc, const char* argv[]) {
	assert(argc == 2);
	std::string workingDir = argv[1];
	std::string filename = workingDir + "/syntax.yml";
	std::ifstream ifs(filename, std::ios::binary);
	std::u32string syntaxYaml = read_with_bom(ifs);
	YAML::Node spec = YAML::Load(to_utf8(syntaxYaml));
	std::map<std::string, parlex::wirth_production_def> defs;
	for (auto const & elem : spec) {
		std::string name = elem.first.as<std::string>();
		auto data = elem.second;
		std::cout << name << "\n";
		std::string syntax = trim(data["syntax"].as<std::string>());
		std::cout << syntax << "\n";
		parlex::wirth_production_def temp;
		temp.definition = to_utf32(syntax);
		temp.assoc = parlex::associativity::none;
		if (data["assoc"]) {
			std::string assocName = data["assoc"].as<std::string>();
			if (assocName == "either") {
				temp.assoc = parlex::associativity::any;
			} else if (assocName == "left") {
				temp.assoc = parlex::associativity::left;
			} else if (assocName == "right") {
				temp.assoc = parlex::associativity::right;
			} else {
				throw std::logic_error(("invalid assoc value " + assocName).c_str());
			}
		}
		temp.filter = nullptr;
		if (data["filter"]) {
			std::string filterName = data["filter"].as<std::string>();
			if (filterName == "longest") {
				temp.filter = &parlex::builtins::longest;
			} else {
				throw std::logic_error(("unrecognized filter " + filterName).c_str());
			}
		}
		if (data["precedes"]) {
			for (auto element : data["precedes"]) {
				temp.precedences.insert(element.as<std::string>());
			}
		}
		defs[name] = temp;
	}
	parlex::grammar g = parlex::load_grammar("STATEMENT_SCOPE", defs);
	std::ofstream cppStream(workingDir + "/plc/src/plange_grammar.cpp");
	std::ofstream hppStream(workingDir + "/plc/include/plange_grammar.hpp");
	g.generate_cpp("plange", "STATEMENT_SCOPE", cppStream, hppStream);
}
