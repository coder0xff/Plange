#ifndef INCLUDED_PLC_COMPILER_HPP
#define INCLUDED_PLC_COMPILER_HPP

// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#pragma warning(push, 0)
#include "llvm/IR/LLVMContext.h"
#pragma warning(pop)

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

	llvm::LLVMContext llvm_context;
};

}

#endif // INCLUDED_PLC_COMPILER_HPP
