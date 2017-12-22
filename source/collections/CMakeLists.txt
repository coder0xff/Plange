add_subdirectory(collections_test)

set (SOURCES
	"collections_dummy.cpp"
)
	
set (HEADERS
	"concurrent_forward_list.hpp"
)
	
add_library(collections ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")