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
#include "parlex/parser.hpp"
#include "parlex/grammar.hpp"
#include "parlex/builtins.hpp"

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
	std::u32string syntaxYaml = read_with_bom(ifs);
	YAML::Node spec = YAML::Load(to_utf8(syntaxYaml));

	parlex::parser p;
	std::map<std::string, parlex::details::wirth_t::production> defs;
	for (auto const & elem : spec) {
		std::string name = elem.first.as<std::string>();
		auto data = elem.second;
		std::cout << name << "\n";
		std::string syntax = trim(data["syntax"].as<std::string>());
		std::cout << syntax << "\n";
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
				filter = p.builtins.longest;
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
		defs[name] = parlex::details::wirth_t::production(source, assoc, filter, precedences);
	}
	std::unique_ptr<parlex::correlated_grammar> g = p.builtins.wirth.load_grammar("STATEMENT_SCOPE", defs);
	std::ofstream cppStream(workingDir + "/plc/src/plange_grammar.cpp");
	std::ofstream hppStream(workingDir + "/plc/include/plange_grammar.hpp");
	g.generate_cplusplus_code(p.builtins, "plange", "STATEMENT_SCOPE", cppStream, hppStream, "plc");
}
