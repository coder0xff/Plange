include(ExternalProject)

#dependency on LLVM
set(LLVM_VERSION 3.8.1)
ExternalProject_Add(
	llvm
	PREFIX /var/tmp/llvm-${LLVM_VERSION}.src
	BINARY_DIR /var/tmp/llvm-${LLVM_VERSION}.build
	URL http://llvm.org/releases/${LLVM_VERSION}/llvm-${LLVM_VERSION}.src.tar.xz
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/llvm-${LLVM_VERSION} -DLLVM_INCLUDE_DOCS=No -DLLVM_INCLUDE_EXAMPLES=No -DLLVM_INCLUDE_GO_TESTS=No -DLLVM_INCLUDE_TESTS=No -DLLVM_INCLUDE_TOOLS=No -DLLVM_INCLUDE_UTILS=No
)
include_directories(${PROJECT_BINARY_DIR}/llvm-${LLVM_VERSION}/include)

#collect source files
file (GLOB SRC_FILES src/*.cpp)
include_directories(. include ../utilities ../parlex/include)

# add the binary tree to the search path for include files
# so that we will find plangeConfig.hpp
include_directories("${PROJECT_BINARY_DIR}")

add_executable(plc ${SRC_FILES})
add_dependencies(plc llvm)
set_property(TARGET parlex PROPERTY CXX_STANDARD 11)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)