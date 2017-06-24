#include "parlex/details/grammar.hpp"

#include "parlex/builder.hpp"
#include "parlex/details/builtins.hpp"

#include "utf.hpp"

namespace parlex {
namespace details {

grammar::production::production(std::string const & id, filter_function const & filter, associativity assoc) : machine(id, filter, assoc) {
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

bool grammar::test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const {
	auto i = precedences.find(static_cast<state_machine const *>(&productionA));
	if (i == precedences.end()) {
		return false;
	}
	return i->second.count(static_cast<state_machine const *>(&productionB)) > 0;
}

precedence_collection grammar::get_precedences() const {
	precedence_collection results;
	for (auto const & precedence : precedences) {
		std::set<state_machine_base const *> & s = results[precedence.first];
		for (auto const & then : precedence.second) {
			s.insert(static_cast<state_machine_base const *>(then));
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
	auto const * as_##name = dynamic_cast<details::name##_t const *>(&b); \
	if (as_##name != nullptr)

	DO_AS(literal) {
		auto const & l = get_or_add_literal(as_literal->content);
		return behavior::leaf(l);
	}

	DO_AS(reference) {
		auto const & r = get_recognizer(as_reference->id);
		return behavior::leaf(r);
	}

#define CONVERT_AS(type) \
	DO_AS(type) { \
		behavior::type result; \
		for (auto const & child : b.children) { \
			result.add_child(get_behavior(*child)); \
		} \
		return result; \
	}

	CONVERT_AS(choice)
	CONVERT_AS(optional)
	CONVERT_AS(repetition)
	CONVERT_AS(sequence)

#undef CONVERT_AS
#undef DO_AS

		throw std::logic_error("unknown type");
}

} // namespace details
} // namespace parlex
