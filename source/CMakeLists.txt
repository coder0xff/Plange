cmake_minimum_required (VERSION 2.6)
project(plange)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(utilities)
add_subdirectory(parlex)
add_subdirectory(plc)

