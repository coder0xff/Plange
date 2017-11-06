cmake_minimum_required (VERSION 3.10)
project(plange)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(DEP_DIR "${CMAKE_BINARY_DIR}/../../../Dependencies" CACHE INTERNAL "Dependenies directory")

add_subdirectory(utilities)
add_subdirectory(mpl)
add_subdirectory(parlex)
add_subdirectory(plc)
add_subdirectory(grammar_gen)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT plc)

