set (SOURCES
	"src/abstract_syntax_graph.cpp"
	"src/associativity_grammar.cpp"
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
	"src/precedence_grammar.cpp"
	"src/producer.cpp"
	"src/state_machine.cpp"
	"src/subjob.cpp"
	"src/token.cpp"
	"src/unicode.cpp"
	"src/wirth.cpp"
)

include_directories("include" "${PROJECT_SOURCE_DIR}/utilities")
add_library(parlex ${SOURCES})
set_property(TARGET parlex PROPERTY CXX_STANDARD 11)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
