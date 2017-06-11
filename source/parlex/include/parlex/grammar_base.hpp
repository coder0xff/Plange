#ifndef GRAMMAR_BASE_HPP
#define GRAMMAR_BASE_HPP

#include <map>

#include "parlex/state_machine.hpp"
#include "parlex/precedence_collection.hpp"

namespace parlex {

class builtins_t;

class grammar_base {
public:
	virtual state_machine_base const& get_main_production() const = 0;
	virtual std::map<std::string, state_machine_base const *> get_productions() const = 0;
	virtual bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const = 0;
	virtual precedence_collection get_precedences() const = 0;
	builtins_t const & builtins;
protected:
	~grammar_base() = default;
	explicit grammar_base(builtins_t const & builtins);
	grammar_base(grammar_base const & other);
};

} // namespace parlex

#endif //GRAMMAR_BASE_HPP
