set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

find_package(yaml-cpp REQUIRED HINTS "${CMAKE_BINARY_DIR}/yaml-cpp/CMake")

set(SOURCES
	"main.cpp")

add_executable(grammar_gen ${SOURCES})
source_group("src" FILES ${SOURCES})
include_directories("${CMAKE_SOURCE_DIR}/parlex/include")
include_directories("${CMAKE_SOURCE_DIR}/utilities")
include_directories("${YAML_CPP_INCLUDE_DIR}")
target_link_libraries(grammar_gen utilities parlex yaml-cpp)
set_property(TARGET grammar_gen PROPERTY CXX_STANDARD 11)
set_property(TARGET grammar_gen PROPERTY CXX_STANDARD_REQUIRED ON)
