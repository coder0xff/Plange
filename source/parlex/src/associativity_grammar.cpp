#include "parlex/builtins.hpp"
#include "parlex/parser.hpp"
#include "utils.hpp"

namespace parlex {
namespace builtins {

parlex::grammar const & get_associativity_grammar() {
	static parlex::grammar g("SYNTAX");

	static parlex::builtins::string_terminal & literal0 = g.add_literal(U"\n");
	static parlex::builtins::string_terminal & literal1 = g.add_literal(U"r");
	static parlex::builtins::string_terminal & literal2 = g.add_literal(U"a");
	static parlex::builtins::string_terminal & literal3 = g.add_literal(U"l");
	static parlex::builtins::string_terminal & literal4 = g.add_literal(U":");
	static parlex::builtins::string_terminal & literal5 = g.add_literal(U"_");

	static parlex::state_machine & ENTRY = g.add_production("ENTRY", 0, 1);
	static parlex::state_machine & IDENTIFIER = g.add_production("IDENTIFIER", 0, 1, parlex::builtins::greedy);
	static parlex::state_machine & SYNTAX = g.add_production("SYNTAX", 0, 1, parlex::builtins::greedy);

	static bool initialized = false;
	if (!initialized) {
		initialized = true;

		ENTRY.add_transition(0, IDENTIFIER, 3);
		ENTRY.add_transition(1, literal0, 4);
		ENTRY.add_transition(2, literal2, 1);
		ENTRY.add_transition(2, literal3, 1);
		ENTRY.add_transition(2, literal1, 1);
		ENTRY.add_transition(3, literal4, 2);

		IDENTIFIER.add_transition(0, literal5, 1);
		IDENTIFIER.add_transition(0, parlex::builtins::letter, 1);
		IDENTIFIER.add_transition(1, literal5, 1);
		IDENTIFIER.add_transition(1, parlex::builtins::letter, 1);
		IDENTIFIER.add_transition(1, parlex::builtins::number, 1);

		SYNTAX.add_transition(0, ENTRY, 0);
	}

	return g;
}

}

std::map<std::string, associativity> load_associativities(std::u32string document) {
	parlex::parser p;
	auto asg = p.parse(builtins::get_associativity_grammar(), document);
	if (!asg.is_rooted()) {
		throw std::exception("Could not parse the document.");
	}
	std::map<std::string, associativity> result;
	for (match const & m : *asg.permutations[asg.root].begin()) {
		auto entry = *asg.permutations[m].begin();
		associativity & destination = result[to_utf8(document.substr(entry[0].document_position, entry[0].consumed_character_count))];
		switch (document[entry[2].document_position]) {
		case 'a':
			destination = associativity::any;
			break;
		case 'l':
			destination = associativity::left;
			break;
		case 'r':
			destination = associativity::right;
			break;
		}
	}
	return result;
}

}
