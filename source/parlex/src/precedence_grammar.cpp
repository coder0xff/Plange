#include <cassert>

#include "parlex/builtins/precedence_grammar.hpp"
#include "parlex/parser.hpp"
#include "utils.hpp"

namespace parlex {
namespace builtins {

parlex::grammar const & get_precedence_grammar() {
	static parlex::grammar g("SYNTAX");

	static parlex::builtins::string_terminal & literal0 = g.add_literal(U"#");
	static parlex::builtins::string_terminal & literal1 = g.add_literal(U":");
	static parlex::builtins::string_terminal & literal2 = g.add_literal(U"_");
	static parlex::builtins::string_terminal & literal3 = g.add_literal(U"\n");

	static parlex::state_machine & COMMENT = g.add_production("COMMENT", 0, 1);
	static parlex::state_machine & ENTRY = g.add_production("ENTRY", 0, 1);
	static parlex::state_machine & IDENTIFIER = g.add_production("IDENTIFIER", 0, 1, parlex::builtins::greedy);
	static parlex::state_machine & NEWLINE = g.add_production("NEWLINE", 0, 1);
	static parlex::state_machine & SYNTAX = g.add_production("SYNTAX", 0, 1);

	static bool initialized = false;
	if (!initialized) {
		initialized = true;

		COMMENT.add_transition(0, literal0, 1);
		COMMENT.add_transition(1, parlex::builtins::not_newline, 1);
		COMMENT.add_transition(1, NEWLINE, 2);

		ENTRY.add_transition(0, IDENTIFIER, 3);
		ENTRY.add_transition(1, NEWLINE, 4);
		ENTRY.add_transition(2, IDENTIFIER, 1);
		ENTRY.add_transition(3, literal1, 2);

		IDENTIFIER.add_transition(0, parlex::builtins::letter, 1);
		IDENTIFIER.add_transition(0, literal2, 1);
		IDENTIFIER.add_transition(1, parlex::builtins::letter, 1);
		IDENTIFIER.add_transition(1, parlex::builtins::number, 1);
		IDENTIFIER.add_transition(1, literal2, 1);

		NEWLINE.add_transition(0, literal3, 1);

		SYNTAX.add_transition(0, ENTRY, 0);
		SYNTAX.add_transition(0, COMMENT, 0);
	}

	return g;
}

}

namespace {

std::pair<std::string, std::string> process_entry(std::u32string const & document, abstract_syntax_graph const & asg, parlex::match const & m) {
	assert(asg.table.find(m) != asg.table.end());
	permutation const & entryPerm = *asg.table.find(m)->second.begin();
	assert(entryPerm.size() >= 3);
	auto const & left = entryPerm[0];
	auto const & right = entryPerm[2];
	return std::make_pair<std::string, std::string>(
		to_utf8(document.substr(left.document_position, left.consumed_character_count)),
		to_utf8(document.substr(right.document_position, right.consumed_character_count))
		);
}

}

void load_precedence(grammar & g, std::u32string const & document)
{
	parser p;
	auto asg = p.parse(builtins::get_precedence_grammar(), document);
	if (!asg.is_rooted()) {
		throw std::exception("Could not parse the document");
	}

	state_machine const * entryMachine = &(builtins::get_precedence_grammar().get_productions().find("ENTRY")->second);
	for (match const & part : *asg.table[asg.root].begin()) {
		if (&part.r == entryMachine) {
			auto pair = process_entry(document, asg, part);
			auto leftIter = g.get_productions().find(pair.first);
			if (leftIter == g.get_productions().end()) {
				throw std::exception((pair.first + " does not exist.").c_str());
			}
			auto rightIter = g.get_productions().find(pair.second);
			if (rightIter == g.get_productions().end()) {
				throw std::exception((pair.second + " does not exist.").c_str());
			}
			g.add_precedence(leftIter->second, rightIter->second);
		}
	}
}

}