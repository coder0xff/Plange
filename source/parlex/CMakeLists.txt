add_subdirectory(parlex_test)

set (SOURCES
	"src/abstract_syntax_graph.cpp"
	"src/behavior.cpp"
	"src/builtins.cpp"
	"src/c_string.cpp"
	"src/context.cpp"
	"src/grammar.cpp"
	"src/job.cpp"
	"src/match.cpp"
	"src/match_class.cpp"
	"src/nfa.cpp"
	"src/parser.cpp"
	"src/producer.cpp"
	"src/state_machine.cpp"
	"src/subjob.cpp"
	"src/token.cpp"
	"src/unicode.cpp"
	"src/wirth.cpp"
)

set (HEADERS
	"include/parlex/abstract_syntax_graph.hpp"
	"include/parlex/associativity.hpp"
	"include/parlex/builtins.hpp"
	"include/parlex/filter_function.hpp"
	"include/parlex/grammar.hpp"
	"include/parlex/match.hpp"
	"include/parlex/match_class.hpp"
	"include/parlex/parser.hpp"
	"include/parlex/permutation.hpp"
	"include/parlex/precedence_collection.hpp"
	"include/parlex/recognizer.hpp"
	"include/parlex/state_machine.hpp"
	"include/parlex/terminal.hpp"
	"include/parlex/token.hpp")

set (BUILTINS_HEADERS
	"include/parlex/builtins/any_character.hpp"
	"include/parlex/builtins/c_string.hpp"
	"include/parlex/builtins/greedy.hpp"
	"include/parlex/builtins/not_double_quote.hpp"
	"include/parlex/builtins/not_newline.hpp"
	"include/parlex/builtins/progress_bar.hpp"
	"include/parlex/builtins/set_terminal.hpp"
	"include/parlex/builtins/string_terminal.hpp"
	"include/parlex/builtins/unicode.hpp"
	"include/parlex/builtins/wirth.hpp")

set (DETAILS_HEADERS
	"include/parlex/details/auto_map.hpp"
	"include/parlex/details/behavior.hpp"
	"include/parlex/details/context.hpp"
	"include/parlex/details/job.hpp"
	"include/parlex/details/nfa.hpp"
	"include/parlex/details/partial_abstract_syntax_graph.hpp"
	"include/parlex/details/producer.hpp"
	"include/parlex/details/subjob.hpp")

source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("include\\builtins" FILES ${BUILTINS_HEADERS})
source_group("include\\details" FILES ${DETAILS_HEADERS})

include_directories("include" "${PROJECT_SOURCE_DIR}/utilities")
add_library(parlex ${SOURCES} ${HEADERS} ${BUILTINS_HEADERS} ${DETAILS_HEADERS})
set_property(TARGET parlex PROPERTY CXX_STANDARD 11)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
