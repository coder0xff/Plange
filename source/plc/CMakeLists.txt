# LLVM will build LLD if put it in the right place
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/lld" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/llvm/tools/")

function(add_llvm)
	set(LLVM_BUILD_TESTS OFF CACHE BOOL "")
	set(LLVM_BUILD_UTILS OFF CACHE BOOL "")
	set(LLVM_ENABLE_OCAMLDOC OFF CACHE BOOL "")
	set(LLVM_ENABLE_RTTI ON CACHE BOOL "")
	set(LLVM_ENABLE_EH ON CACHE BOOL "")
	set(LLVM_INCLUDE_DOCS OFF CACHE BOOL "")
	set(LLVM_INCLUDE_EXAMPLES OFF CACHE BOOL "")
	set(LLVM_INCLUDE_GO_TESTS OFF CACHE BOOL "")
	set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "")
	set(LLVM_INCLUDE_UTILS OFF CACHE BOOL "")
	set(LLVM_TARGETS_TO_BUILD "X86" CACHE STRING "") # Disable this setting to build for all targets

	add_subdirectory(llvm)
	include_directories(${LLVM_SOURCE_DIR}/include)
	export(TARGETS gtest APPEND FILE "${CMAKE_BINARY_DIR}/source/plc/llvm/lib/cmake/llvm/LLVMBuildTreeOnlyTargets.cmake")
endfunction(add_llvm)
add_llvm()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") #for tclap
include_directories("${PROJECT_SOURCE_DIR}/source/utilities")
include_directories("${PROJECT_SOURCE_DIR}/source/mpl")
include_directories("${PROJECT_SOURCE_DIR}/source/collections")
include_directories("${PROJECT_SOURCE_DIR}/source/parlex/include")
include_directories("${CMAKE_BINARY_DIR}/source/plc/llvm/include")

set(SOURCES
	"src/analytic_value.cpp"
	"src/compiler.cpp"
	"src/errors.cpp"
	"src/main.cpp"
	"src/module.cpp"
	"src/natural_value.cpp"
	"src/plange_grammar.cpp"
	"src/scope.cpp"
	"src/source_code.cpp"
	"src/stdafx.cpp"
	"src/symbol.cpp"
	"src/warnings.cpp"
	"src/plc_utils.cpp")

set(HEADERS
	"include/analytic_value.hpp"
	"include/compiler.hpp"
	"include/errors.hpp"
	"include/module.hpp"
	"include/natural_value.hpp"
	"include/plange_grammar.hpp"
	"include/relation.hpp"
	"include/scope.hpp"
	"include/source_code.hpp"
	"include/stdafx.hpp"
	"include/symbol.hpp"
	"include/warnings.hpp"
	"include/plc_utils.hpp")

FILE(GLOB DOCUMENT_SOURCES "src/document/*.cpp*") 
FILE(GLOB DOCUMENT_HEADERS "include/document/*.hpp*")

set (TEST_SOURCES
	"plc_test/compiler.t.cpp"
)

add_executable(plc ${HEADERS} ${SOURCES} ${DOCUMENT_HEADERS} ${DOCUMENT_SOURCES} ${TEST_SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("src/document" FILES ${DOCUMENT_SOURCES})
source_group("include/document" FILES ${DOCUMENT_HEADERS})
source_group("test" FILES ${TEST_SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/document)
set_property(TARGET plc PROPERTY CXX_STANDARD 17)
set_property(TARGET plc PROPERTY CXX_STANDARD_REQUIRED ON)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
else()
	target_link_libraries(plc stdc++fs)	
endif()
#add_precompiled_header(plc "include/stdafx.hpp" FORCEINCLUDE SOURCE_CXX "src/stdafx.cpp")
target_link_libraries(
	plc
	parlex
	utilities
	LLVMAnalysis
	LLVMAsmParser
	LLVMAsmPrinter
	LLVMBinaryFormat
	LLVMBitReader
	LLVMBitWriter
	LLVMCodeGen
	LLVMCore
	LLVMCoroutines
	LLVMCoverage
	LLVMDebugInfoCodeView
	LLVMDebugInfoDWARF
	LLVMDebugInfoMSF
	LLVMDebugInfoPDB
	LLVMDemangle
	LLVMDlltoolDriver
	LLVMExecutionEngine
	LLVMFuzzMutate
	LLVMGlobalISel
	LLVMInstCombine
	LLVMInstrumentation
	LLVMInterpreter
	LLVMipo
	LLVMIRReader
	LLVMLibDriver
	LLVMLineEditor
	LLVMLinker
	LLVMLTO
	LLVMMC
	LLVMMCDisassembler
	LLVMMCJIT
	LLVMMCParser
	LLVMMIRParser
	LLVMObjCARCOpts
	LLVMObject
	LLVMObjectYAML
	LLVMOption
	LLVMOrcJIT
	LLVMPasses
	LLVMProfileData
	LLVMRuntimeDyld
	LLVMScalarOpts
	LLVMSelectionDAG
	LLVMSupport
	LLVMSymbolize
	LLVMTableGen
	LLVMTarget
	LLVMTransformUtils
	LLVMVectorize
	LLVMWindowsManifest
	LLVMX86AsmParser
	LLVMX86AsmPrinter
	LLVMX86CodeGen
	LLVMX86Desc
	LLVMX86Disassembler
	LLVMX86Info
	LLVMX86Utils
	LLVMXRay
	lldCommon
	lldCore	
	gtest
	gtest_main
)

add_test(NAME plc_test COMMAND "$<TARGET_FILE:plc>" --test)

# # copy plc to artifacts folder
# add_custom_command(
# 	TARGET plc
# 	POST_BUILD
# 	COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:plc>" "${ARTIFACTS_PREFIX}/bin/$<TARGET_FILE_NAME:plc>"
# )


