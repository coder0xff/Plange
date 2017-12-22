#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include <map>

#include "parlex/detail/parser.hpp"

#include "plange_grammar.hpp"
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
	template <typename T = STATEMENT_SCOPE>
	static T parse(std::u32string const & source) {
		auto ast = construct_ast(source, T::recognizer(), "");
		throw_assert(&ast.r == &T::recognizer());
		return T::build(ast);
	}

	static std::pair<int, int> get_line_number_and_column(std::map<int, int> const & lineNumberByFirstCharacter, int charIndex);
	// For initialization of `line_number_by_first_character` data member, requires document already constructed
	static std::map<int, int> construct_line_number_by_first_character(std::u32string const & document);
	static std::string describe_code_span(parlex::detail::match const & m, std::map<int, int> const & lineNumberByFirstCharacter, std::string const & pathname = "");
	static parlex::detail::abstract_syntax_tree construct_ast(std::u32string const & document, parlex::detail::recognizer const & production, std::string const & pathname);

	parlex::detail::abstract_syntax_tree const ast;
	STATEMENT_SCOPE const representation;

	std::pair<int, int> get_line_number_and_column(int charIndex) const;
	std::string describe_code_span(parlex::detail::match const & m) const;

private:
	// For initialization of `representation` data member
};

}
#endif
