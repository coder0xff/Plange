#collect source files
set (SOURCES
	"logging.cpp"
	"one_shot.cpp"
	"perf_timer.cpp"
	"utils.cpp")
	
set (HEADERS
	"auto_map_c.hpp"
	"forward_list_c.hpp"
	"logging.hpp"
	"one_shot.hpp"
	"perf_timer.hpp"
	"erased.hpp"
	"utils.hpp")
	
add_library(utilities ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 11)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
