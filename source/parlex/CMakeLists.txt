add_subdirectory(parlex_test)

set (SOURCES
	"src/abstract_syntax_semilattice.cpp"
	"src/behavior.cpp"
	"src/builder.cpp"
	"src/builtins.cpp"
	"src/c_string.cpp"
	"src/context.cpp"
	"src/cpp_generator.cpp"
	"src/document_representation.cpp"
	"src/grammar.cpp"
	"src/job.cpp"
	"src/match.cpp"
	"src/match_class.cpp"
	"src/parser.cpp"
	"src/producer.cpp"
	"src/raw_state_machine.cpp"
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
	"include/parlex/associativity.hpp"
	"include/parlex/builder.hpp"
	"include/parlex/cpp_generator.hpp"
	"include/parlex/document_representation.hpp"
	"include/parlex/filter_function.hpp"
	"include/parlex/post_processor.hpp"
	"include/parlex/precedence_collection.hpp"
)

set (DETAILS_HEADERS
	"include/parlex/details/abstract_syntax_semilattice.hpp"
	"include/parlex/details/any_character.hpp"
	"include/parlex/details/behavior.hpp"
	"include/parlex/details/builtins.hpp"
	"include/parlex/details/c_string.hpp"
	"include/parlex/details/concrete_syntax_tree.hpp"
	"include/parlex/details/context.hpp"
	"include/parlex/details/grammar.hpp"
	"include/parlex/details/grammar_base.hpp"
	"include/parlex/details/job.hpp"
	"include/parlex/details/match.hpp"
	"include/parlex/details/match_class.hpp"
	"include/parlex/details/nfa.hpp"
	"include/parlex/details/not_double_quote.hpp"
	"include/parlex/details/not_newline.hpp"
	"include/parlex/details/permutation.hpp"
	"include/parlex/details/parser.hpp"
	"include/parlex/details/producer.hpp"
	"include/parlex/details/raw_state_machine.hpp"
	"include/parlex/details/recognizer.hpp"
	"include/parlex/details/state_machine.hpp"
	"include/parlex/details/state_machine_base.hpp"
	"include/parlex/details/string_terminal.hpp"
	"include/parlex/details/subjob.hpp"
	"include/parlex/details/terminal.hpp"	
	"include/parlex/details/token.hpp"
	"include/parlex/details/transition.hpp"
	"include/parlex/details/unicode.hpp"
	"include/parlex/details/wirth.hpp"
)

source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("include\\builtins" FILES ${BUILTINS_HEADERS})
source_group("include\\details" FILES ${DETAILS_HEADERS})

include_directories("include" "${PROJECT_SOURCE_DIR}/utilities" "${PROJECT_SOURCE_DIR}/mpl")
add_library(parlex ${SOURCES} ${HEADERS} ${BUILTINS_HEADERS} ${DETAILS_HEADERS})
set_property(TARGET parlex PROPERTY CXX_STANDARD 17)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
