set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
#include(PrecompiledHeader)

include("${DEP_DIR}/llvm/lib/cmake/llvm/LLVMConfig.cmake")
add_definitions(${LLVM_DEFINITIONS})
include_directories("${LLVM_INCLUDE_DIRS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") #for tclap

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../parlex/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../utilities")

set(SOURCES
	"src/abstract_value.cpp"
	"src/compiler.cpp"
	"src/concrete_value.cpp"
	"src/errors.cpp"
	"src/main.cpp"
	"src/module.cpp"
	"src/plange_grammar.cpp"
	"src/scope.cpp"
	"src/source_code.cpp"
	"src/statement.cpp"
	"src/stdafx.cpp"
	"src/stdlib.cpp"
	"src/symbol.cpp"
	"src/warnings.cpp")

set(HEADERS
	"include/abstract_value.hpp"
	"include/compiler.hpp"
	"include/concrete_value.hpp"
	"include/errors.hpp"
	"include/module.hpp"
	"include/plange_grammar.hpp"
	"include/relation.hpp"
	"include/scope.hpp"
	"include/source_code.hpp"
	"include/statement.hpp"
	"include/stdafx.hpp"
	"include/stdlib.hpp"
	"include/symbol.hpp"
	"include/warnings.hpp")

add_executable(plc ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set_property(TARGET plc PROPERTY CXX_STANDARD 11)
set_property(TARGET plc PROPERTY CXX_STANDARD_REQUIRED ON)
#add_precompiled_header(plc "include/stdafx.hpp" FORCEINCLUDE SOURCE_CXX "src/stdafx.cpp")
target_link_libraries(plc parlex utilities LLVMCore LLVMSupport)
