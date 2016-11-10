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
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/llvm" "-DLLVM_TARGETS_TO_BUILD=X86"
)

if(${MSVC})
	function(get_msvc_short_ver OUTPUT_VARIABLE)
		set(MSVC_VERSION_TABLE "1600:10;1700:11;1800:12;1900:14;")	
		string(REGEX MATCH "${MSVC_VERSION}:[0-9]+;" ENTRY "${MSVC_VERSION_TABLE}")
		string(LENGTH ${MSVC_VERSION} L)
		string(SUBSTRING "${ENTRY}" ${L} -1 RESULT)
		string(SUBSTRING "${RESULT}" 1 -1 RESULT)
		string(LENGTH "${RESULT}" L)
		string(SUBSTRING "${RESULT}" 0 ${L} RESULT)
		set(${OUTPUT_VARIABLE} ${RESULT} PARENT_SCOPE)
	endfunction()

	include(vsyasm_install)
	get_msvc_short_ver(MSVC_SHORT_VER)
	file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/Dependencies/mpir/")
	ExternalProject_Add(mpir
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/mpir/prefix"
		GIT_REPOSITORY "https://github.com/wbhart/mpir.git"
		GIT_TAG 622672e868d15a0186922c08bac2037182600f3b
		CONFIGURE_COMMAND ""
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/mpir/prefix/src/mpir/build.vc${MSVC_SHORT_VER}"
		BUILD_COMMAND 
			"${CMAKE_BINARY_DIR}/Downloads/mpir/prefix/src/mpir/build.vc${MSVC_SHORT_VER}/msbuild.bat"
			"gc" "LIB" "win32" "${CMAKE_CFG_INTDIR}"
		INSTALL_COMMAND
			"${CMAKE_COMMAND}" "-E" "copy_if_different"
			"${CMAKE_BINARY_DIR}/Downloads/mpir/prefix/src/mpir/lib/win32/${CMAKE_CFG_INTDIR}/gmp.h"
			"${CMAKE_BINARY_DIR}/Downloads/mpir/prefix/src/mpir/lib/win32/${CMAKE_CFG_INTDIR}/mpir.lib"
			"${CMAKE_BINARY_DIR}/Dependencies/mpir/"
	)

	ExternalProject_Add(symengine
		DEPENDS mpir
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/symengine/prefix"
		GIT_REPOSITORY "https://github.com/symengine/symengine.git"
		GIT_TAG 5d123c0e321b8f7a323599092f7cf11045bf77ee
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/symengine/${CMAKE_CFG_INTDIR}/build"
		CONFIGURE_COMMAND ""
		BUILD_COMMAND
			"${CMAKE_COMMAND}"
			"${CMAKE_BINARY_DIR}/Downloads/symengine/prefix/src/symengine"
			"-G" "${CMAKE_GENERATOR}"
			"-DGMP_LIBRARY=${CMAKE_BINARY_DIR}/Dependencies/mpir/mpir.lib"
			"-DGMP_INCLUDE_DIR=${CMAKE_BINARY_DIR}/Dependencies/mpir"
			"-DCMAKE_BUILD_TYPE=${CMAKE_CFG_INTDIR}"
			"-DMSVC_USE_MT=0"
			"-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/symengine"
		INSTALL_COMMAND "${CMAKE_COMMAND}" "--build" "${CMAKE_BINARY_DIR}/Downloads/symengine/${CMAKE_CFG_INTDIR}/build" "--target" "INSTALL"
	)
else()
	ExternalProject_Add(symengine
		PREFIX "${CMAKE_BINARY_DIR}/Downloads/symengine/prefix"
		GIT_REPOSITORY "https://github.com/symengine/symengine.git"
		GIT_TAG 5d123c0e321b8f7a323599092f7cf11045bf77ee
		BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/symengine/build"
		CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/symengine"
	)
endif()


ExternalProject_Add(googletest
	PREFIX "${CMAKE_BINARY_DIR}/Downloads/googletest"
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG 48ee8e98abc950abd8541e15550b18f8f6cfb3a9
	BINARY_DIR "${CMAKE_BINARY_DIR}/Downloads/googletest/${CMAKE_CFG_INTDIR}/build"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/googletest" "-Dgtest_force_shared_crt=ON"
)

ExternalProject_Add(plange
	DEPENDS yaml-cpp llvm symengine googletest
	PREFIX "${CMAKE_BINARY_DIR}/prefix"
	SOURCE_DIR "${PROJECT_SOURCE_DIR}/source"
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
	INSTALL_COMMAND ""
)
