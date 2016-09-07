#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include "parlex/parser.hpp"

class source_code {
public:
	source_code(std::string const& pathname, std::u32string const& document, parlex::parser& parser);
	~source_code();
	parlex::abstract_syntax_graph graph;
	std::map<int, int> lineNumberByFirstChar;
	std::pair<int, int> get_line_number_and_column(int charIndex);
	std::u32string document;
};

#endif
