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

	tagDfa.add_transition(0, dollarSign, 1);
	tagDfa.add_transition(1, identifierDfa, 2);

	factorDfa.add_transition(0, identifierDfa, 2);
	factorDfa.add_transition(0, parlex::builtins::c_string, 2);
	factorDfa.add_transition(0, parentheticalDfa, 2);
	factorDfa.add_transition(0, tagDfa, 1);
	factorDfa.add_transition(1, parentheticalDfa, 2);

	identifierDfa.add_transition(0, parlex::builtins::letter, 1);
	identifierDfa.add_transition(1, parlex::builtins::letter, 1);
	identifierDfa.add_transition(1, underscore, 1);

	return 0;
}

int dont_care = build();

std::shared_ptr<parlex::details::behavior_node> process_expression(std::u32string document, parlex::match const & expression, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes);

std::shared_ptr<parlex::details::behavior_node> process_factor(std::u32string document, parlex::match const & factor, parlex::abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<parlex::details::literal>> & literalNodes, std::map<std::string, std::shared_ptr<parlex::details::production>> & productionNodes) {
	parlex::permutation const & p = *asg.permutations.find(factor)->second.begin();
	parlex::recognizer const * const underlying = &p[0].r;
	if (underlying == &identifierDfa) {
		std::string name = to_utf8(document.substr(factor.document_position, factor.consumed_character_count));

		auto i = productionNodes.find(name);
		std::shared_ptr<parlex::details::production> q;
		if (i == productionNodes.end()) {
			q.reset(new parlex::details::production(name));
			productionNodes[name] = q;
		}
		else {
			q = i->second;
		}
		return q;
	}
	if (underlying == &parlex::builtins::c_string) {
		std::u32string temp = parlex::builtins::c_string_t::extract(document, p[0], asg);

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
	std::shared_ptr<parlex::match> expression(new parlex::match(p[1]));
	if (&expression->r == &whiteSpaceDfa) {
		expression.reset(new parlex::match(p[2]));
	}
	if (underlying == &openSquare) {
		return std::static_pointer_cast<parlex::details::behavior_node>(std::make_shared<parlex::details::optional>(process_expression(document, *expression, asg, literalNodes, productionNodes)));
	}
	if (underlying == &openCurly) {
		return std::static_pointer_cast<parlex::details::behavior_node>(std::make_shared<parlex::details::repetition>(process_expression(document, *expression, asg, literalNodes, productionNodes)));
	}
	if (underlying == &openParen) {
		return process_expression(document, *expression, asg, literalNodes, productionNodes);
	}
	throw;
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
	parlex::details::sequence *sequence = new parlex::details::sequence;
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
	parlex::details::choice *choice = new parlex::details::choice;
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

namespace parlex {

grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) {
	(void)dont_care;
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
	(void)dont_care;
	parser p;
	std::map<std::string, production_def> temp;
	std::map<std::u32string, std::shared_ptr<details::literal>> literalNodes;
	std::map<std::string, std::shared_ptr<details::production>> productionNodes;
	for (auto const & entry : productions) {
		production_def def;
		abstract_syntax_graph asg = p.parse(builtins::wirth, expressionDfa, entry.second.definition);
		def.tree = process_expression(entry.second.definition, asg.root, asg, literalNodes, productionNodes);
		def.assoc = entry.second.assoc;
		def.precedences = entry.second.precedences;
		def.filter = entry.second.filter;
		temp[entry.first] = def;
	}
	return grammar(nameOfMain, temp);
}

}

