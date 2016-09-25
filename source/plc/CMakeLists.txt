set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
include(PrecompiledHeader)
include(depend)

#dependency on LLVM
set(LLVM_VERSION 3.8.1)
depend("LLVM" "http://llvm.org/releases/${LLVM_VERSION}/llvm-${LLVM_VERSION}.src.tar.xz" ".tar.xz" "share/llvm/cmake/LLVMConfig.cmake" "")

if(${MSVC})
	include(msvc_fetch_mpir)
	include_directories("${PROJECT_BINARY_DIR}/mpir")
endif()

#Prep build for symengine
set(PLC_SYMENGINE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/symengine.build")
file(MAKE_DIRECTORY "${PLC_SYMENGINE_BINARY_DIR}")
execute_process(COMMAND "${CMAKE_COMMAND}" "${CMAKE_CURRENT_SOURCE_DIR}/symengine" "-G" "${CMAKE_GENERATOR}" "-DGMP_LIBRARIES=${GMP_LIBRARIES}" "-DGMP_INCLUDE_DIRS=${GMP_INCLUDE_DIRS}" "-DGMP_TARGETS=${GMP_LIBRARIES}" "-DCMAKE_BUILD_TYPE=Debug" WORKING_DIRECTORY "${PLC_SYMENGINE_BINARY_DIR}" RESULT_VARIABLE PLC_SYMENGINE_CMAKE_RESULT)
if(${PLC_SYMENGINE_CMAKE_RESULT})
	message(FATAL_ERROR "Unable to configure symengine. Check output for errors.")
endif()
include(msvc_symengine_mdd)
add_custom_target(symengine_build
	"${CMAKE_COMMAND}" "--build" "${PLC_SYMENGINE_BINARY_DIR}"
)

include_directories("${CMAKE_SOURCE_DIR}/parlex/include")
include_directories("${CMAKE_SOURCE_DIR}/utilities")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}") #for tclap
include_directories("${LLVM_INCLUDE_DIRS}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/symengine")
include_directories("${PLC_SYMENGINE_BINARY_DIR}")
include_directories("${PLC_SYMENGINE_BINARY_DIR}/symengine/utilities/teuchos")
link_directories("${PLC_SYMENGINE_BINARY_DIR}/symengine/utilities/teuchos/${CMAKE_BUILD_TYPE}")
link_directories("${PLC_SYMENGINE_BINARY_DIR}/symengine/${CMAKE_BUILD_TYPE}")
add_definitions(${LLVM_DEFINITIONS})

set(SOURCES
	"src/errors.cpp"
	"src/main.cpp"
	"src/plange_grammar.cpp"
	"src/scope.cpp"
	"src/source_code.cpp"
	"src/stdafx.cpp"
	"src/stdlib.cpp"
	"src/warnings.cpp")

set(HEADERS
	"include/errors.hpp"
	"include/plange_grammar.hpp"
	"include/scope.hpp"
	"include/source_code.hpp"
	"include/stdafx.hpp"
	"include/stdlib.hpp"
	"include/warnings.hpp")

add_executable(plc ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set_property(TARGET plc PROPERTY CXX_STANDARD 11)
set_property(TARGET plc PROPERTY CXX_STANDARD_REQUIRED ON)
add_precompiled_header(plc "include/stdafx.hpp" FORCEINCLUDE SOURCE_CXX "src/stdafx.cpp")
target_link_libraries(plc parlex utilities LLVMCore LLVMSupport teuchos symengine)
add_dependencies(plc symengine_build)

