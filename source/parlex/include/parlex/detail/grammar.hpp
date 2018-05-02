#ifndef CORRELATED_GRAMMAR_HPP
#define CORRELATED_GRAMMAR_HPP

#include <map>

#include "erased.hpp"

#include "parlex/precedence_collection.hpp"

#include "parlex/detail/grammar.hpp"
#include "parlex/detail/acceptor.hpp"
#include "parlex/detail/string_terminal.hpp"


namespace parlex {
struct sub_builder;
struct builder;

namespace detail {

struct node;
class builtin_terminals_t;

// you must first create all the productions objects
// then create the behaviors
// then call set_behavior on each reference
class grammar {
public:
	struct production {
		production(std::string const & name, filter_function const & filter, associativity assoc);
		node const & get_behavior() const;
		acceptor const & get_acceptor() const;
	private:
		friend class grammar;
		acceptor machine;
		std::unique_ptr<node> behavior;
		void set_behavior(grammar const & g, erased<node> const & behavior);
	};

	explicit grammar(builder const & grammarDefinition);
	grammar(grammar const & copy) = delete;
	virtual ~grammar() = default;

	acceptor const& get_root_acceptor() const;
	std::vector<acceptor const *> get_state_acceptors() const;
	std::vector<recognizer const *> const & get_recognizers() const;
	uint16_t get_recognizer_count() const;
	recognizer const& get_recognizer(uint16_t const index) const;
	bool does_precede(uint16_t const lhs, uint16_t const rhs) const;
	precedence_collection get_precedences() const;

	uint16_t lookup_production_local_index(std::string const & name) const;
	uint16_t lookup_literal_recognizer_index(std::u32string const & content) const;
	uint16_t lookup_recognizer_index(std::string const & name) const;
	uint16_t lookup_recognizer_index(recognizer const & recognizer) const;
	bool is_recognizer_left_recursive(uint16_t recognizerIndex) const;
private:
	std::vector<production> local_productions;
	std::vector<string_terminal> local_literals;
	std::vector<recognizer const *> recognizers; // pointers into builtin_terminals, local production, and local literals. The index is used to uniquely identify the corresponding recognizer throughout the parsing algorithms
	std::map<recognizer const *, uint16_t> recognizer_ptr_to_recognizer_index;
	std::map<std::u32string, uint16_t> content_to_recognizer_index;
	std::map<std::u32string, uint16_t> content_to_local_literal_index;
	std::map<std::string, uint16_t> name_to_recognizer_index;
	std::map<std::string, uint16_t> name_to_local_production_index;
	uint16_t root_production_index;
	precedence_collection precedences;
	std::set<uint16_t> left_recursive_recognizers;

	size_t add_table_data(std::map<std::string, recognizer const *> & nameToRecognizerPtr, recognizer const * recognizerPtr);
	void compile_sub_builder(std::map<std::string, recognizer const *> & nameToRecognizerPtr, sub_builder const & grammarDefinition);
	void link_sub_builder(sub_builder const & grammarDefinition);
	void compute_left_recursive_recognizers();
};

} // namespace detail
} // namespace parlex

#endif //CORRELATED_GRAMMAR_HPP
