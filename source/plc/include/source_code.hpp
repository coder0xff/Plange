#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP

#include <map>

#include "STATEMENT_SCOPE.hpp"

namespace plc {

class scope;

class source_code {
public:
	source_code(std::string const & pathname, std::u32string const & document);
	explicit source_code(std::string const & pathname);
	std::string const pathname;
	std::u32string const document;

private: // we need a certain initialization order for these const fields
	std::map<uint32_t, uint32_t> const line_number_by_first_character;

public:
	template <typename T = STATEMENT_SCOPE>
	static T parse(std::u32string const & source) {
		parlex::detail::abstract_syntax_tree ast = construct_ast(source, T::acceptor(), "");
		return T::build(ast);
	}

	static std::pair<uint32_t, uint32_t> get_line_number_and_column(std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, uint32_t charIndex);
	// For initialization of `line_number_by_first_character` data member, requires document already constructed
	static std::map<uint32_t, uint32_t> construct_line_number_by_first_character(std::u32string const & document);
	static std::string describe_code_span(parlex::detail::match const & m, std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, std::string const & pathname = "");
	static parlex::detail::abstract_syntax_tree construct_ast(std::u32string const & document, parlex::detail::recognizer const & production, std::string const & pathname);

	parlex::detail::abstract_syntax_tree const ast;
	STATEMENT_SCOPE const representation;

	std::pair<uint32_t, uint32_t> get_line_number_and_column(uint32_t charIndex) const;
	std::string describe_code_span(parlex::detail::match const & m) const;

};

}
#endif
