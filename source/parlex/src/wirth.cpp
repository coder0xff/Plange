#include "parlex/details/wirth.hpp"

#include "parlex/builtins.hpp"
#include "parlex/parser.hpp"
#include "utils.hpp"
#include "parlex/grammar2.hpp"

namespace parlex {

namespace details {

static recognizer const & find_recognizer(grammar2 const & g, std::string const & id) {
	recognizer const * builtin_ptr;
	if (g.builtins.resolve_builtin(id, builtin_ptr)) {
		return *builtin_ptr;
	}
	return g.get_state_machine(id);
}

erased<behavior2::node> wirth_t::process_factor2(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg, grammar2 & g)
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

	std::unique_ptr<erased<behavior2::node>> result;
	auto set = [&result](erased<behavior2::node> const & node) { result.reset(new erased<behavior2::node>(node)); };
	if (&i->r == &identifierDfa) {
		std::string name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		set(behavior2::leaf(find_recognizer(g, name)));
	}
	else if (&i->r == &g.builtins.c_string) {
		std::u32string text = g.builtins.c_string.extract(document, *i, asg);
		set(behavior2::leaf(g.get_or_add_literal(text)));
	}
	else if (&i->r == &parentheticalDfa) {
		permutation const & q = *asg.permutations.find(*i)->second.begin();
		auto j = q.begin();
		auto parenthetical_type = &j->r;
		while (&j->r != &expressionDfa) {
			++j;
		}
		if (parenthetical_type == &openSquare) {
			set(process_expression2(document, *j, asg, g));
		}
		else if (parenthetical_type == &openCurly) {
			set(process_expression2(document, *j, asg, g));
		}
		else if (parenthetical_type == &openParen) {
			set(process_expression2(document, *j, asg, g));
		}
		else {
			throw;
		}
	}
	else {
		throw;
	}

	if (tag != "") {
		(*result)->tag = tag;
	}
	return *result;
}

erased<behavior2::node> wirth_t::process_term2(std::u32string const & document, match const & term, abstract_syntax_graph const & asg, grammar2 & g)
{
	std::vector<match> factors;

	permutation const & p = *(*asg.permutations.find(term)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &factorDfa) {
			factors.push_back(entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor2(document, factors[0], asg, g);
	}
	behavior2::sequence result;
	for (match const & factor : factors) {
		result.add_child(process_factor2(document, factor, asg, g));
	}
	return result;
}

erased<behavior2::node> wirth_t::process_expression2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg, grammar2 & g)
{
	std::vector<match> terms;

	permutation const & p = *(*asg.permutations.find(expression)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &termDfa) {
			terms.push_back(entry);
		}
	}
	if (terms.size() == 1) {
		return process_term2(document, terms[0], asg, g);
	}
	behavior2::choice result;
	for (match const & term : terms) {
		result.add_child(process_term2(document, term, asg, g));
	}
	return result;
}

erased<behavior2::node> wirth_t::compile_source(std::u32string const & source, grammar2 & g) {
	auto asg = p.parse(*this, expressionDfa, source);
	if (!asg.is_rooted()) {
		throw std::exception("could not parse expression");
	}
	//auto test = asg.to_dot(); //TODO: Make sure this is commented out
	return process_expression2(source, asg.root, asg, g);

}

std::unique_ptr<grammar2> wirth_t::load_grammar2(std::string const & nameOfMain, std::map<std::string, definition> const & definitions) {
	std::set<std::string> names;
	std::vector<state_machine2_info> infos;
	for (auto const & definitionEntry : definitions) {
		std::string const & name = definitionEntry.first;
		definition const & def = definitionEntry.second;
		auto res = names.insert(name);
		if (!res.second) {
			throw std::exception(("duplicate production ID " + name).c_str());
		}
		infos.emplace_back(name, def.filter, def.assoc);
	}
	std::unique_ptr<grammar2> result(new grammar2(p.builtins, nameOfMain, infos, [this, &definitions](std::string const & id, grammar2 & g){
		return compile_source(definitions.find(id)->second.source, g);
	}));
	return result;
}

std::unique_ptr<grammar2> wirth_t::load_grammar2(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames)
{
	std::set<std::u32string> names;
	std::map<std::string, definition> definitions;
	abstract_syntax_graph asg = p.parse(*this, document);
	//std::string check = asg.to_dot();
	permutation const & top = *asg.permutations[asg.root].begin();
	for (match const & entry : top) {
		if (&entry.r == &productionDfa) {
			match const & namePart = (*asg.permutations[entry].begin())[0];
			std::u32string const u32Name = document.substr(namePart.document_position, namePart.consumed_character_count);
			std::string const name = to_utf8(u32Name);
			auto res = names.insert(u32Name);
			if (!res.second) {
				throw std::exception(("duplicate production ID " + name).c_str());
			}
			auto assoc = associativities.count(name) > 0 ? associativities.find(name)->second : associativity::none;
			auto filter = longestNames.count(name) > 0 ? builtins.longest : filter_function();
			definitions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(u32Name, assoc, filter, std::set<std::string>()));
		}
	}
	return load_grammar2(nameOfMain, definitions);
}

wirth_t::definition::definition(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences) : source(source), assoc(assoc), filter(filter), precedences(precedences) {
}

wirth_t::wirth_t(parser & p) : grammar(p.builtins, "root"), p(p),
	newline(add_literal(U"\n")),
	hash(add_literal(U"#")),
	period(add_literal(U".")),
	equals(add_literal(U"=")),
	quote(add_literal(U"\"")),
	pipe(add_literal(U"|")),
	openSquare(add_literal(U"[")),
	closeSquare(add_literal(U"]")),
	openParen(add_literal(U"(")),
	closeParen(add_literal(U")")),
	openCurly(add_literal(U"{")),
	closeCurly(add_literal(U"}")),
	underscore(add_literal(U"_")),
	dollarSign(add_literal(U"$")),
	percentageSign(add_literal(U"%")),
	
	whiteSpaceDfa(add_production("whiteSpace", 0, 1, p.builtins.longest)),
	commentDfa(add_production("comment", 0, 1)),
	productionDfa(add_production("production", 0, 1)),
	expressionDfa(add_production("expression", 0, 1)),
	termDfa(add_production("term", 0, 1)),
	parentheticalDfa(add_production("parenthetical", 0, 1)),
	tagDfa(add_production("tag", 0, 1)),
	factorDfa(add_production("factor", 0, 1)),
	identifierDfa(add_production("identifier", 0, 1, p.builtins.longest)),
	rootDfa(add_production("root", 0, 1))
	
	{
	rootDfa.states[0][&productionDfa] = 0;
	rootDfa.states[0][&whiteSpaceDfa] = 0;
	rootDfa.states[0][&commentDfa] = 0;

	whiteSpaceDfa.states[0][&p.builtins.white_space] = 1;
	whiteSpaceDfa.states[1][&p.builtins.white_space] = 1;

	commentDfa.states[0][&hash] = 1;
	commentDfa.states[1][&p.builtins.not_newline] = 1;
	commentDfa.states[1][&newline] = 2;

	productionDfa.states[0][&identifierDfa] = 1;

	productionDfa.states[1][&whiteSpaceDfa] = 2;
	productionDfa.states[2][&equals] = 3;
	productionDfa.states[1][&equals] = 3;

	productionDfa.states[3][&whiteSpaceDfa] = 4;
	productionDfa.states[4][&expressionDfa] = 5;
	productionDfa.states[3][&expressionDfa] = 5;

	productionDfa.states[5][&whiteSpaceDfa] = 6;
	productionDfa.states[6][&period] = 7;
	productionDfa.states[5][&period] = 7;

	expressionDfa.states[0][&termDfa] = 3;
	expressionDfa.states[1][&termDfa] = 3;
	expressionDfa.states[1][&whiteSpaceDfa] = 0;
	expressionDfa.states[2][&pipe] = 1;
	expressionDfa.states[3][&pipe] = 1;
	expressionDfa.states[3][&whiteSpaceDfa] = 2;

	termDfa.states[0][&factorDfa] = 1;
	termDfa.states[1][&whiteSpaceDfa] = 0;
	termDfa.states[1][&factorDfa] = 1;

	parentheticalDfa.states[0][&openSquare] = 1;
	parentheticalDfa.states[1][&whiteSpaceDfa] = 2;
	parentheticalDfa.states[1][&expressionDfa] = 3;
	parentheticalDfa.states[2][&expressionDfa] = 3;
	parentheticalDfa.states[3][&whiteSpaceDfa] = 4;
	parentheticalDfa.states[3][&closeSquare] = 13;
	parentheticalDfa.states[4][&closeSquare] = 13;

	parentheticalDfa.states[0][&openParen] = 5;
	parentheticalDfa.states[5][&whiteSpaceDfa] = 6;
	parentheticalDfa.states[5][&expressionDfa] = 7;
	parentheticalDfa.states[6][&expressionDfa] = 7;
	parentheticalDfa.states[7][&whiteSpaceDfa] = 8;
	parentheticalDfa.states[7][&closeParen] = 13;
	parentheticalDfa.states[8][&closeParen] = 13;

	parentheticalDfa.states[0][&openCurly] = 9;
	parentheticalDfa.states[9][&whiteSpaceDfa] = 10;
	parentheticalDfa.states[9][&expressionDfa] = 11;
	parentheticalDfa.states[10][&expressionDfa] = 11;
	parentheticalDfa.states[11][&whiteSpaceDfa] = 12;
	parentheticalDfa.states[11][&closeCurly] = 13;
	parentheticalDfa.states[12][&closeCurly] = 13;

	tagDfa.states[0][&percentageSign] = 1;
	tagDfa.states[1][&identifierDfa] = 2;

	factorDfa.states[0][&identifierDfa] = 3;
	factorDfa.states[0][&p.builtins.c_string] = 3;
	factorDfa.states[0][&dollarSign] = 1;
	factorDfa.states[1][&identifierDfa] = 3;
	factorDfa.states[1][&p.builtins.c_string] = 3;
	factorDfa.states[0][&parentheticalDfa] = 3;
	factorDfa.states[0][&tagDfa] = 2;
	factorDfa.states[2][&parentheticalDfa] = 3;

	identifierDfa.states[0][&p.builtins.letter] = 1;
	identifierDfa.states[0][&underscore] = 1;
	identifierDfa.states[1][&p.builtins.letter] = 1;
	identifierDfa.states[1][&underscore] = 1;
	identifierDfa.states[1][&p.builtins.decimal_digit] = 1;

	precedences[&factorDfa].insert(&factorDfa);
}

erased<behavior2::node> wirth_t::process_production2(std::u32string const & document, match const & production, abstract_syntax_graph const & asg, grammar2 & g)
{
	for (match const & entry : *(*asg.permutations.find(production)).second.begin()) {
		if (&entry.r == &expressionDfa) {
			return process_expression2(document, entry, asg, g);
		}
	}
	throw;
}


} //namespace details

} //namespace parlex

