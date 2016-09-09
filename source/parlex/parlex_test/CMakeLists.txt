set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
include(depend)

set(GOOGLETEST_REVISION 48ee8e98abc950abd8541e15550b18f8f6cfb3a9)
depend("googletest" "https://github.com/google/googletest/archive/${GOOGLETEST_REVISION}.zip" ".zip" "" "-Dgtest_force_shared_crt=ON")

include_directories("${PROJECT_SOURCE_DIR}/parlex/include")
include_directories("${PROJECT_SOURCE_DIR}/utilities")
include_directories("${PROJECT_BINARY_DIR}/googletest/include")
link_directories("${PROJECT_BINARY_DIR}/googletest/lib")

add_executable(parlex_test "test.cpp")
target_link_libraries(parlex_test gtest gtest_main parlex utilities)
set_property(TARGET parlex_test PROPERTY CXX_STANDARD 11)
set_property(TARGET parlex_test PROPERTY CXX_STANDARD_REQUIRED ON)
