#collect source files
set (SOURCES
	"logging.cpp"
	"one_shot.cpp"
	"perf_timer.cpp"
	"utils.cpp")
	
set (HEADERS
	"logging.hpp"
	"one_shot.hpp"
	"perf_timer.hpp"
	"utils.hpp")
	
add_library(utilities ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 11)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
