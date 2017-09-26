include_directories("${PROJECT_SOURCE_DIR}/utilities")
include_directories("${DEP_DIR}/googletest/include")
link_directories("${DEP_DIR}/googletest/lib")

find_package (Threads)

SET(SOURCES
	"erased.test.cpp"
	"utf.test.cpp"
)

add_executable(utilities_test ${SOURCES})
target_link_libraries(utilities_test gtest gtest_main utilities ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET utilities_test PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities_test PROPERTY CXX_STANDARD_REQUIRED ON)
 