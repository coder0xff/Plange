cmake_minimum_required (VERSION 2.6)
project (plange)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++11")


# The version number.
set (plange_VERSION_MAJOR 0)
set (plange_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/plangeConfig.hpp.in"
	"${PROJECT_BINARY_DIR}/plangeConfig.hpp"
)


add_subdirectory(utilities)
add_subdirectory(parlex)
add_subdirectory(plc)
