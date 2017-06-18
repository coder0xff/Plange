#include "parlex/grammar.hpp"

#include <algorithm>
#include <queue>
#include <sstream>

#include "parlex/builtins.hpp"

#include "utils.hpp"
#include "utf.hpp"

namespace parlex {

grammar::grammar(builtins_t const & builtins, std::string const & nameOfMain) : grammar_base(builtins), main_production_name(nameOfMain) {
}

grammar::grammar(grammar const & other) : grammar_base(other), main_production_name(other.main_production_name), literals(other.literals) {
	std::map<recognizer const *, recognizer const *> recognizersMap;
	for (std::map<std::u32string, details::string_terminal>::const_iterator i = other.literals.begin(), j = literals.begin(); j != literals.end();) {
		recognizersMap[static_cast<recognizer const *>(&i++->second)] = static_cast<recognizer const *>(&j++->second);
	}

	for (auto const & nameAndStateMachine : other.productions) {
		std::string name = nameAndStateMachine.first;
		state_machine const & sm = nameAndStateMachine.second;
		std::pair<std::map<std::string, state_machine>::iterator, bool> emplaceResult = productions.emplace(
			std::piecewise_construct,
			forward_as_tuple(name),
			forward_as_tuple(name, sm.start_state, sm.accept_state_count, sm.filter, sm.assoc));
		recognizersMap[static_cast<recognizer const *>(&sm)] = static_cast<recognizer const *>(&emplaceResult.first->second);
	}

	for (auto const & nameAndStateMachine : other.productions) {
		state_machine const & sm = nameAndStateMachine.second;
		state_machine & outProduction = productions.find(nameAndStateMachine.first)->second;
		state_machine::states_t const & othersStates = sm.get_states();
		for (size_t j = 0; j < othersStates.size(); ++j) {
			auto const & othersState = othersStates[j];
			for (auto const & symbolAndToState : othersState) {
				recognizer const * mappedSymbol = symbolAndToState.first;
				if (recognizersMap.count(mappedSymbol) == 1) {
					mappedSymbol = recognizersMap[mappedSymbol];
				}
				outProduction.add_transition(j, mappedSymbol, symbolAndToState.second);
			}
		}
	}
}

#if 0 //to move
std::string grammar::hierarchy_dot(std::map<std::string, production_def> const & productions) {
	std::set<std::pair<std::string, std::string>> arrows;
	for (auto const & pair: productions) {
		auto const & name = pair.first;
		auto const & tree = pair.second.tree;
		std::queue<std::shared_ptr<details::behavior_node>> descendentsQueue;
		for (auto const & child : tree->get_children()) {
			descendentsQueue.push(child);
		}
		while (descendentsQueue.size() > 0) {
			auto const & descendent = descendentsQueue.front();
			descendentsQueue.pop();
			auto const & asProduction = std::dynamic_pointer_cast<details::reference>(descendent);
			if (asProduction != nullptr) {
				arrows.insert(make_pair(name, asProduction->name));
			} else {
				for (auto const & subDescendent: descendent->get_children()) {
					descendentsQueue.push(subDescendent);
				}

			}
		}
	}
	std::stringstream result;
	result << "digraph nfa {" << std::endl;
	for (auto const & arrow : arrows) {
		result << arrow.first << " -> " << arrow.second << std::endl;
	}
	result << "}" << std::endl;
	return result.str();
}
#endif

state_machine_base const& grammar::get_main_production() const {
	auto i = productions.find(main_production_name);
	throw_assert(i != productions.end());
	return i->second;
}

std::map<std::string, state_machine_base const *> grammar::get_productions() const {
	std::map<std::string, state_machine_base const *> results;
	for (auto const & i : productions) {
		results[i.first] = &i.second;
	}
	return results;
}

builtins_t::string_terminal& grammar::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
	return result.first->second;
}

std::map<std::u32string, builtins_t::string_terminal> const& grammar::get_literals() const {
	return literals;
}

state_machine& grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc) {
	return productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, startState, acceptStateCount, filter_function(), assoc)).first->second;
}

state_machine& grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function filter, associativity assoc) {
	return productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, startState, acceptStateCount, filter, assoc)).first->second;
}

details::string_terminal const& grammar::get_add_literal(std::u32string contents) {
	auto i = literals.find(contents);
	if (i != literals.end()) {
		i->second;
	}
	auto res = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
	return res.first->second;
}

void print_sorted_lines(std::ostream & os, std::string lines) {
	std::stringstream ss(lines);
	std::string to;
	std::vector<std::string> splitLines;
	while (getline(ss, to, '\n')) {
		splitLines.push_back(to);
	}
	sort(splitLines.begin(), splitLines.end());
	for (std::string const & s : splitLines) {
		os << s << '\n';
	}
}

void grammar::generate_hpp(std::string grammarName, std::ostream & hpp, std::string namespace_, std::string upperCaseGrammarName) const {
	hpp << "/************ This file was generated by parlex ************/" << std::endl;
	hpp << std::endl;
	hpp << "#ifndef " << upperCaseGrammarName << "_GRAMMAR_HPP" << std::endl;
	hpp << "#define " << upperCaseGrammarName << "_GRAMMAR_HPP" << std::endl;
	hpp << std::endl;
	hpp << "#include \"parlex/builder.hpp\"" << std::endl;
	hpp << std::endl;
	if (namespace_ != "") {
		hpp << "namespace " << namespace_ << " {" << std::endl;
		hpp << std::endl;
	}
	for (auto const & i : productions) {
		hpp << "DECLARE_DFA(" << i.first << ");" << std::endl;
	}
	hpp << std::endl;
	hpp << "DECLARE_GRAMMAR(" << grammarName << ");" << std::endl;
	hpp << std::endl;
	if (namespace_ != "") {
		hpp << "}" << std::endl;
		hpp << std::endl;
	}
	hpp << "#endif" << std::endl;
}

#if 0 //to move
void grammar::generate_representation(std::ostream & cpp) {
	std::map<std::string, bool> needsClass;
	for (auto const & pair: definitions) {
		std::string const & name = pair.first;
		needsClass[name] = false;
		production_def const & def = pair.second;
		std::queue<std::shared_ptr<details::behavior_node>> nodes;
		nodes.push(def.tree);
		while (nodes.size() > 0) {
			auto const node = nodes.front();
			nodes.pop();
			if (node->tag != "") {
				needsClass[name] = true;
				break;
			}
			for (auto const & childNode: node->get_children()) {
				nodes.push(childNode);
			}
		}
	}
}
#endif

void grammar::generate_cplusplus_code(builtins_t const & builtins, std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string namespace_, std::string headerPathPrefix) const {
	std::string upperCaseGrammarName = grammarName;
	transform(upperCaseGrammarName.begin(), upperCaseGrammarName.end(), upperCaseGrammarName.begin(), toupper);

	generate_hpp(grammarName, hpp, namespace_, upperCaseGrammarName);

	std::map<recognizer const *, std::string> recognizerToStringMap;
	std::set<std::string> sortedBuiltInNames;
	for (auto const & entry : builtins.recognizer_table) {
		sortedBuiltInNames.insert(entry.first);
	}
	for (std::string const & name : sortedBuiltInNames) {
		auto const & entry = builtins.recognizer_table.find(name);
		recognizerToStringMap[entry->second] = "parlex::builtins::" + entry->first;
	}

	// start with a BOM for sanity's sake
	cpp << "\xEF\xBB\xBF/************ This file was generated by parlex ************/" << std::endl;
	cpp << std::endl;
	cpp << "#include \"" << headerPathPrefix << grammarName << "_grammar.hpp\"" << std::endl;
	cpp << std::endl;
	if (namespace_ != "") {
		cpp << "namespace " << namespace_ << " {" << std::endl;
		cpp << std::endl;
	}

	int i = 0;
	std::map<std::u32string, details::string_terminal const *> contentToLiterals;
	std::vector<std::u32string> sortedContentStrings;
	for (auto const & entry : literals) {
		contentToLiterals[entry.second.get_content()] = &entry.second;
	}
	for (auto const & entry : contentToLiterals) {
		sortedContentStrings.push_back(entry.first);
	}
	sort(sortedContentStrings.begin(), sortedContentStrings.end());
	for (std::u32string content : sortedContentStrings) {
		details::string_terminal const & literal = *contentToLiterals[content];
		std::ostringstream nameStream;
		nameStream << "literal_t" << i;
		cpp << "DEFINE_TERMINAL(" << nameStream.str() << ", U" << enquote(to_utf8(literal.get_content())) << ");" << std::endl;
		recognizerToStringMap[static_cast<recognizer const *>(&literal)] = nameStream.str();
		i++;
	}
	for (auto const & entry : literals) {
		details::string_terminal const & chosenLiteral = *contentToLiterals[entry.second.get_content()];
		std::string chosenName = recognizerToStringMap[static_cast<recognizer const *>(&chosenLiteral)];
		recognizerToStringMap[static_cast<recognizer const *>(&entry.second)] = chosenName;
	}
	cpp << std::endl;

	for (auto const & production : productions) {
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		recognizerToStringMap[static_cast<recognizer const *>(&sm)] = id;
	}

	for (auto const & production : productions) {
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		cpp << "DEFINE_DFA(" << id << "," << std::endl;
		auto const states = sm.get_states();
		for (size_t j = 0; j < states.size(); ++j) {
			auto const & state = states[j];
			cpp << "\tDFA_STATE " << j << ":" << std::endl;
			bool isAccept = j >= states.size() - sm.accept_state_count;
			if (isAccept) {
				cpp << "\t\tDFA_ACCEPT;" << std::endl;
			}
			for (auto const & edge : state) {
				auto const & transition = *edge.first;
				int nextState = edge.second;
				cpp << "\t\tDFA_EDGE(" << recognizerToStringMap[&transition] << "," << nextState << ");" << std::endl;
			}
			cpp << "\t\tbreak;" << std::endl;
		}

		std::string associativityString = "parlex::associativity::";
		switch (sm.assoc) {
			case associativity::none:
				associativityString += "none";
				break;
			case associativity::any:
				associativityString += "any";
				break;
			case associativity::left:
				associativityString += "left";
				break;
			case associativity::right:
				associativityString += "right";
				break;
			default:
				throw std::logic_error("invalid value for associativity");
		}

		if (sm.filter == builtins.longest) {
			cpp << ", " << sm.start_state << ", &parlex::builtins::longest, " << associativityString << "); " << std::endl;
		} else {
			cpp << ", " << sm.start_state << ", " << associativityString << ");" << std::endl;
		}
		cpp << std::endl;
	}
	cpp << std::endl;

	cpp << "DEFINE_GRAMMAR(" << std::endl;
	cpp << "\t" << grammarName << "," << std::endl;
	cpp << "\t" << nameOfMain << "," << std::endl;
	cpp << "\t({" << std::endl;
	for (auto const & production : productions) {
		cpp << "\t\t" << production.first << ", " << std::endl;
	}
	cpp << "\t})," << std::endl;

	cpp << "\t({" << std::endl;
	for (precedence_collection::value_type const & leftAndRights : get_precedences()) {
		for (auto const & right : leftAndRights.second) {
			cpp << "\t\tGRAMMAR_PRECEDENCE(" << leftAndRights.first->id << ", " << right->id << ")," << std::endl;
		}
	}
	cpp << "\t})" << std::endl;
	cpp << ");" << std::endl;
	if (namespace_ != "") {
		cpp << std::endl;
		cpp << "}" << std::endl;
	}


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

}
