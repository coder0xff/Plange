#include "parlex/grammar2.hpp"

#include "parlex/builtins.hpp"

namespace parlex {

grammar2::production::production(state_machine2_info const & info) : state_machine(info) {
}


void grammar2::production::set_behavior(erased<behavior2::node> const & behavior) {
	this->behavior.swap(move(behavior.clone()));
	state_machine.set_behavior(*this->behavior);
}

grammar2::grammar2(builtins_t const & builtins, std::string const & rootName, std::vector<state_machine2_info> const & infos, std::function<erased<behavior2::node>(std::string const &, grammar2 &)> behavior_function) :
	grammar_base(builtins), root_name(rootName) {
	for (auto const & info : infos) {
		productions.emplace(info.id, info);
	}
	for (auto & production : productions) {
		production.second.set_behavior(behavior_function(production.first, *this));
	}
}

builtins_t::string_terminal& grammar2::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
	return result.first->second;
}

state_machine_base2 const& grammar2::get_main_production() const {
	return productions.find(root_name)->second.state_machine;
}

std::map<std::string, state_machine_base2 const *> grammar2::get_productions() const {
	std::map<std::string, state_machine_base2 const *> results;
	for (auto const & production : productions) {
		results[production.first] = &production.second.state_machine;
	}
	return results;
}

bool grammar2::test_precedence(state_machine_base2 const & productionA, state_machine_base2 const & productionB) const {
	auto i = precedences.find(static_cast<state_machine2 const *>(&productionA));
	if (i == precedences.end()) {
		return false;
	}
	return i->second.count(static_cast<state_machine2 const *>(&productionB)) > 0;
}

precedence_collection grammar2::get_precedences() const {
	precedence_collection results;
	for (auto const & precedence : precedences) {
		std::set<state_machine_base2 const *> & s = results[precedence.first];
		for (auto const & then : precedence.second) {
			s.insert(static_cast<state_machine_base2 const *>(then));
		}
	}
	return results;
}

state_machine2 const& grammar2::get_state_machine(std::string const & id) const {
	auto i = productions.find(id);
	throw_assert(i != productions.end());
	return i->second.state_machine;
}

} // namespace parlex
