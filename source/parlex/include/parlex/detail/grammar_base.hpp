#ifndef GRAMMAR_BASE_HPP
#define GRAMMAR_BASE_HPP

#include <map>

#include "parlex/precedence_collection.hpp"

#include "parlex/detail/state_machine_base.hpp"
#include "parlex/detail/string_terminal.hpp"

namespace parlex {
namespace detail {

class builtins_t;

class grammar_base {
public:
	virtual state_machine_base const& get_main_state_machine() const = 0;
	virtual std::vector<state_machine_base const *> get_state_machines() const = 0;
	virtual state_machine_base const& get_state_machine(std::string const & id) const = 0;
	virtual string_terminal const& get_literal(std::string const & id) const = 0;
	virtual bool does_precede(recognizer const * lhs, recognizer const * rhs) const = 0;
	virtual precedence_collection get_precedences() const = 0;
protected:
	virtual ~grammar_base() = default;
	grammar_base() = default;
	grammar_base(grammar_base const & other) = default;
};

}
} // namespace parlex

#endif //GRAMMAR_BASE_HPP
