set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
#include(PrecompiledHeader)

find_package(LLVM 6.0 REQUIRED HINTS "${DEP_DIR}/llvm/lib/cmake/llvm")
include_directories("${LLVM_INCLUDE_DIRS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") #for tclap
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../parlex/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../mpl")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../utilities")

set(SOURCES
	"src/analytic_value.cpp"
	"src/compiler.cpp"
	"src/document.cpp"
	"src/errors.cpp"
	"src/main.cpp"
	"src/module.cpp"
	"src/natural_value.cpp"
	"src/scope.cpp"
	"src/source_code.cpp"
	"src/statement.cpp"
	"src/stdafx.cpp"
	"src/stdlib.cpp"
	"src/symbol.cpp"
	"src/warnings.cpp")

set(HEADERS
	"include/analytic_value.hpp"
	"include/compiler.hpp"
	"include/document.hpp"
	"include/errors.hpp"
	"include/module.hpp"
	"include/natural_value.hpp"
	"include/relation.hpp"
	"include/scope.hpp"
	"include/source_code.hpp"
	"include/statement.hpp"
	"include/stdafx.hpp"
	"include/stdlib.hpp"
	"include/symbol.hpp"
	"include/warnings.hpp")

FILE(GLOB DOCUMENT_SOURCES "src/document/*.cpp")
FILE(GLOB DOCUMENT_HEADERS "include/document/*.hpp")

add_executable(plc ${HEADERS} ${SOURCES} ${DOCUMENT_HEADERS} ${DOCUMENT_SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("src/document" FILES ${DOCUMENT_SOURCES})
source_group("include/document" FILES ${DOCUMENT_HEADERS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/document)
set_property(TARGET plc PROPERTY CXX_STANDARD 17)
set_property(TARGET plc PROPERTY CXX_STANDARD_REQUIRED ON)
#add_precompiled_header(plc "include/stdafx.hpp" FORCEINCLUDE SOURCE_CXX "src/stdafx.cpp")
target_link_libraries(plc parlex utilities LLVMCore LLVMSupport)
