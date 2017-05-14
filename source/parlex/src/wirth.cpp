#include "parlex/builtins.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/behavior.hpp"

#include "utils.hpp"

namespace parlex {
namespace builtins {

grammar wirth("root");

}
}

namespace {

parlex::builtins::string_terminal & newline = parlex::builtins::wirth.add_literal(U"\n");
parlex::builtins::string_terminal & hash = parlex::builtins::wirth.add_literal(U"#");
parlex::builtins::string_terminal & period = parlex::builtins::wirth.add_literal(U".");
parlex::builtins::string_terminal & equals = parlex::builtins::wirth.add_literal(U"=");
parlex::builtins::string_terminal & quote = parlex::builtins::wirth.add_literal(U"\"");
parlex::builtins::string_terminal & pipe = parlex::builtins::wirth.add_literal(U"|");
parlex::builtins::string_terminal & openSquare = parlex::builtins::wirth.add_literal(U"[");
parlex::builtins::string_terminal & closeSquare = parlex::builtins::wirth.add_literal(U"]");
parlex::builtins::string_terminal & openParen = parlex::builtins::wirth.add_literal(U"(");
parlex::builtins::string_terminal & closeParen = parlex::builtins::wirth.add_literal(U")");
parlex::builtins::string_terminal & openCurly = parlex::builtins::wirth.add_literal(U"{");
parlex::builtins::string_terminal & closeCurly = parlex::builtins::wirth.add_literal(U"}");
parlex::builtins::string_terminal & underscore = parlex::builtins::wirth.add_literal(U"_");
parlex::builtins::string_terminal & dollarSign = parlex::builtins::wirth.add_literal(U"$");
parlex::builtins::string_terminal & percentageSign = parlex::builtins::wirth.add_literal(U"%");


parlex::state_machine & whiteSpaceDfa = parlex::builtins::wirth.add_production("whiteSpace", 0, 1, &parlex::builtins::longest);
parlex::state_machine & commentDfa = parlex::builtins::wirth.add_production("comment", 0, 1);
parlex::state_machine & productionDfa = parlex::builtins::wirth.add_production("production", 0, 1);
parlex::state_machine & expressionDfa = parlex::builtins::wirth.add_production("expression", 0, 1);
parlex::state_machine & termDfa = parlex::builtins::wirth.add_production("term", 0, 1);
parlex::state_machine & parentheticalDfa = parlex::builtins::wirth.add_production("parenthetical", 0, 1);
parlex::state_machine & tagDfa = parlex::builtins::wirth.add_production("tag", 0, 1);
parlex::state_machine & factorDfa = parlex::builtins::wirth.add_production("factor", 0, 1);
parlex::state_machine & identifierDfa = parlex::builtins::wirth.add_production("identifier", 0, 1, &parlex::builtins::longest);
parlex::state_machine & root = parlex::builtins::wirth.add_production("root", 0, 1);

int build() {
	root.add_transition(0, productionDfa, 0);
	root.add_transition(0, whiteSpaceDfa, 0);
	root.add_transition(0, commentDfa, 0);

	whiteSpaceDfa.add_transition(0, parlex::builtins::white_space, 1);
	whiteSpaceDfa.add_transition(1, parlex::builtins::white_space, 1);

	commentDfa.add_transition(0, hash, 1);
	commentDfa.add_transition(1, parlex::builtins::not_newline, 1);
	commentDfa.add_transition(1, newline, 2);

	productionDfa.add_transition(0, identifierDfa, 1);

	productionDfa.add_transition(1, whiteSpaceDfa, 2);
	productionDfa.add_transition(2, equals, 3);
	productionDfa.add_transition(1, equals, 3);

	productionDfa.add_transition(3, whiteSpaceDfa, 4);
	productionDfa.add_transition(4, expressionDfa, 5);
	productionDfa.add_transition(3, expressionDfa, 5);

	productionDfa.add_transition(5, whiteSpaceDfa, 6);
	productionDfa.add_transition(6, period, 7);
	productionDfa.add_transition(5, period, 7);

	expressionDfa.add_transition(0, termDfa, 3);
	expressionDfa.add_transition(1, termDfa, 3);
	expressionDfa.add_transition(1, whiteSpaceDfa, 0);
	expressionDfa.add_transition(2, pipe, 1);
	expressionDfa.add_transition(3, pipe, 1);
	expressionDfa.add_transition(3, whiteSpaceDfa, 2);

	termDfa.add_transition(0, factorDfa, 1);
	termDfa.add_transition(1, whiteSpaceDfa, 0);
	termDfa.add_transition(1, factorDfa, 1);

	parentheticalDfa.add_transition(0, openSquare, 1);
	parentheticalDfa.add_transition(1, whiteSpaceDfa, 2);
	parentheticalDfa.add_transition(1, expressionDfa, 3);
	parentheticalDfa.add_transition(2, expressionDfa, 3);
	parentheticalDfa.add_transition(3, whiteSpaceDfa, 4);
	parentheticalDfa.add_transition(3, closeSquare, 13);
	parentheticalDfa.add_transition(4, closeSquare, 13);

	parentheticalDfa.add_transition(0, openParen, 5);
	parentheticalDfa.add_transition(5, whiteSpaceDfa, 6);
	parentheticalDfa.add_transition(5, expressionDfa, 7);
	parentheticalDfa.add_transition(6, expressionDfa, 7);
	parentheticalDfa.add_transition(7, whiteSpaceDfa, 8);
	parentheticalDfa.add_transition(7, closeParen, 13);
	parentheticalDfa.add_transition(8, closeParen, 13);

	parentheticalDfa.add_transition(0, openCurly, 9);
	parentheticalDfa.add_transition(9, whiteSpaceDfa, 10);
	parentheticalDfa.add_transition(9, expressionDfa, 11);
	parentheticalDfa.add_transition(10, expressionDfa, 11);
	parentheticalDfa.add_transition(11, whiteSpaceDfa, 12);
	parentheticalDfa.add_transition(11, closeCurly, 13);
	parentheticalDfa.add_transition(12, closeCurly, 13);

	tagDfa.add_transition(0, percentageSign, 1);
	tagDfa.add_transition(1, identifierDfa, 2);

	factorDfa.add_transition(0, identifierDfa, 3);
	factorDfa.add_transition(0, parlex::builtins::c_string, 3);
	factorDfa.add_transition(0, parentheticalDfa, 3);
	factorDfa.add_transition(0, tagDfa, 1);
	factorDfa.add_transition(1, parentheticalDfa, 3);
	factorDfa.add_transition(0, dollarSign, 2);
	factorDfa.add_transition(2, identifierDfa, 3);
	factorDfa.add_transition(2, parlex::builtins::c_string, 3);

	identifierDfa.add_transition(0, parlex::builtins::letter, 1);
	identifierDfa.add_transition(1, parlex::builtins::letter, 1);
	identifierDfa.add_transition(1, underscore, 1);

	parlex::builtins::wirth.add_precedence(factorDfa, factorDfa);

	return 0;
}

int dont_care = build();

std::shared_ptr<parlex::details::behavior_node> get_or_add_production(std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes, std::string name) {
	auto i = productionNodes.find(name);
	std::shared_ptr<parlex::details::production> q;
	if (i == productionNodes.end()) {
		q.reset(new parlex::details::production(name));
		productionNodes[name] = q;
	} else {
		q = i->second;
	}
	return q;
}

std::shared_ptr<parlex::details::behavior_node> get_or_add_literal(std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::u32string temp) {
	auto i = literalNodes.find(temp);
	std::shared_ptr<parlex::details::literal> l;
	if (i == literalNodes.end()) {
		l.reset(new parlex::details::literal(temp));
		literalNodes[temp] = l;
	} else {
		l = i->second;
	}
	return l;
}

std::shared_ptr<parlex::details::behavior_node> process_expression(std::u32string document, parlex::match const & expression, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes);

std::shared_ptr<parlex::details::behavior_node> process_factor(std::u32string document, parlex::match const & factor, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes) {
	parlex::permutation const & p = *asg.permutations.find(factor)->second.begin();
	auto i = p.begin();
	std::string tag;
	if (&i->r == &dollarSign) {
		++i;
		if (&i->r == &identifierDfa) {
			tag = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		} else if (&i->r == &parlex::builtins::c_string) {
			tag = to_utf8(parlex::builtins::c_string_t::extract(document, *i, asg));
		} else {
			throw;
		}
	}

	if (&i->r == &tagDfa) {
		auto const & sub = *asg.permutations.find(*i)->second.begin();
		++i;
		tag = to_utf8(document.substr(sub[1].document_position, sub[1].consumed_character_count));
		assert(&i->r == &parentheticalDfa);
	}

	if (&i->r == &whiteSpaceDfa) {
		++i;
	}

	std::shared_ptr<parlex::details::behavior_node> result;
	if (&i->r == &identifierDfa) {
		std::string name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		result = get_or_add_production(productionNodes, name);
	} else if (&i->r == &parlex::builtins::c_string) {
		std::u32string temp = parlex::builtins::c_string_t::extract(document, *i, asg);
		result = get_or_add_literal(literalNodes, temp);
	} else if (&i->r == &parentheticalDfa) {
		parlex::permutation const & q = *asg.permutations.find(*i)->second.begin();
		auto j = q.begin();
		auto parenthetical_type = &j->r;
		++j;
		if (parenthetical_type == &openSquare) {
			result = std::make_shared<parlex::details::optional>(process_expression(document, *j, asg, literalNodes, productionNodes));
		} else if (parenthetical_type == &openCurly) {
			result = std::make_shared<parlex::details::repetition>(process_expression(document, *j, asg, literalNodes, productionNodes));
		} else if (parenthetical_type == &openParen) {
			result = process_expression(document, *j, asg, literalNodes, productionNodes);
		} else {
			throw;
		}
	} else {
		throw;
	}

	if (tag != "") {
		result->tag = tag;
	}
	return result;
}

std::shared_ptr<parlex::details::behavior_node> process_term(std::u32string document, parlex::match const & term, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes) {
	std::vector<parlex::match> factors;

	parlex::permutation const & p = *(*asg.permutations.find(term)).second.begin();
	for (parlex::match const & entry : p) {
		if (&entry.r == &factorDfa) {
			factors.push_back(entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor(document, factors[0], asg, literalNodes, productionNodes);
	}
	parlex::details::sequence * sequence = new parlex::details::sequence;
	for (parlex::match const & factor : factors) {
		sequence->children.push_back(process_factor(document, factor, asg, literalNodes, productionNodes));
	}
	return std::shared_ptr<parlex::details::behavior_node>(sequence);
}

std::shared_ptr<parlex::details::behavior_node> process_expression(std::u32string document, parlex::match const & expression, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes) {
	std::vector<parlex::match> terms;

	parlex::permutation const & p = *(*asg.permutations.find(expression)).second.begin();
	for (parlex::match const & entry : p) {
		if (&entry.r == &termDfa) {
			terms.push_back(entry);
		}
	}
	if (terms.size() == 1) {
		return process_term(document, terms[0], asg, literalNodes, productionNodes);
	}
	parlex::details::choice * choice = new parlex::details::choice;
	for (parlex::match const & term : terms) {
		choice->children.push_back(process_term(document, term, asg, literalNodes, productionNodes));
	}
	return std::shared_ptr<parlex::details::behavior_node>(choice);
}

std::shared_ptr<parlex::details::behavior_node> process_production(std::u32string document, parlex::match const & production, parlex::abstract_syntax_graph const & asg) {
	for (parlex::match const & entry : *(*asg.permutations.find(production)).second.begin()) {
		if (&entry.r == &expressionDfa) {
			std::map<std::u32string, std::shared_ptr<parlex::details::literal>> literalNodes;
			std::map<std::string, std::shared_ptr<parlex::details::production>> productionNodes;
			return process_expression(document, entry, asg, literalNodes, productionNodes);
		}
	}
	throw;
}

}

static void ensure_c_string_present() {
	(void)dont_care;
}

namespace parlex {

grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) {
	ensure_c_string_present();
	parser p;
	abstract_syntax_graph asg = p.parse(builtins::wirth, document);
	std::string check = asg.to_dot();
	permutation const & top = *asg.permutations[asg.root].begin();
	std::vector<state_machine> machines;
	std::map<std::string, std::shared_ptr<details::behavior_node>> trees;
	for (match const & entry : top) {
		if (&entry.r == &productionDfa) {
			std::shared_ptr<details::behavior_node> behavior = process_production(document, entry, asg);
			match const & namePart = (*asg.permutations[entry].begin())[0];
			std::string name = to_utf8(document.substr(namePart.document_position, namePart.consumed_character_count));
			recognizer const * dontCare;
			if (builtins::resolve_builtin(name, dontCare)) {
				throw std::logic_error((name + " is a reserved name.").c_str()); // name is reserved for a builtin
			}
			trees[name] = behavior;
		}
	}
	return grammar(nameOfMain, trees, associativities, longestNames);
}

grammar load_grammar(std::string const & nameOfMain, std::map<std::string, wirth_production_def> const & productions) {
	ensure_c_string_present();
	parser p;
	std::map<std::string, production_def> temp;
	std::map<std::u32string, std::shared_ptr<details::literal>> literalNodes;
	std::map<std::string, std::shared_ptr<details::production>> productionNodes;
	for (auto const & entry : productions) {
		production_def def;
		auto asg = p.parse(builtins::wirth, expressionDfa, entry.second.definition);
		auto test = asg.to_dot(); //TODO: Make sure this is commented out
		def.tree = process_expression(entry.second.definition, asg.root, asg, literalNodes, productionNodes);
		def.assoc = entry.second.assoc;
		def.precedences = entry.second.precedences;
		def.filter = entry.second.filter;
		temp[entry.first] = def;
	}
	return grammar(nameOfMain, temp);
}

}
