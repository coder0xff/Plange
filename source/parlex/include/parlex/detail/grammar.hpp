#ifndef CORRELATED_GRAMMAR_HPP
#define CORRELATED_GRAMMAR_HPP

#include <map>

#include "erased.hpp"

#include "parlex/precedence_collection.hpp"

#include "parlex/detail/grammar_base.hpp"
#include "parlex/detail/state_machine.hpp"
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
class grammar : public grammar_base {
public:
	struct production {
		production(std::string const & name, filter_function const & filter, associativity assoc);
		node const & get_behavior() const;
		state_machine const & get_state_machine() const;
	private:
		friend class grammar;
		state_machine machine;
		std::unique_ptr<node> behavior;
		void set_behavior(grammar const & g, erased<node> const & behavior);
	};

	explicit grammar(builder const & grammarDefinition);
	grammar(grammar const & copy) = delete;
	virtual ~grammar() = default;

	state_machine_base const& get_root_state_machine() const override;
	std::vector<state_machine_base const *> get_state_machines() const override;
	std::vector<recognizer const *> const & get_recognizers() const;
	size_t get_recognizer_count() const override;
	recognizer const& get_recognizer(size_t const index) const override;
	bool does_precede(size_t const lhs, size_t const rhs) const override;
	precedence_collection get_precedences() const override;

	size_t lookup_production_local_index(std::string const & name) const;
	size_t lookup_literal_recognizer_index(std::u32string const & content) const;
	size_t lookup_recognizer_index(std::string const & name) const;
	size_t lookup_recognizer_index(recognizer const & recognizer) const override;
private:
	std::vector<production> local_productions;
	std::vector<string_terminal> local_literals;
	std::vector<recognizer const *> recognizers; // pointers into builtin_terminals, local production, and local literals. The index is used to uniquely identify the corresponding recognizer throughtout the parsing algorithms
	std::map<recognizer const *, size_t> recognizer_ptr_to_recognizer_index;
	std::map<std::u32string, size_t> content_to_recognizer_index;
	std::map<std::u32string, size_t> content_to_local_literal_index;
	std::map<std::string, size_t> name_to_recognizer_index;
	std::map<std::string, size_t> name_to_local_production_index;
	size_t root_production_index;
	precedence_collection precedences;

	size_t add_table_data(std::map<std::string, recognizer const *> & nameToRecognizerPtr, recognizer const * recognizerPtr);
	void compile_sub_builder(std::map<std::string, recognizer const *> & nameToRecognizerPtr, sub_builder const & grammarDefinition);
	void link_sub_builder(sub_builder const & grammarDefinition);
};

} // namespace detail
} // namespace parlex

#endif //CORRELATED_GRAMMAR_HPP
