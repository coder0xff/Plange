#collect source files
file (GLOB SRC_FILES *.cpp)
add_library(stdlib_cpp ${SRC_FILES})
set_property(TARGET stdlib_cpp PROPERTY CXX_STANDARD 11)
set_property(TARGET stdlib_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
