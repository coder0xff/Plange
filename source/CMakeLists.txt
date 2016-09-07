cmake_minimum_required (VERSION 2.6)
project(plange)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(utilities)
add_subdirectory(parlex)
add_subdirectory(plc)
add_subdirectory(grammar_gen)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT plc)

