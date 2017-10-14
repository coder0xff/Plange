#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP
#include <map>
#include "STATEMENT_SCOPE.hpp"

namespace plc {

class scope;

class source_code {
public:
	source_code(std::string const & pathname, std::u32string const & document);
	source_code(std::string const & pathname);
	~source_code();
	std::string const pathname;
	std::u32string const document;
private: // we need a certain initialization order for these const fields
	std::map<int, int> const line_number_by_first_character;
public:
	parlex::details::abstract_syntax_tree const ast;
	STATEMENT_SCOPE const representation;

	std::pair<int, int> get_line_number_and_column(int charIndex) const;

private:
	static std::pair<int, int> get_line_number_and_column_impl(std::map<int, int> const lineNumberByFirstCharacter, int charIndex);
	// For initialization of `line_number_by_first_character` data member
	static std::map<int, int> construct_line_number_by_first_character(std::u32string const & document);
	// For initialization of `ast` data member
	static parlex::details::abstract_syntax_tree construct_ast(std::string const & pathname, std::u32string const & document, std::map<int, int> const lineNumberByFirstCharacter);
	// For initialization of `representation` data member
	static STATEMENT_SCOPE construct_representation(parlex::details::abstract_syntax_tree const & ast);
};

}
#endif
