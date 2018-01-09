#include "parlex/detail/grammar.hpp"

#include <stack>

#include "coherent_queue.hpp"

#include "parlex/builder.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/c_string.hpp"

namespace parlex {
namespace detail {

grammar::production::production(std::string const & name, filter_function const & filter, associativity const assoc) : machine(name, filter, assoc) {
}

node const& grammar::production::get_behavior() const
{
	return *behavior;
}

state_machine const & grammar::production::get_state_machine() const {
	return machine;
}


void grammar::production::set_behavior(grammar const & g, erased<node> const & behavior) {
	this->behavior = behavior.clone();

	// assign the recognizer_index field of each leaf
	{
		collections::coherent_queue<node *> pending;
		pending.push(this->behavior.get());
		while (!pending.empty()) {
			auto ptr = pending.pop();
			auto * asLiteral = dynamic_cast<literal *>(ptr);
			if (asLiteral != nullptr) {
				asLiteral->recognizer_index = g.lookup_literal_recognizer_index(asLiteral->content);
			} else {
				auto * asReference = dynamic_cast<reference *>(ptr);
				if (asReference != nullptr) {
					asReference->recognizer_index = g.lookup_recognizer_index(asReference->target);
				} else {
					for (auto & child : ptr->children) {
						pending.push(&*child);
					}
				}
			}
		}
	}

	machine.set_behavior(*this->behavior);
}

size_t grammar::add_table_data(std::map<std::string, recognizer const *> & nameToRecognizerPtr, recognizer const * recognizerPtr) {
	if (recognizer_ptr_to_recognizer_index.count(recognizerPtr) > 0) {
		throw "key already present";
	}
	auto const recognizerIndex = recognizers.size();
	recognizers.push_back(recognizerPtr);
	if (!recognizer_ptr_to_recognizer_index.insert(std::make_pair(recognizerPtr, recognizerIndex)).second) {
		throw "key already present";
	}
	if (!name_to_recognizer_index.insert(std::make_pair(recognizerPtr->name, recognizerIndex)).second) {
		throw "key already present";
	}
	if (!nameToRecognizerPtr.insert(std::make_pair(recognizerPtr->name, recognizerPtr)).second) {
		throw "key already present";
	}
	return recognizerIndex;
}

void grammar::compile_sub_builder(std::map<std::string, recognizer const *> & nameToRecognizerPtr, sub_builder const & grammarDefinition) {
	for (auto const & definition : grammarDefinition.productions) {
		local_productions.emplace_back(definition.name, definition.filter, definition.assoc);
		name_to_local_production_index[definition.name] = uint16_t(local_productions.size() - 1);
		auto const ptr = &local_productions.back().get_state_machine();
		add_table_data(nameToRecognizerPtr, ptr);
	}
}

void grammar::link_sub_builder(sub_builder const & grammarDefinition) {
	for (auto const & definition : grammarDefinition.productions) {
		auto const & name = definition.name;
		production & production = local_productions[name_to_local_production_index[name]];
		production.set_behavior(*this, definition.behavior);
	}
}

grammar::grammar(builder const & grammarDefinition, bool noBuiltIns) {
	std::set<std::string> referencedRecognizers;
	auto cStringWasReferenced = false;
	for (auto const & production : grammarDefinition.productions) {
		referencedRecognizers.insert(production.name);
		std::stack<node const *> pending;
		pending.push(&*production.behavior);
		while (!pending.empty()) {
			auto const asNodePtr = pending.top();
			pending.pop();
			auto const * asReferencePtr = dynamic_cast<reference const *>(asNodePtr);
			if (asReferencePtr != nullptr) {
				if (asReferencePtr->target == "c_string") {
					cStringWasReferenced = true;
				}
				referencedRecognizers.insert(asReferencePtr->target);
			}
			for (auto const & child : asNodePtr->children) {
				pending.push(&*child);
			}
		}
	}

	auto const & cStringSubgrammar = c_string();
	if (cStringWasReferenced) {
		referencedRecognizers.insert("basic_escape_sequence");
		referencedRecognizers.insert("content");
		referencedRecognizers.insert("hexadecimal_digit");
		referencedRecognizers.insert("octal_digit");
	}

	std::map<std::string, recognizer const *> nameToRecognizerPtr;

	for (auto const & builtin : builtin_terminals().recognizer_table) {
		if (referencedRecognizers.count(builtin.first) > 0) {
			add_table_data(nameToRecognizerPtr, builtin.second);
		}
	}


	std::set<std::u32string> allStringLiterals;
	{
		if (cStringWasReferenced) {
			allStringLiterals = cStringSubgrammar.extract_string_literals();
		}
		auto grammerStringLiterals = grammarDefinition.extract_string_literals();
		allStringLiterals.insert(grammerStringLiterals.begin(), grammerStringLiterals.end());
	}

	// assign integer target to every local string literal
	local_literals.reserve(allStringLiterals.size());
	for (auto const & literal : allStringLiterals) {
		auto const literalIndex = local_literals.size();
		local_literals.emplace_back(literal);
		if (!content_to_local_literal_index.insert(std::make_pair(literal, literalIndex)).second) {
			throw "key already present";
		};
		string_terminal const * ptr = &local_literals[literalIndex];
		auto const recognizerIndex = add_table_data(nameToRecognizerPtr, ptr);
		if (!content_to_recognizer_index.insert(std::make_pair(literal, recognizerIndex)).second) {
			throw "key already present";
		}
	}
	
	if (!cStringWasReferenced) {
		local_productions.reserve(grammarDefinition.productions.size());
		compile_sub_builder(nameToRecognizerPtr, grammarDefinition);
		link_sub_builder(grammarDefinition);
	} else {
		local_productions.reserve(cStringSubgrammar.productions.size() + grammarDefinition.productions.size());
		compile_sub_builder(nameToRecognizerPtr, cStringSubgrammar);
		compile_sub_builder(nameToRecognizerPtr, grammarDefinition);
		link_sub_builder(cStringSubgrammar);
		link_sub_builder(grammarDefinition);
	}

	// Now that all the state_machines are created we can setup precedences
	precedences.resize(recognizers.size());
	for (auto const & definition : grammarDefinition.productions) {
		auto const fromRecognizerIndex = recognizer_ptr_to_recognizer_index[nameToRecognizerPtr[definition.name]];
		auto & precedenceSet = precedences[fromRecognizerIndex];
		for (auto const & precedence : definition.precedences) {
			auto toRecognizerIndex = recognizer_ptr_to_recognizer_index[nameToRecognizerPtr[precedence]];
			precedenceSet.insert(toRecognizerIndex);
		}
	}

	root_production_index = name_to_local_production_index[grammarDefinition.root_name];
}

state_machine const& grammar::get_root_state_machine() const {
	return local_productions[root_production_index].get_state_machine();
}

std::vector<state_machine const *> grammar::get_state_machines() const {
	std::vector<state_machine const *> results;
	results.reserve(local_productions.size());
	for (auto const & production : local_productions) {
		results.push_back(&production.machine);
	}
	return results;
}

std::vector<recognizer const *> const & grammar::get_recognizers() const {
	return recognizers;
}

uint16_t grammar::get_recognizer_count() const {
	return uint16_t(recognizers.size());
}

bool grammar::does_precede(uint16_t const lhs, uint16_t const rhs) const {
	return precedences[lhs].count(rhs) > 0;
}


uint16_t grammar::lookup_recognizer_index(recognizer const & recognizer) const
{
	auto i = recognizer_ptr_to_recognizer_index.find(&recognizer);
	throw_assert(i != recognizer_ptr_to_recognizer_index.end());
	return i->second;
}

precedence_collection grammar::get_precedences() const
{
	return precedences;
}

uint16_t grammar::lookup_production_local_index(std::string const & name) const {
	auto const i = name_to_local_production_index.find(name);
	throw_assert(i != name_to_local_production_index.end());
	return i->second;
}

uint16_t grammar::lookup_literal_recognizer_index(std::u32string const & content) const {
	auto const i = content_to_recognizer_index.find(content);
	throw_assert(i != content_to_recognizer_index.end());
	return i->second;
}

uint16_t grammar::lookup_recognizer_index(std::string const & name) const {
	auto const i = name_to_recognizer_index.find(name);
	throw_assert(i != name_to_recognizer_index.end());
	return i->second;
}

//state_machine_base const& grammar::get_state_machine(std::string const & name) const {
//	auto const i = productions.find(name);
//	throw_assert(i != productions.end());
//	return i->second.machine;
//}
//
//string_terminal const& grammar::get_literal(std::string const & name) const {
//	auto const i = literals.find(target);
//	throw_assert(i != literals.end());
//	return i->second;
//}

recognizer const & grammar::get_recognizer(uint16_t const index) const {
	return *recognizers[index];
}

}

//grammar::production const & grammar::get_production(std::string const & id) const {
//	auto const i = productions.find(id);
//	return i->second;
//}

} // namespace parlex
