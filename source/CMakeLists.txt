cmake_minimum_required (VERSION 2.6)
project(plange)

include(ExternalProject)

add_subdirectory(utilities)
add_subdirectory(parlex)

#dependency on LLVM
set(LLVM_VERSION 3.8.1)
ExternalProject_Add(
	llvm
	PREFIX ${PROJECT_BINARY_DIR}/llvm-${LLVM_VERSION}.src
	BINARY_DIR ${PROJECT_BINARY_DIR}/llvm-${LLVM_VERSION}.build
	URL http://llvm.org/releases/${LLVM_VERSION}/llvm-${LLVM_VERSION}.src.tar.xz
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/llvm-${LLVM_VERSION} -DLLVM_INCLUDE_DOCS=No -DLLVM_INCLUDE_EXAMPLES=No -DLLVM_INCLUDE_GO_TESTS=No -DLLVM_INCLUDE_TESTS=No -DLLVM_INCLUDE_TOOLS=No -DLLVM_INCLUDE_UTILS=No
)

ExternalProject_Add(
	plc
	PREFIX ${PROJECT_BINARY_DIR}/plc_build
	BINARY_DIR ${PROJECT_BINARY_DIR}/plc_build
	SOURCE_DIR ${PROJECT_SOURCE_DIR}/plc
	CMAKE_ARGS -DLLVM_VERSION=${LLVM_VERSION} -DPLANGE_SRC=${PROJECT_SOURCE_DIR} -DPLANGE_BIN=${PROJECT_BINARY_DIR} -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/plc
)

add_dependencies(plc llvm utilities parlex)
