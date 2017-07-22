#collect source files

set (SOURCES
	"mpl_dummy.cpp"
)

set (HEADERS
	"mpl_apply.hpp"
	"mpl_apply_values.hpp"
	"mpl_functor.hpp"
	"mpl_map_i.hpp"
	"mpl_map_values.hpp"
	"mpl_pop_value.hpp"
	"mpl_push.hpp"
	"mpl_push_value.hpp"
	"mpl_utils.hpp"
)
	
add_library(mpl ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")