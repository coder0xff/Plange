// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include "module.hpp"

#pragma warning(push, 0)
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/tools/bugpoint/ToolRunner.h"
#pragma warning(pop)

#include "compiler.hpp"
#include "errors.hpp"
#include "utf.hpp"

namespace plc {

module::module(compiler & owner, nptr<source_code const> source) : owner(owner), source(source), llvm_module("module", owner.get_llvm_context()), plange(make_val<scope>(*this, source, std::nullopt)) {
	std::once_flag llvmInit;
	std::call_once(llvmInit, []
	{
		llvm::InitializeAllTargetInfos();
		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
		llvm::InitializeAllAsmParsers();
		llvm::InitializeAllAsmPrinters();
	});

	auto const targetTriple = llvm::sys::getDefaultTargetTriple();
	std::string error;
	auto const target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

	if (!target) {
		ERROR(Unknown, error);
	}

	auto const cpu = "generic";
	auto const features = "";
	llvm::TargetOptions const opt;
	auto const rm = llvm::Optional<llvm::Reloc::Model>();
	auto * targetMachine = target->createTargetMachine(targetTriple, cpu, features, opt, rm);
	llvm_module.setDataLayout(targetMachine->createDataLayout());
	llvm_module.setTargetTriple(targetTriple);
}

void module::compile(std::string const & outputFilename) {
	std::error_code errorCode;
	llvm::raw_fd_ostream dest(outputFilename, errorCode, llvm::sys::fs::OpenFlags::F_None);

	if (errorCode) {
		ERROR(CouldNotOpenFile, errorCode.message());
	}
	llvm::legacy::PassManager pass;
	auto const fileType = llvm::TargetMachine::CGFT_ObjectFile;

	if (owner.get_target_machine().addPassesToEmitFile(pass, dest, fileType)) {
		ERROR(Unknown, "TargetMachine can't emit a file of this type");
	}

	pass.run(llvm_module);
	dest.flush();
}

llvm::Module const & module::get_llvm_module() const {
	return llvm_module;
}

llvm::Module & module::get_llvm_module() {
	return llvm_module;
}

compiler & module::get_compiler() const {
	return owner;
}

nptr<source_code const> module::get_source() const {
	return source;
}

llvm::GlobalVariable * module::get_or_add_global_string(std::u32string const & s) {
	auto const i = global_strings.find(s);
	if (i != global_strings.end()) return i->second;
	llvm::StringRef const str(to_utf8(s));
	auto const strConstant = llvm::ConstantDataArray::getString(owner.get_llvm_context(), str);
	auto gv = new llvm::GlobalVariable(llvm_module, strConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, strConstant);
	auto const name = "str" + std::to_string(global_strings.size());
	gv->setName(name);
	//gv->setUnnamedAddr(true)
	return global_strings[s] = gv;
}

}
