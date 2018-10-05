#ifndef INCLUDED_PLC_SOURCE_CODE_HPP
#define INCLUDED_PLC_SOURCE_CODE_HPP

// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <map>

#include "STATEMENT_SCOPE.hpp"

namespace plc {
	struct XML_DOC_STRING;

	class scope;

class source_code {
public:
	source_code(std::string const & pathname, std::u32string const & document);
	explicit source_code(std::string const & pathname);
	STATEMENT_SCOPE get_representation() const;

	template <typename T = STATEMENT_SCOPE>
	static T parse(std::u32string const & source) {
		parlex::detail::abstract_syntax_tree ast = construct_ast(source, T::acceptor(), "");
		return T::build(ast);
	}

	static std::pair<uint32_t, uint32_t> get_line_number_and_column(std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, uint32_t charIndex);
	static std::map<uint32_t, uint32_t> construct_line_number_by_first_character(std::u32string const & document);
	static std::string describe_code_span(int32_t firstCharacter, int32_t lastCharacter, std::map<uint32_t, uint32_t> const& lineNumberByFirstCharacter);
	static std::string describe_code_span(int32_t firstCharacter, int32_t lastCharacter, std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, std::string const & pathname);
	static parlex::detail::abstract_syntax_tree construct_ast(std::u32string const & document, parlex::detail::recognizer const & production, std::string const & pathname);

	std::u32string const & get_document() const;
	std::pair<uint32_t, uint32_t> get_line_number_and_column(uint32_t charIndex) const;
	std::string describe_code_span(int32_t firstCharacter, int32_t lastCharacter) const;

	template<typename T>
	std::u32string get_substring(T const & syntaxElement) const {
		return document.substr(syntaxElement.document_position, syntaxElement.consumed_character_count);
	}

	std::u32string get_xml_doc_string(XML_DOC_STRING const & v) const;

	template<typename T>
	std::string describe_code_span(T syntaxElement) const {
		return describe_code_span(syntaxElement.document_position, syntaxElement.document_position + syntaxElement.consumed_character_count - 1);
	}

private:
	std::string pathname;
	std::u32string document;
	std::map<uint32_t, uint32_t> line_number_by_first_character;
	parlex::detail::abstract_syntax_tree ast;
	STATEMENT_SCOPE representation;

};

}
#endif // INCLUDED_PLC_SOURCE_CODE_HPP
