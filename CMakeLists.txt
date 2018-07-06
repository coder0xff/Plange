cmake_minimum_required (VERSION 3.10)
project(plange)
enable_testing()

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj") # MSVC++ fails without it
endif()

find_package(Git)
if (GIT_FOUND)
	message(INFO Initializing any uninitialized git submodules)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} fetch --recurse-submodules
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
	execute_process(
		COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
else()
	message(WARNING Git was not found. Uninitialized git submodules must be initialized manually.)
endif()

function(add_googletest)
	set(BUILD_GMOCK OFF CACHE BOOL "")
	set(BUILD_GTEST ON CACHE BOOL "")
	set(INSTALL_GMOCK OFF CACHE BOOL "")
	set(INSTALL_GTEST ON CACHE BOOL "")
    set(gtest_force_shared_crt ON CACHE BOOL "Force gtest to used shared VC++ CRT")
	add_subdirectory(source/googletest)
	include_directories("${gtest_SOURCE_DIR}/include")
endfunction(add_googletest)
add_googletest()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT MSVC) # Remove condition once CMAKE supports this with Visual Studio 2017
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

add_subdirectory(source/utilities)
add_subdirectory(source/mpl)
add_subdirectory(source/collections)
add_subdirectory(source/parlex)
add_subdirectory(source/plc)
add_subdirectory(source/grammar_gen)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT plc)

