#include "parlex/details/wirth.hpp"

#include "parlex/builtins.hpp"
#include "parlex/parser.hpp"

#include "utils.hpp"
#include "parlex/builder.hpp"
#include "utf.hpp"

namespace parlex {
namespace details {

erased<builder::node> wirth_t::process_factor2(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg) {
	permutation const & p = *asg.permutations.find(factor)->second.begin();
	auto i = p.begin();
	std::string tag;
	if (&i->r == &dollarSign) {
		++i;
		if (&i->r == &identifierDfa) {
			tag = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		} else if (&i->r == &builtins.c_string) {
			tag = to_utf8(builtins.c_string.extract(document, *i, asg));
		} else {
			throw;
		}
	}

	if (&i->r == &tagDfa) {
		permutation const & q = *asg.permutations.find(*i)->second.begin();
		match const & j = q[1];
		++i;
		throw_assert(&j.r == &identifierDfa);
		tag = to_utf8(document.substr(j.document_position, j.consumed_character_count));
	}

	std::unique_ptr<erased<builder::node>> result;
	auto set = [&result](erased<builder::node> const & node) { result.reset(new erased<builder::node>(node)); };
	if (&i->r == &identifierDfa) {
		std::string name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		set(builder::reference(name));
	} else if (&i->r == &builtins.c_string) {
		std::u32string text = builtins.c_string.extract(document, *i, asg);
		set(builder::literal(text));
	} else if (&i->r == &parentheticalDfa) {
		permutation const & q = *asg.permutations.find(*i)->second.begin();
		auto j = q.begin();
		auto parenthetical_type = &j->r;
		while (&j->r != &expressionDfa) {
			++j;
		}
		if (parenthetical_type == &openSquare) {
			set(builder::optional_t(process_expression2(document, *j, asg)));
		} else if (parenthetical_type == &openCurly) {
			set(builder::repetition_t(process_expression2(document, *j, asg)));
		} else if (parenthetical_type == &openParen) {
			set(process_expression2(document, *j, asg));
		} else {
			throw;
		}
	} else {
		throw;
	}

	if (tag != "") {
		(*result)->tag = tag;
	}
	return *result;
}

erased<builder::node> wirth_t::process_term2(std::u32string const & document, match const & term, abstract_syntax_graph const & asg) {
	std::vector<match> factors;

	permutation const & p = *(*asg.permutations.find(term)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &factorDfa) {
			factors.push_back(entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor2(document, factors[0], asg);
	}
	builder::sequence_t result;
	for (match const & factor : factors) {
		result.children.push_back(process_factor2(document, factor, asg));
	}
	return result;
}

erased<builder::node> wirth_t::process_expression2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg) {
	std::vector<match> terms;

	permutation const & p = *(*asg.permutations.find(expression)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &termDfa) {
			terms.push_back(entry);
		}
	}
	if (terms.size() == 1) {
		return process_term2(document, terms[0], asg);
	}
	builder::choice_t result;
	for (match const & term : terms) {
		result.children.push_back(process_term2(document, term, asg));
	}
	return result;
}

erased<builder::node> wirth_t::compile_source(std::u32string const & source) {
	auto asg = p.parse(*this, expressionDfa, source);
	if (!asg.is_rooted()) {
		throw std::runtime_error("could not parse expression");
	}
	//auto test = asg.to_dot(); //TODO: Make sure this is commented out
	return process_expression2(source, asg.root, asg);
}

#if 0 //to move
builder::grammar wirth_t::load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) {

	std::set<std::string> names;
	std::vector<correlated_state_machine_info> infos;
	for (auto const & definitionEntry : definitions) {
		std::string const & name = definitionEntry.first;
		production const & def = definitionEntry.second;
		auto res = names.insert(name);
		if (!res.second) {
			throw std::exception(("duplicate reference ID " + name).c_str());
		}
		infos.emplace_back(name, def.filter, def.assoc);
	}
	std::unique_ptr<correlated_grammar> result(new correlated_grammar(p.builtins, rootId, infos, [this, &definitions](std::string const & id, correlated_grammar & g) {
	                                              return compile_source(definitions.find(id)->second.source, g);
                                              }));
	return result;
}
#endif

builder::grammar wirth_t::load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) {
	std::set<std::string> names;
	builder::grammar result;
	result.root_id = rootId;
	for (auto const & entry : definitions) {
		auto const & id = entry.first;
		auto const & definition = entry.second;
		auto res = names.insert(entry.first);
		if (!res.second) {
			throw std::runtime_error(("duplicate reference ID " + id).c_str());
		}
		builder::production resultDefinition(id, compile_source(definition.source), definition.assoc, definition.filter, definition.precedences);
		resultDefinition.id = id;
		resultDefinition.behavior = compile_source(definition.source);
		resultDefinition.assoc = definition.assoc;
		resultDefinition.filter = definition.filter;
		result.productions.push_back(resultDefinition);
	}
	return result;
}


builder::grammar wirth_t::load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) {
	std::set<std::u32string> names;
	abstract_syntax_graph asg = p.parse(*this, document);
	std::map<std::string, production> definitions;
	//std::string check = asg.to_dot();
	permutation const & top = *asg.permutations[asg.root].begin();
	for (match const & entry : top) {
		if (&entry.r == &productionDfa) {
			match const & namePart = (*asg.permutations[entry].begin())[0];
			std::u32string const u32Name = document.substr(namePart.document_position, namePart.consumed_character_count);
			std::string const name = to_utf8(u32Name);
			auto res = names.insert(u32Name);
			if (!res.second) {
				throw std::runtime_error(("duplicate reference ID " + name).c_str());
			}
			std::u32string source;
			for (match const & entry2 : *(*asg.permutations.find(entry)).second.begin()) {
				if (&entry2.r == &expressionDfa) {
					source = document.substr(entry2.document_position, entry2.consumed_character_count);
				}
			}
			auto assoc = associativities.count(name) > 0 ? associativities.find(name)->second : associativity::none;
			auto filter = longestNames.count(name) > 0 ? builtins.longest : filter_function();
			definitions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, std::set<std::string>()));
		}
	}
	return load_grammar(rootId, definitions);
}

wirth_t::production::production(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences) : source(source), assoc(assoc), filter(filter), precedences(precedences) {
}

wirth_t::wirth_t(parser & p) : grammar(p.builtins, "root"), p(p),
                               newline(get_or_add_literal(U"\n")),
                               hash(get_or_add_literal(U"#")),
                               period(get_or_add_literal(U".")),
                               equals(get_or_add_literal(U"=")),
                               quote(get_or_add_literal(U"\"")),
                               pipe(get_or_add_literal(U"|")),
                               openSquare(get_or_add_literal(U"[")),
                               closeSquare(get_or_add_literal(U"]")),
                               openParen(get_or_add_literal(U"(")),
                               closeParen(get_or_add_literal(U")")),
                               openCurly(get_or_add_literal(U"{")),
                               closeCurly(get_or_add_literal(U"}")),
                               underscore(get_or_add_literal(U"_")),
                               dollarSign(get_or_add_literal(U"$")),
                               percentageSign(get_or_add_literal(U"%")),

                               whiteSpaceDfa(add_production("whiteSpace", 0, 1, p.builtins.longest)),
                               commentDfa(add_production("comment", 0, 1)),
                               productionDfa(add_production("reference", 0, 1)),
                               expressionDfa(add_production("expression", 0, 1)),
                               termDfa(add_production("term", 0, 1)),
                               parentheticalDfa(add_production("parenthetical", 0, 1)),
                               tagDfa(add_production("tag", 0, 1)),
                               factorDfa(add_production("factor", 0, 1)),
                               identifierDfa(add_production("identifier", 0, 1, p.builtins.longest)),
                               rootDfa(add_production("root", 0, 1)) {
	rootDfa.add_transition(0, &productionDfa, 0);
	rootDfa.add_transition(0, &whiteSpaceDfa, 0);
	rootDfa.add_transition(0, &commentDfa, 0);

	whiteSpaceDfa.add_transition(0, &p.builtins.white_space, 1);
	whiteSpaceDfa.add_transition(1, &p.builtins.white_space, 1);

	commentDfa.add_transition(0, &hash, 1);
	commentDfa.add_transition(1, &p.builtins.not_newline, 1);
	commentDfa.add_transition(1, &newline, 2);

	productionDfa.add_transition(0, &identifierDfa, 1);

	productionDfa.add_transition(1, &whiteSpaceDfa, 2);
	productionDfa.add_transition(2, &equals, 3);
	productionDfa.add_transition(1, &equals, 3);

	productionDfa.add_transition(3, &whiteSpaceDfa, 4);
	productionDfa.add_transition(4, &expressionDfa, 5);
	productionDfa.add_transition(3, &expressionDfa, 5);

	productionDfa.add_transition(5, &whiteSpaceDfa, 6);
	productionDfa.add_transition(6, &period, 7);
	productionDfa.add_transition(5, &period, 7);

	expressionDfa.add_transition(0, &termDfa, 3);
	expressionDfa.add_transition(1, &termDfa, 3);
	expressionDfa.add_transition(1, &whiteSpaceDfa, 0);
	expressionDfa.add_transition(2, &pipe, 1);
	expressionDfa.add_transition(3, &pipe, 1);
	expressionDfa.add_transition(3, &whiteSpaceDfa, 2);

	termDfa.add_transition(0, &factorDfa, 1);
	termDfa.add_transition(1, &whiteSpaceDfa, 0);
	termDfa.add_transition(1, &factorDfa, 1);

	parentheticalDfa.add_transition(0, &openSquare, 1);
	parentheticalDfa.add_transition(1, &whiteSpaceDfa, 2);
	parentheticalDfa.add_transition(1, &expressionDfa, 3);
	parentheticalDfa.add_transition(2, &expressionDfa, 3);
	parentheticalDfa.add_transition(3, &whiteSpaceDfa, 4);
	parentheticalDfa.add_transition(3, &closeSquare, 13);
	parentheticalDfa.add_transition(4, &closeSquare, 13);

	parentheticalDfa.add_transition(0, &openParen, 5);
	parentheticalDfa.add_transition(5, &whiteSpaceDfa, 6);
	parentheticalDfa.add_transition(5, &expressionDfa, 7);
	parentheticalDfa.add_transition(6, &expressionDfa, 7);
	parentheticalDfa.add_transition(7, &whiteSpaceDfa, 8);
	parentheticalDfa.add_transition(7, &closeParen, 13);
	parentheticalDfa.add_transition(8, &closeParen, 13);

	parentheticalDfa.add_transition(0, &openCurly, 9);
	parentheticalDfa.add_transition(9, &whiteSpaceDfa, 10);
	parentheticalDfa.add_transition(9, &expressionDfa, 11);
	parentheticalDfa.add_transition(10, &expressionDfa, 11);
	parentheticalDfa.add_transition(11, &whiteSpaceDfa, 12);
	parentheticalDfa.add_transition(11, &closeCurly, 13);
	parentheticalDfa.add_transition(12, &closeCurly, 13);

	tagDfa.add_transition(0, &percentageSign, 1);
	tagDfa.add_transition(1, &identifierDfa, 2);

	factorDfa.add_transition(0, &identifierDfa, 3);
	factorDfa.add_transition(0, &p.builtins.c_string, 3);
	factorDfa.add_transition(0, &dollarSign, 1);
	factorDfa.add_transition(1, &identifierDfa, 3);
	factorDfa.add_transition(1, &p.builtins.c_string, 3);
	factorDfa.add_transition(0, &parentheticalDfa, 3);
	factorDfa.add_transition(0, &tagDfa, 2);
	factorDfa.add_transition(2, &parentheticalDfa, 3);

	identifierDfa.add_transition(0, &p.builtins.letter, 1);
	identifierDfa.add_transition(0, &underscore, 1);
	identifierDfa.add_transition(1, &p.builtins.letter, 1);
	identifierDfa.add_transition(1, &underscore, 1);
	identifierDfa.add_transition(1, &p.builtins.decimal_digit, 1);

	precedences[&factorDfa].insert(&factorDfa);
}

erased<builder::node> wirth_t::process_production2(std::u32string const & document, match const & production, abstract_syntax_graph const & asg) {
	for (match const & entry : *(*asg.permutations.find(production)).second.begin()) {
		if (&entry.r == &expressionDfa) {
			return process_expression2(document, entry, asg);
		}
	}
	throw;
}


} //namespace details
} //namespace parlex
