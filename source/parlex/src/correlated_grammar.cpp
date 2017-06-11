#include "parlex/correlated_grammar.hpp"

#include "parlex/builtins.hpp"

namespace parlex {

correlated_grammar::production::production(correlated_state_machine_info const & info) : state_machine(info) {
}


void correlated_grammar::production::set_behavior(erased<behavior::node> const & behavior) {
	this->behavior.swap(move(behavior.clone()));
	state_machine.set_behavior(*this->behavior);
}

correlated_grammar::correlated_grammar(builtins_t const & builtins, std::string const & rootName, std::vector<correlated_state_machine_info> const & infos, std::function<erased<behavior::node>(std::string const &, correlated_grammar &)> behavior_function) :
	grammar_base(builtins), root_name(rootName) {
	for (auto const & info : infos) {
		productions.emplace(info.id, info);
	}
	for (auto & production : productions) {
		production.second.set_behavior(behavior_function(production.first, *this));
	}
}

builtins_t::string_terminal& correlated_grammar::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
	return result.first->second;
}

state_machine_base const& correlated_grammar::get_main_production() const {
	return productions.find(root_name)->second.state_machine;
}

std::map<std::string, state_machine_base const *> correlated_grammar::get_productions() const {
	std::map<std::string, state_machine_base const *> results;
	for (auto const & production : productions) {
		results[production.first] = &production.second.state_machine;
	}
	return results;
}

bool correlated_grammar::test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const {
	auto i = precedences.find(static_cast<correlated_state_machine const *>(&productionA));
	if (i == precedences.end()) {
		return false;
	}
	return i->second.count(static_cast<correlated_state_machine const *>(&productionB)) > 0;
}

precedence_collection correlated_grammar::get_precedences() const {
	precedence_collection results;
	for (auto const & precedence : precedences) {
		std::set<state_machine_base const *> & s = results[precedence.first];
		for (auto const & then : precedence.second) {
			s.insert(static_cast<state_machine_base const *>(then));
		}
	}
	return results;
}

correlated_state_machine const& correlated_grammar::get_state_machine(std::string const & id) const {
	auto i = productions.find(id);
	throw_assert(i != productions.end());
	return i->second.state_machine;
}

} // namespace parlex
