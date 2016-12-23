#ifndef GRAMMAR_BASE_HPP
#define GRAMMAR_BASE_HPP

#include <map>

#include "parlex/state_machine.hpp"
#include "parlex/precedence_collection.hpp"

namespace parlex {

class grammar_base {
public:
	virtual ~grammar_base() = default;
	virtual state_machine_base const & get_main_production() const = 0;
	virtual std::map<std::string, state_machine_base const *> get_productions() const = 0;
	void add_precedence(state_machine_base const & productionA, state_machine_base const & productionB);
	bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const;
	precedence_collection const & get_precedences() const;
private:
	precedence_collection precedences;
};

}

#endif
