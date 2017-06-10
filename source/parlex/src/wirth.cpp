#include "parlex/details/wirth.hpp"

#include "parlex/parser.hpp"
#include "parlex/details/behavior.hpp"

#include "parlex/builtins.hpp"
#include "utils.hpp"

namespace parlex {

namespace details {

grammar wirth_t::load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames)
{
	parser p;
	abstract_syntax_graph asg = p.parse(g, document);
	std::string check = asg.to_dot();
	permutation const & top = *asg.permutations[asg.root].begin();
	std::vector<state_machine> machines;
	std::map<std::string, std::shared_ptr<behavior_node>> trees;
	for (match const & entry : top) {
		if (&entry.r == &productionDfa) {
			std::shared_ptr<behavior_node> behavior = process_production(document, entry, asg);
			match const & namePart = (*asg.permutations[entry].begin())[0];
			std::string name = to_utf8(document.substr(namePart.document_position, namePart.consumed_character_count));
			recognizer const * dontCare;
			if (g.builtins.resolve_builtin(name, dontCare)) {
				throw std::logic_error((name + " is a reserved name.").c_str()); // name is reserved for a builtin
			}
			trees[name] = behavior;
		}
	}
	return grammar(g.builtins, nameOfMain, trees, associativities, longestNames);
}

grammar wirth_t::load_grammar(std::string const & nameOfMain, std::map<std::string, production_def> const & productions)
{
	parser p;
	std::map<std::string, grammar::production_def> trees;
	std::map<std::u32string, std::shared_ptr<literal>> literalNodes;
	std::map<std::string, std::shared_ptr<production>> productionNodes;
	for (auto const & entry : productions) {
		grammar::production_def def;
		auto asg = p.parse(g, expressionDfa, entry.second.definition);
		if (!asg.is_rooted()) {
			throw std::exception("could not parse expression");
		}
		//auto test = asg.to_dot(); //TODO: Make sure this is commented out
		def.tree = process_expression(entry.second.definition, asg.root, asg, literalNodes, productionNodes);
		def.assoc = entry.second.assoc;
		def.precedences = entry.second.precedences;
		def.filter = entry.second.filter;
		trees[entry.first] = def;
	}
	auto test = g.hierarchy_dot(trees);
	return grammar(g.builtins, nameOfMain, trees);
}

std::shared_ptr<behavior_node> wirth_t::get_or_add_production(std::map<std::string, std::shared_ptr<production>> & productionNodes, std::string name)
{
	auto i = productionNodes.find(name);
	std::shared_ptr<production> q;
	if (i == productionNodes.end()) {
		q.reset(new production(name));
		productionNodes[name] = q;
	}
	else {
		q = i->second;
	}
	return q;
}

std::shared_ptr<behavior_node> wirth_t::get_or_add_literal(std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::u32string temp)
{
	auto i = literalNodes.find(temp);
	std::shared_ptr<literal> l;
	if (i == literalNodes.end()) {
		l.reset(new literal(temp));
		literalNodes[temp] = l;
	}
	else {
		l = i->second;
	}
	return l;
}

wirth_t::wirth_t(parser const & p) : grammar_base(p.builtins), p(p), g(p.builtins, "root"),
	newline(g.add_literal(U"\n")),
	hash(g.add_literal(U"#")),
	period(g.add_literal(U".")),
	equals(g.add_literal(U"=")),
	quote(g.add_literal(U"\"")),
	pipe(g.add_literal(U"|")),
	openSquare(g.add_literal(U"[")),
	closeSquare(g.add_literal(U"]")),
	openParen(g.add_literal(U"(")),
	closeParen(g.add_literal(U")")),
	openCurly(g.add_literal(U"{")),
	closeCurly(g.add_literal(U"}")),
	underscore(g.add_literal(U"_")),
	dollarSign(g.add_literal(U"$")),
	percentageSign(g.add_literal(U"%")),
	
	whiteSpaceDfa(g.add_production("whiteSpace", 0, 1, p.builtins.longest)),
	commentDfa(g.add_production("comment", 0, 1)),
	productionDfa(g.add_production("production", 0, 1)),
	expressionDfa(g.add_production("expression", 0, 1)),
	termDfa(g.add_production("term", 0, 1)),
	parentheticalDfa(g.add_production("parenthetical", 0, 1)),
	tagDfa(g.add_production("tag", 0, 1)),
	factorDfa(g.add_production("factor", 0, 1)),
	identifierDfa(g.add_production("identifier", 0, 1, p.builtins.longest)),
	root(g.add_production("root", 0, 1))
	
	{
	root.add_transition(0, productionDfa, 0);
	root.add_transition(0, whiteSpaceDfa, 0);
	root.add_transition(0, commentDfa, 0);

	whiteSpaceDfa.add_transition(0, p.builtins.white_space, 1);
	whiteSpaceDfa.add_transition(1, p.builtins.white_space, 1);

	commentDfa.add_transition(0, hash, 1);
	commentDfa.add_transition(1, p.builtins.not_newline, 1);
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
	factorDfa.add_transition(0, p.builtins.c_string, 3);
	factorDfa.add_transition(0, dollarSign, 1);
	factorDfa.add_transition(1, identifierDfa, 3);
	factorDfa.add_transition(1, p.builtins.c_string, 3);
	factorDfa.add_transition(0, parentheticalDfa, 3);
	factorDfa.add_transition(0, tagDfa, 2);
	factorDfa.add_transition(2, parentheticalDfa, 3);

	identifierDfa.add_transition(0, p.builtins.letter, 1);
	identifierDfa.add_transition(0, underscore, 1);
	identifierDfa.add_transition(1, p.builtins.letter, 1);
	identifierDfa.add_transition(1, underscore, 1);
	identifierDfa.add_transition(1, p.builtins.decimal_digit, 1);

	g.add_precedence(factorDfa, factorDfa);
}

std::shared_ptr<behavior_node> wirth_t::process_factor(std::u32string document, match const & factor, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes)
{
	permutation const & p = *asg.permutations.find(factor)->second.begin();
	auto i = p.begin();
	std::string tag;
	if (&i->r == &dollarSign) {
		++i;
		if (&i->r == &identifierDfa) {
			tag = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		}
		else if (&i->r == &g.builtins.c_string) {
			tag = to_utf8(g.builtins.c_string.extract(document, *i, asg));
		}
		else {
			throw;
		}
	}

	if (&i->r == &tagDfa) {
		permutation const& q = *asg.permutations.find(*i)->second.begin();
		match const& j = q[1];
		++i;
		throw_assert(&j.r == &identifierDfa);
		tag = to_utf8(document.substr(j.document_position, j.consumed_character_count));
	}

	std::shared_ptr<behavior_node> result;
	if (&i->r == &identifierDfa) {
		std::string name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		result = get_or_add_production(productionNodes, name);
	}
	else if (&i->r == &g.builtins.c_string) {
		std::u32string temp = g.builtins.c_string.extract(document, *i, asg);
		result = get_or_add_literal(literalNodes, temp);
	}
	else if (&i->r == &parentheticalDfa) {
		permutation const & q = *asg.permutations.find(*i)->second.begin();
		auto j = q.begin();
		auto parenthetical_type = &j->r;
		while (&j->r != &expressionDfa) {
			++j;
		}
		if (parenthetical_type == &openSquare) {
			result = std::make_shared<optional>(process_expression(document, *j, asg, literalNodes, productionNodes));
		}
		else if (parenthetical_type == &openCurly) {
			result = std::make_shared<repetition>(process_expression(document, *j, asg, literalNodes, productionNodes));
		}
		else if (parenthetical_type == &openParen) {
			result = process_expression(document, *j, asg, literalNodes, productionNodes);
		}
		else {
			throw;
		}
	}
	else {
		throw;
	}

	if (tag != "") {
		result->tag = tag;
	}
	return result;
}

std::shared_ptr<behavior_node> wirth_t::process_term(std::u32string document, match const & term, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes)
{
	std::vector<match> factors;

	permutation const & p = *(*asg.permutations.find(term)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &factorDfa) {
			factors.push_back(entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor(document, factors[0], asg, literalNodes, productionNodes);
	}
	sequence * sequence = new details::sequence;
	for (match const & factor : factors) {
		sequence->children.push_back(process_factor(document, factor, asg, literalNodes, productionNodes));
	}
	return std::shared_ptr<behavior_node>(sequence);
}

std::shared_ptr<behavior_node> wirth_t::process_expression(std::u32string document, match const & expression, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes)
{
	std::vector<match> terms;

	permutation const & p = *(*asg.permutations.find(expression)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &termDfa) {
			terms.push_back(entry);
		}
	}
	if (terms.size() == 1) {
		return process_term(document, terms[0], asg, literalNodes, productionNodes);
	}
	choice * choice = new details::choice;
	for (match const & term : terms) {
		choice->children.push_back(process_term(document, term, asg, literalNodes, productionNodes));
	}
	return std::shared_ptr<behavior_node>(choice);
}

std::shared_ptr<behavior_node> wirth_t::process_production(std::u32string document, match const & production, abstract_syntax_graph const & asg)
{
	for (match const & entry : *(*asg.permutations.find(production)).second.begin()) {
		if (&entry.r == &expressionDfa) {
			std::map<std::u32string, std::shared_ptr<literal>> literalNodes;
			std::map<std::string, std::shared_ptr<details::production>> productionNodes;
			return process_expression(document, entry, asg, literalNodes, productionNodes);
		}
	}
	throw;
}

state_machine_base const & wirth_t::get_main_production() const
{
	return g.get_main_production();
}

std::map<std::string, state_machine_base const *> wirth_t::get_productions() const {
	return g.get_productions();
}

} //namespace details

} //namespace parlex

