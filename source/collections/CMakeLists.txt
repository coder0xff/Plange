add_subdirectory(collections_test)

set (SOURCES
	"collections_dummy.cpp"
)
	
set (HEADERS
	"coherent_queue.hpp"
	"coherent_set.hpp"
	"concurrent_forward_list.hpp"
	"mover.hpp"
    "coherent_map.hpp"
    "concurrent_auto_map.hpp"
)
	
add_library(collections ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET collections PROPERTY CXX_STANDARD 17)
set_property(TARGET collections PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")