cmake_minimum_required (VERSION 3.10)
project(plange)
enable_testing()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
function (add_subdirectory folder_name)
	if (NOT DEFINED ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX)
		set(ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX "" STRING)
	endif()
	set(ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX "${ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX}/${folder_name}" STRING)

	function (add_library name type)
		_add_library (${ARGV})
		# Do not wrap creation of INTERFACE libraries
		if (type STREQUAL INTERFACE)
			return()
		endif()

		set_target_properties(${name}
			PROPERTIES
			FOLDER "${ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX}"
		)
	endfunction()

	function (add_executable name)
		_add_executable (${ARGV})
		set_target_properties(${name}
			PROPERTIES
			FOLDER "${ADD_SUBDIRECTORY_WITH_FOLDER_PREFIX}"
		)
	endfunction()

	_add_subdirectory (${ARGN})
endfunction()

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj") # MSVC++ fails without it
endif()

find_package(Git)
if (GIT_FOUND)
	mark_as_advanced(
		FORCE
		git_executable
	)
	message(INFO " Initializing git submodules...")
	execute_process(
		COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
else()
	message(WARNING " Git was not found. Uninitialized git submodules must be initialized manually.")
endif()

function(add_googletest)
	set(BUILD_GMOCK OFF CACHE BOOL "")
	set(BUILD_GTEST ON CACHE BOOL "")
	set(INSTALL_GMOCK OFF CACHE BOOL "")
	set(INSTALL_GTEST ON CACHE BOOL "")
		set(gtest_force_shared_crt ON CACHE BOOL "Force gtest to used shared VC++ CRT")
	add_subdirectory(source/googletest)
	include_directories("${gtest_SOURCE_DIR}/include")

	mark_as_advanced(
		FORCE
		BUILD_GMOCK
		BUILD_GTEST
		BUILD_SHARED_LIBS
		gtest_build_samples
		gtest_build_tests
		gtest_disable_pthreads
		gtest_force_shared_crt
		gtest_hide_internal_symbols
		INSTALL_GMOCK
		INSTALL_GTEST
	)
endfunction(add_googletest)
add_googletest()

if(NOT MSVC) # Remove condition once CMAKE supports this with Visual Studio 2017
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

add_subdirectory(source/utilities)
add_subdirectory(source/mpl)
add_subdirectory(source/collections)
add_subdirectory(source/plc)
add_subdirectory(source/grammar_gen)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT plc)
