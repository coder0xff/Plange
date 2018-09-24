include_directories("${PROJECT_SOURCE_DIR}/source/utilities")

find_package (Threads)

SET(SOURCES
	"bits.test.cpp"
	"val.test.cpp"
	"tarjan.test.cpp"
	"utf.test.cpp"
)

add_executable(utilities_test ${SOURCES})
target_link_libraries(utilities_test gtest gtest_main utilities ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET utilities_test PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities_test PROPERTY CXX_STANDARD_REQUIRED ON)

add_test(NAME utilities_test COMMAND "$<TARGET_FILE:utilities_test>")

# # copy utilities_test to artifacts folder
# add_custom_command(
# 	TARGET utilities_test
# 	POST_BUILD
# 	COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:utilities_test>" "${ARTIFACTS_PREFIX}/bin/$<TARGET_FILE_NAME:utilities_test>"
# )
