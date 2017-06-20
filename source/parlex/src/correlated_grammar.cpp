#include "parlex/correlated_grammar.hpp"

#include "parlex/builder.hpp"
#include "parlex/builtins.hpp"
#include "utf.hpp"

namespace parlex {

correlated_grammar::production::production(std::string const & id, filter_function const & filter, associativity assoc) : state_machine(id, filter, assoc) {
}


void correlated_grammar::production::set_behavior(erased<behavior::node> const & behavior) {
	this->behavior = behavior.clone();
	state_machine.set_behavior(*this->behavior);
}

correlated_grammar::correlated_grammar(builtins_t const & builtins, builder::grammar const & grammarDefinition) : grammar_base(builtins), root_id(grammarDefinition.root_id) {
	for (auto const & definition : grammarDefinition.productions) {
		auto const & id = definition.id;
		productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, definition.filter, definition.assoc));
	}
	for (auto const & definition : grammarDefinition.productions) {
		auto const & id = definition.id;
		auto i = productions.find(id);
		throw_assert(i != productions.end());
		i->second.set_behavior(get_behavior(*definition.behavior));
	}

}

builtins_t::string_terminal& correlated_grammar::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(to_utf8(contents)), forward_as_tuple(contents));
	return result.first->second;
}

state_machine_base const& correlated_grammar::get_main_state_machine() const {
	return get_state_machine(root_id);
}

std::map<std::string, state_machine_base const *> correlated_grammar::get_state_machines() const {
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

state_machine_base const & correlated_grammar::get_state_machine(std::string const & id) const {
	auto i = productions.find(id);
	throw_assert(i != productions.end());
	return i->second.state_machine;
}

details::string_terminal const & correlated_grammar::get_literal(std::string const & id) const {
	auto i = literals.find(id);
	throw_assert(i != literals.end());
	return i->second;
}

recognizer const& correlated_grammar::get_recognizer(std::string const & id) const {
	recognizer const * r;
	if (builtins.resolve_builtin(id, r)) {
		return *r;
	} {
		auto i = literals.find(id);
		if (i != literals.end()) {
			return i->second;
		}
	}
	return get_state_machine(id);
}

erased<behavior::node> correlated_grammar::get_behavior(builder::node const & b) {
#define DO_AS(name) \
	builder::name##_t const * as_##name = dynamic_cast<builder::name##_t const *>(&b); \
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

} // namespace parlex
