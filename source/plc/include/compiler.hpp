#ifndef INCLUDED_PLC_COMPILER_HPP
#define INCLUDED_PLC_COMPILER_HPP

#include "source_code.hpp"

namespace plc {

class module;
struct XML_DOC_STRING;

class compiler {
public:
	static void inject_std_lib(module & m);
	static STATEMENT_SCOPE parse(std::u32string const & source);
	static std::u32string extract_xml_doc_string(std::u32string const & document, XML_DOC_STRING const & xmlDocString);

	template <typename T>
	static T parse(std::u32string const & document) {
		return source_code::parse<T>(document);
	}
};

}

#endif // INCLUDED_PLC_COMPILER_HPP
