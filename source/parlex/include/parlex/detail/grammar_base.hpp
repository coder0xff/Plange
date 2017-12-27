#ifndef GRAMMAR_BASE_HPP
#define GRAMMAR_BASE_HPP

#include "parlex/precedence_collection.hpp"

#include "parlex/detail/state_machine_base.hpp"
#include "parlex/detail/string_terminal.hpp"

namespace parlex {
namespace detail {

class builtin_terminals_t;

class grammar_base {
public:
	virtual state_machine_base const& get_root_state_machine() const = 0;
	virtual std::vector<state_machine_base const *> get_state_machines() const = 0;
	virtual size_t get_recognizer_count() const = 0;
	virtual recognizer const& get_recognizer(size_t const index) const = 0;
	virtual bool does_precede(size_t const lhs, size_t const rhs) const = 0;
	virtual size_t lookup_recognizer_index(recognizer const & recognizer) const = 0;
	virtual precedence_collection get_precedences() const = 0;
protected:
	virtual ~grammar_base() = default;
	grammar_base() = default;
	grammar_base(grammar_base const & other) = default;
};

}
} // namespace parlex

#endif //GRAMMAR_BASE_HPP
