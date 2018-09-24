add_subdirectory(utilities_test)

#collect source files
set (SOURCES
	"logging.cpp"
	"perf_timer.cpp"
	"tarjan.cpp"
	"thread_pool.cpp"
	"utf.cpp"
	"utils.cpp"
)
	
set (HEADERS
	"bits.hpp"
	"covariant_invoke.hpp"
	"graphviz_dot.hpp"
	"logging.hpp"
	"perf_timer.hpp"
	"pointer.hpp"
	"tarjan.hpp"
	"thread_pool.hpp"
	"utf.hpp"
	"utils.hpp"
	"val.hpp"
	"wait_flag.hpp"
)
	
add_library(utilities ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")