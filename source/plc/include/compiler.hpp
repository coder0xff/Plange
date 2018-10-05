#ifndef INCLUDED_PLC_COMPILER_HPP
#define INCLUDED_PLC_COMPILER_HPP

// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#pragma warning(push, 0)
#include "llvm/IR/LLVMContext.h"
#include "llvm/Target/TargetMachine.h"
#pragma warning(pop)

#include "pointer.hpp"

#include "source_code.hpp"
#include "EMBEDDED_COMMENT.hpp"
#include "EMBEDDED_STRING.hpp"
#include "EMBEDDED_NEWLINE_STRING.hpp"

namespace plc {
struct PAYLOAD;

class module;
struct XML_DOC_STRING;

class compiler {
public:
	static STATEMENT_SCOPE parse(std::u32string const & source);
	static std::u32string extract_xml_doc_string(std::u32string const & document, XML_DOC_STRING const & xmlDocString);

	template <typename T>
	static T parse(std::u32string const & document) {
		return source_code::parse<T>(document);
	};

	static void build(std::string const & outputFilename, std::set<std::string> const & inputFiles);

	llvm::LLVMContext & get_llvm_context();
	llvm::TargetMachine & get_target_machine() const;
private:
	std::string target_triple;
	pointer<llvm::TargetMachine> target_machine;
	llvm::LLVMContext llvm_context;

	static void inject_std_lib(module & m);
	compiler();
	void build_impl(std::string const & outputFilename, std::set<std::string> const & inputFiles);
};

}

#endif // INCLUDED_PLC_COMPILER_HPP
