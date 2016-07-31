cmake_minimum_required (VERSION 2.6)
project(plc)

if(NOT PLANGE_BIN)
	message(FATAL_ERROR "The PLANGE_BIN variable is not set")
endif (NOT PLANGE_BIN)

if (NOT LLVM_VERSION)
	message(FATAL ERROR "The LLVM_VERSION variable is not set")
endif (NOT LLVM_VERSION)

if(NOT PLANGE_SRC)
	message(FATAL_ERROR "The PLANGE_SRC variable is not set")
endif (NOT PLANGE_SRC)

include(${PLANGE_BIN}/llvm-${LLVM_VERSION}/share/llvm/cmake/LLVMConfig.cmake)
include_directories(${LLVM_INCLUDE_DIRS} ${PLANGE_SRC}/utilities/ ${PLANGE_SRC}/parlex/include/)
link_directories(${LLVM_LIBRARY_DIRS} ${PLANGE_BIN}/parlex ${PLANGE_BIN}/utilities)

#collect source files
file (GLOB SRC_FILES src/*.cpp)
include_directories(. include)

# add the binary tree to the search path for include files
# so that we will find plangeConfig.hpp
include_directories()

add_executable(plc ${SRC_FILES})
target_link_libraries(plc parlex utilities LLVMCore LLVMSupport)
set_property(TARGET plc PROPERTY CXX_STANDARD 11)
set_property(TARGET plc PROPERTY CXX_STANDARD_REQUIRED ON)

install(FILES ${PLANGE_BIN}/plc_build/plc DESTINATION ${PLANGE_BIN} PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
