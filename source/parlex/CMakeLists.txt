add_subdirectory(parlex_test)

set (SOURCES
	"src/abstract_syntax_semilattice.cpp"
	"src/abstract_syntax_tree.cpp"
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

set (DETAIL_HEADERS
	"include/parlex/detail/abstract_syntax_semilattice.hpp"
	"include/parlex/detail/abstract_syntax_tree.hpp"
	"include/parlex/detail/any_character.hpp"
	"include/parlex/detail/behavior.hpp"
	"include/parlex/detail/builtins.hpp"
	"include/parlex/detail/c_string.hpp"
	"include/parlex/detail/context.hpp"
	"include/parlex/detail/document.hpp"
	"include/parlex/detail/grammar.hpp"
	"include/parlex/detail/grammar_base.hpp"
	"include/parlex/detail/job.hpp"
	"include/parlex/detail/match.hpp"
	"include/parlex/detail/match_class.hpp"
	"include/parlex/detail/nfa.hpp"
	"include/parlex/detail/not_double_quote.hpp"
	"include/parlex/detail/not_newline.hpp"
	"include/parlex/detail/permutation.hpp"
	"include/parlex/detail/parser.hpp"
	"include/parlex/detail/producer.hpp"
	"include/parlex/detail/raw_state_machine.hpp"
	"include/parlex/detail/recognizer.hpp"
	"include/parlex/detail/state_machine.hpp"
	"include/parlex/detail/state_machine_base.hpp"
	"include/parlex/detail/string_terminal.hpp"
	"include/parlex/detail/subjob.hpp"
	"include/parlex/detail/terminal.hpp"	
	"include/parlex/detail/token.hpp"
	"include/parlex/detail/transition.hpp"
	"include/parlex/detail/unicode.hpp"
	"include/parlex/detail/wirth.hpp"
)

source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
source_group("include\\builtins" FILES ${BUILTINS_HEADERS})
source_group("include\\detail" FILES ${DETAIL_HEADERS})

include_directories("include" "${PROJECT_SOURCE_DIR}/utilities" "${PROJECT_SOURCE_DIR}/mpl")
add_library(parlex ${SOURCES} ${HEADERS} ${BUILTINS_HEADERS} ${DETAIL_HEADERS})
set_property(TARGET parlex PROPERTY CXX_STANDARD 17)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
