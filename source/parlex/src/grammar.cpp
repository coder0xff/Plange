#include "parlex/detail/grammar.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/builtins.hpp"

#include "utf.hpp"
#include "covariant_invoke.hpp"

namespace parlex {
namespace detail {

grammar::production::production(std::string const & id, filter_function const & filter, associativity assoc) : machine(id, filter, assoc) {
}

behavior::node const& grammar::production::get_behavior() const
{
	return *behavior;
}

recognizer const & grammar::production::get_recognizer() const {
	return machine;
}


void grammar::production::set_behavior(erased<behavior::node> const & behavior) {
	this->behavior = behavior.clone();
	machine.set_behavior(*this->behavior);
}

grammar::grammar(builder const & grammarDefinition) : root_id(grammarDefinition.root_id) {
	for (auto const & definition : grammarDefinition.productions) {
		auto const & id = definition.id;
		productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, definition.filter, definition.assoc));
	}
	for (auto const & definition : grammarDefinition.productions) {
		auto const & id = definition.id;
		auto i = productions.find(id);
		throw_assert(i != productions.end());
		i->second.set_behavior(get_behavior(*definition.behavior));
		throw_assert(i->second.behavior != nullptr);
	}
	// Now that all the state_machines are created we can setup precedences
	for (auto const & definition : grammarDefinition.productions) {
		auto const & id = definition.id;
		auto i = productions.find(id);
		for (auto const & precedence : definition.precedences) {
			std::set<const recognizer *> & precedenceSet = precedences[&i->second.get_recognizer()];
			precedenceSet.insert(&get_recognizer(precedence));
		}
	}
}

string_terminal& grammar::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(to_utf8(contents)), forward_as_tuple(contents));
	return result.first->second;
}

state_machine_base const& grammar::get_main_state_machine() const {
	return get_state_machine(root_id);
}

std::map<std::string, state_machine_base const *> grammar::get_state_machines() const {
	std::map<std::string, state_machine_base const *> results;
	for (auto const & production : productions) {
		results[production.first] = &production.second.machine;
	}
	return results;
}

bool grammar::does_precede(recognizer const * lhs, recognizer const * rhs) const {
	auto i = precedences.find(lhs);
	if (i == precedences.end()) {
		return false;
	}
	return i->second.count(rhs) > 0;
}

precedence_collection grammar::get_precedences() const {
	precedence_collection results;
	for (auto const & precedence : precedences) {	
		auto const & preceding = precedence.first;
		for (auto const & preceded : precedence.second) {
			results[preceding].insert(preceded);
		}
	}
	return results;
}

state_machine_base const& grammar::get_state_machine(std::string const & id) const {
	auto i = productions.find(id);
	throw_assert(i != productions.end());
	return i->second.machine;
}

string_terminal const& grammar::get_literal(std::string const & id) const {
	auto i = literals.find(id);
	throw_assert(i != literals.end());
	return i->second;
}

recognizer const& grammar::get_recognizer(std::string const & id) const {
	recognizer const * r;
	if (builtins().resolve_builtin(id, r)) {
		return *r;
	} {
		auto i = literals.find(id);
		if (i != literals.end()) {
			return i->second;
		}
	}
	return get_state_machine(id);
}

erased<behavior::node> grammar::get_behavior(node const & b) {

#define DO_AS(name) \
		[&](name##_t const & v) { \
			behavior::name result; \
			for (auto const & child : v.children) { \
				result.add_child(get_behavior(*child)); \
			} \
			return result; \
		}


	return covariant_invoke<erased<behavior::node>>(b,
		[&](literal_t const & v) {
			auto const & l = get_or_add_literal(v.content);
			return behavior::leaf(l);
		},
		[&](reference_t const & v) {
			auto const & r = get_recognizer(v.id);
			return behavior::leaf(r);
		},
		DO_AS(choice),
		DO_AS(optional),
		DO_AS(repetition),
		DO_AS(sequence)
	);

#undef DO_AS
}

grammar::production const & grammar::get_production(std::string const & id) const {
	auto i = productions.find(id);
	return i->second;
}

} // namespace detail
} // namespace parlex
