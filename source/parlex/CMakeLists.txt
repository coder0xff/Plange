add_subdirectory(parlex_test)

set (SOURCES
	"src/abstract_syntax_graph.cpp"
	"src/behavior.cpp"
	"src/builtins.cpp"
	"src/c_string.cpp"
	"src/context.cpp"
	"src/correlated_grammar.cpp"
	"src/correlated_state_machine.cpp"
	"src/grammar.cpp"
	"src/grammar_base.cpp"
	"src/job.cpp"
	"src/match.cpp"
	"src/match_class.cpp"
	"src/parser.cpp"
	"src/producer.cpp"
	"src/recognizer.cpp"
	"src/state_machine.cpp"
	"src/state_machine_base.cpp"
	"src/subjob.cpp"
	"src/terminal.cpp"
	"src/token.cpp"
	"src/unicode.cpp"
	"src/wirth.cpp"
)

set (HEADERS
	"include/parlex/abstract_syntax_graph.hpp"
	"include/parlex/associativity.hpp"
	"include/parlex/behavior.hpp"
	"include/parlex/builder.hpp"
	"include/parlex/builtins.hpp"
	"include/parlex/correlated_grammar.hpp"
	"include/parlex/correlated_state_machine.hpp"
	"include/parlex/document_representation.hpp"
	"include/parlex/filter_function.hpp"
	"include/parlex/grammar.hpp"
	"include/parlex/grammar_base.hpp"
	"include/parlex/grammar_definition.hpp"
	"include/parlex/match.hpp"
	"include/parlex/match_class.hpp"
	"include/parlex/parser.hpp"
	"include/parlex/permutation.hpp"
	"include/parlex/post_processor.hpp"
	"include/parlex/precedence_collection.hpp"
	"include/parlex/recognizer.hpp"
	"include/parlex/state_machine.hpp"
	"include/parlex/state_machine_base.hpp"
	"include/parlex/terminal.hpp"
	"include/parlex/token.hpp"
)

set (DETAILS_HEADERS
	"include/parlex/details/any_character.hpp"
	"include/parlex/details/auto_map.hpp"
	"include/parlex/details/c_string.hpp"
	"include/parlex/details/context.hpp"
	"include/parlex/details/job.hpp"
	"include/parlex/details/nfa.hpp"
	"include/parlex/details/not_double_quote.hpp"
	"include/parlex/details/not_newline.hpp"
	"include/parlex/details/producer.hpp"
	"include/parlex/details/string_terminal.hpp"
	"include/parlex/details/subjob.hpp"
	"include/parlex/details/unicode.hpp"
	"include/parlex/details/wirth.hpp"
)

source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("include\\builtins" FILES ${BUILTINS_HEADERS})
source_group("include\\details" FILES ${DETAILS_HEADERS})

include_directories("include" "${PROJECT_SOURCE_DIR}/utilities")
add_library(parlex ${SOURCES} ${HEADERS} ${BUILTINS_HEADERS} ${DETAILS_HEADERS})
set_property(TARGET parlex PROPERTY CXX_STANDARD 17)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
