cmake_minimum_required (VERSION 3.8)
project(plange_superbuild)
enable_testing()
include(ExternalProject)

find_package(YAML-CPP QUIET)
if (NOT YAML-CPP_FOUND)
	set(YAML-CPP_INSTALL_TARGET "yaml-cpp")
	ExternalProject_Add(yaml-cpp
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp" 
		GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
		GIT_TAG 519d33fea3fbcbe7e1f89f97ee0fa539cec33eb7
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/yaml-cpp/build"
		CMAKE_ARGS
			"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
			"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/yaml-cpp"
	)
endif()

find_package(LLVM 6.0 QUIET)
if (NOT LLVM_FOUND)
	set(LLVM_INSTALL_TARGET "llvm")
	ExternalProject_Add(llvm
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/llvm"
		GIT_REPOSITORY "https://github.com/llvm-mirror/llvm.git"
		GIT_TAG c80a0ef3c0cda8ed483d0291170aefb30fe65381
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/llvm/${CMAKE_CFG_INTDIR}/build"
		CMAKE_ARGS
			"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/llvm"
			"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
			"-DLLVM_TARGETS_TO_BUILD=X86"
			"-DLLVM_ENABLE_RTTI=ON"
	)
else()
	if(NOT MSVC)
		# LLVM-3.9-dev package doesn't reference zlib1g-dev package
		# plc won't link without it
		# TODO: Maybe this wont be needed in 5.0 release
#		find_package(ZLIB 1 REQUIRED)
	endif()
endif()

# don't bother with find_package, because it does not include the libraries https://askubuntu.com/questions/145887/why-no-library-files-installed-for-google-test
ExternalProject_Add(googletest
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/googletest"
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG d175c8bf823e709d570772b038757fadf63bc632 
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/googletest/${CMAKE_CFG_INTDIR}/build"
	CMAKE_ARGS
		"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/googletest"
		"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
		"-DCMAKE_DEBUG_POSTFIX=''"
		"-Dgtest_force_shared_crt=ON"
)

set(ARTIFACTS_PREFIX "${CMAKE_BINARY_DIR}/artifacts" CACHE PATH "Location to copy useful build outputs")

ExternalProject_Add(plange
	DEPENDS ${YAML-CPP_INSTALL_TARGET} ${LLVM_INSTALL_TARGET} googletest
	PREFIX "${CMAKE_BINARY_DIR}/prefix"
	SOURCE_DIR "${PROJECT_SOURCE_DIR}/source"
	CMAKE_ARGS
		"-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
		"-DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
		"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
		"-DARTIFACTS_PREFIX=${ARTIFACTS_PREFIX}"
	INSTALL_COMMAND ""
)

add_test(NAME plange_test COMMAND "${ARTIFACTS_PREFIX}/bin/plc${CMAKE_EXECUTABLE_SUFFIX}" --test)
