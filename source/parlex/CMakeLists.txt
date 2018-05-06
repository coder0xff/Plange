add_subdirectory(parlex_test)

set (SOURCES
	"src/abstract_syntax_semilattice.cpp"
	"src/abstract_syntax_tree.cpp"
	"src/builder.cpp"
	"src/builtins.cpp"
	"src/c_string.cpp"
	"src/configuration.cpp"
	"src/cpp_generator.cpp"
	"src/document_representation.cpp"
	"src/grammar.cpp"
	"src/job.cpp"
	"src/match.cpp"
	"src/match_class.cpp"
	"src/parser.cpp"
	"src/producer.cpp"
	"src/recognizer.cpp"
	"src/acceptor.cpp"
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
	"include/parlex/detail/basic_escape_sequence.hpp"
	"include/parlex/detail/builtins.hpp"
	"include/parlex/detail/c_string.hpp"
	"include/parlex/detail/configuration.hpp"
	"include/parlex/detail/content.hpp"
	"include/parlex/detail/document.hpp"
	"include/parlex/detail/grammar.hpp"
	"include/parlex/detail/job.hpp"
	"include/parlex/detail/match.hpp"
	"include/parlex/detail/match_class.hpp"
	"include/parlex/detail/nfa.hpp"
	"include/parlex/detail/not_double_quote.hpp"
	"include/parlex/detail/not_newline.hpp"
	"include/parlex/detail/derivation.hpp"
	"include/parlex/detail/parser.hpp"
	"include/parlex/detail/producer.hpp"
	"include/parlex/detail/producer_table.hpp"
	"include/parlex/detail/recognizer.hpp"
	"include/parlex/detail/acceptor.hpp"
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

include_directories("include")
include_directories("${PROJECT_SOURCE_DIR}/utilities")
include_directories("${PROJECT_SOURCE_DIR}/mpl")
include_directories("${PROJECT_SOURCE_DIR}/collections")

add_library(parlex ${SOURCES} ${HEADERS} ${BUILTINS_HEADERS} ${DETAIL_HEADERS})
set_property(TARGET parlex PROPERTY CXX_STANDARD 17)
set_property(TARGET parlex PROPERTY CXX_STANDARD_REQUIRED ON)
find_package (Threads)
target_link_libraries(parlex utilities ${CMAKE_THREAD_LIBS_INIT})
