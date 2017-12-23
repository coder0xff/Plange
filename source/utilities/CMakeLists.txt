add_subdirectory(utilities_test)

#collect source files
set (SOURCES
	"graphviz_dot.cpp"
	"logging.cpp"
	"one_shot.cpp"
	"perf_timer.cpp"
	"utils.cpp"
	"utf.cpp")
	
set (HEADERS
	"bits.hpp"
	"covariant_invoke.hpp"
	"graphviz_dot.hpp"
	"logging.hpp"
	"one_shot.hpp"
	"perf_timer.hpp"
	"erased.hpp"
	"utils.hpp"
	"utf.hpp")
	
add_library(utilities ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")