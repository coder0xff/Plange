#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include "parlex/parser.hpp"

class Scope;

class SourceCode {
public:
	SourceCode(std::string const& pathname, std::u32string const& document, parlex::parser& parser);
	~SourceCode();
	parlex::abstract_syntax_graph graph;
	std::map<int, int> lineNumberByFirstChar;
	std::pair<int, int> get_line_number_and_column(int charIndex);
	std::unique_ptr<Scope> scope;
};

#endif
