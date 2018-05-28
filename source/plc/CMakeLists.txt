set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
#include(PrecompiledHeader)

find_package(LLVM 6.0 REQUIRED HINTS "${DEP_DIR}/llvm/lib/cmake/llvm")
include_directories("${LLVM_INCLUDE_DIRS}")

set(LLD_INCLUDE_DIRS "${DEP_DIR}/lld/include")
set(LLD_LIB_DIR "${DEP_DIR}/lld/lib")
find_library(LLDCore lldCore "${LLD_LIB_DIR}")
find_library(LLDCommon lldCommon "${LLD_LIB_DIR}")

include_directories("${DEP_DIR}/googletest/include")
link_directories("${DEP_DIR}/googletest/lib")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") #for tclap
include_directories("${PROJECT_SOURCE_DIR}/utilities")
include_directories("${PROJECT_SOURCE_DIR}/mpl")
include_directories("${PROJECT_SOURCE_DIR}/collections")
include_directories("${PROJECT_SOURCE_DIR}/parlex/include")

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
	${LLDCore}
	${LLDCommon}
	gtest
	gtest_main
)

add_test(NAME plc_test COMMAND "$<TARGET_FILE:plc>" --test)

# copy plc to artifacts folder
add_custom_command(
	TARGET plc
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:plc>" "${ARTIFACTS_PREFIX}/bin/$<TARGET_FILE_NAME:plc>"
)


