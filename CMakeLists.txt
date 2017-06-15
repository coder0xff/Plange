cmake_minimum_required (VERSION 2.6)
include(ExternalProject)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/Modules/")

ExternalProject_Add(yaml-cpp
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp" 
	GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
	GIT_TAG 519d33fea3fbcbe7e1f89f97ee0fa539cec33eb7
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp/build"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/yaml-cpp"
)

ExternalProject_Add(llvm
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/llvm"
	GIT_REPOSITORY "https://github.com/llvm-mirror/llvm.git"
	GIT_TAG "release_39"
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/llvm/${CMAKE_CFG_INTDIR}/build"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/llvm" "-DLLVM_TARGETS_TO_BUILD=X86" "-DLLVM_ENABLE_RTTI=ON"
)

ExternalProject_Add(googletest
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/googletest"
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG 48ee8e98abc950abd8541e15550b18f8f6cfb3a9
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/googletest/${CMAKE_CFG_INTDIR}/build"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/googletest" "-Dgtest_force_shared_crt=ON"
)

ExternalProject_Add(plange
	DEPENDS yaml-cpp llvm googletest
	PREFIX "${CMAKE_BINARY_DIR}/prefix"
	SOURCE_DIR "${PROJECT_SOURCE_DIR}/source"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
	INSTALL_COMMAND ""
)
