include_directories("${DEP_DIR}/googletest/include")
link_directories("${DEP_DIR}/googletest/lib")

set (SOURCES
	"concurrent_forward_list.t.cpp"
)

add_executable(collections_test ${SOURCES})
find_package (Threads)
target_link_libraries(collections_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET collections_test PROPERTY CXX_STANDARD 17)
set_property(TARGET collections_test PROPERTY CXX_STANDARD_REQUIRED ON)

add_test(NAME collections_test COMMAND "$<TARGET_FILE:collections_test>")

# copy utilities_test to artifacts folder
add_custom_command(
	TARGET collections_test
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:collections_test>" "${ARTIFACTS_PREFIX}/bin/$<TARGET_FILE_NAME:collections_test>"
)
