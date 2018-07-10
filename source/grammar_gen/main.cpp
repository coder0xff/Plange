/****************************************************
 *
 * Given the path of the Plange/source directory as a
 * command-line argument, generates
 * Plange/source/plc/include/plange_grammar.hpp and
 * Plange/source/plc/src/plange_grammar.cpp
 * 
 ****************************************************/

#include <fstream>
#include <iostream>
#include <optional>

#pragma warning(push, 0)
#include "yaml-cpp/yaml.h"
#pragma warning(pop)

#include "utf.hpp"
#include "utils.hpp"

#include "parlex/builder.hpp"
#include "parlex/cpp_generator.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/grammar.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/wirth.hpp"

inline std::string trim(std::string str)
{
	str.erase(0, str.find_first_not_of(" \n\t\t"));       //prefixing spaces
	str.erase(str.find_last_not_of(" \n\t\r") + 1);         //suffixing spaces
	return str;
}

std::optional<std::string> read_file(std::string const & pathname)
{
	std::ifstream file(pathname);
	if (file) {
		std::string str;
		std::string fileContents;
		while (getline(file, str))
		{
			fileContents += str;
			fileContents.push_back('\n');
		}
		return fileContents;
	}
	return std::optional<std::string>();
}

void write_file(std::string const & pathname, std::string const & text)
{
	auto const bomText = "\xEF\xBB\xBF" + text;
	auto currentText = read_file(pathname);
	if (currentText.has_value() && currentText.value() == bomText)
	{
		return;
	}
	std::ofstream file(pathname, std::ios::binary);
	if (!file) {
		throw std::runtime_error("couldn't open file for writing");
	}
	std::cout << "Writing " << pathname << '\n';
	file << bomText;
}

void write_files(std::string const & plcDir, parlex::cpp_generator::file_dictionary const & filesToWrite)
{
	for (auto const & file : filesToWrite) {
		auto const pathname = plcDir + "/" + file.first;
		auto const & text = file.second;
		write_file(pathname, text);
	}
}

// takes one argument pointing to the directory containing syntax.yml
int main(int const argc, const char* argv[]) {
	throw_assert(argc == 2);
	std::string const workingDir = argv[1];
	auto const filename = workingDir + "/syntax.yml";
	std::ifstream ifs(filename, std::ios::binary);
	throw_assert(bool(ifs));
	auto const syntaxYaml = read_with_bom(move(ifs));
	auto spec = YAML::Load(to_utf8(syntaxYaml));

	parlex::detail::parser p;
	std::map<std::string, parlex::detail::wirth_t::production> defs;
	for (auto const & elem : spec) {
		auto name = elem.first.as<std::string>();
		auto data = elem.second;
		std::cout << "parsing " << name << "\n";
		std::string const syntax = trim(data["syntax"].as<std::string>());
		std::cout << "syntax " << syntax << "\n";
		auto source = to_utf32(syntax);
		auto assoc = parlex::associativity::NONE;
		if (data["assoc"]) {
			std::string const assocName = data["assoc"].as<std::string>();
			if (assocName == "either") {
				assoc = parlex::associativity::ANY;
			} else if (assocName == "left") {
				assoc = parlex::associativity::LEFT;
			} else if (assocName == "right") {
				assoc = parlex::associativity::RIGHT;
			} else {
				throw std::logic_error(("invalid assoc value " + assocName).c_str());
			}
		}
		parlex::filter_function filter;
		if (data["filter"]) {
			std::string const filterName = data["filter"].as<std::string>();
			if (filterName == "longest") {
				filter = parlex::longest();
			} else if (filterName == "shortest") {
				filter = parlex::shortest();
			} else {
				throw std::logic_error(("unrecognized filter " + filterName).c_str());
			}
		}
		std::set<std::string> precedences;
		if (data["precedes"]) {
			for (const auto & element : data["precedes"]) {
				precedences.insert(element.as<std::string>());
			}
		}
		defs.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, precedences));
	}
	auto const g = parlex::wirth().load_grammar("STATEMENT_SCOPE", defs);
	auto const files = parlex::cpp_generator::generate("plange", { "plc" }, g);

	write_files(workingDir + "/plc/include/document", files.headers);
	write_files(workingDir + "/plc/src/document", files.sources);

}
