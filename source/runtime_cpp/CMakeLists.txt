#collect source files
file (GLOB SRC_FILES *.cpp)
add_library(runtime_cpp ${SRC_FILES})
set_property(TARGET runtime_cpp PROPERTY CXX_STANDARD 11)
set_property(TARGET runtime_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
