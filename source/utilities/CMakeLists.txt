#collect source files
file (GLOB SRC_FILES *.cpp)
add_library(utilities ${SRC_FILES})
set_property(TARGET utilities PROPERTY CXX_STANDARD 11)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
