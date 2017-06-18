#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include "parlex/parser.hpp"

namespace plc {

class scope;

class source_code {
public:
	source_code(std::string const& pathname, std::u32string const& document);
	source_code(std::string const& pathname);
	~source_code();
	std::string pathname;
	std::u32string const document;
	parlex::abstract_syntax_graph const asg;
	std::pair<int, int> get_line_number_and_column(int charIndex) const;
	parlex::permutation get_parts(parlex::match const & m) const;
	std::u32string get_text(parlex::match const & m) const;

	static void get_type_constraint_parts(parlex::match const& m, bool& isStatic, bool& isExtern);
private:
	std::map<int, int> line_number_by_first_character;
};

}
#endif
