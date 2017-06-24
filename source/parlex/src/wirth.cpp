#include "parlex/details/wirth.hpp"

#include "parlex/details/builtins.hpp"

#include "parlex/details/parser.hpp"

#include "utils.hpp"
#include "parlex/builder.hpp"
#include "utf.hpp"
#include <iostream>

namespace parlex {
namespace details {

erased<node> wirth_t::process_factor(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg) const {
	permutation const & p = *asg.permutations.find(factor)->second.begin();
	auto i = p.begin();
	std::string tag;
	if (&i->r == &dollarSign) {
		++i;
		if (&i->r == &identifierDfa) {
			tag = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		} else if (&i->r == &builtins().c_string) {
			tag = to_utf8(builtins().c_string.extract(document, *i, asg));
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

	std::unique_ptr<erased<node>> result;
	auto set = [&result](erased<node> const & node) { result.reset(new erased<details::node>(node)); };
	if (&i->r == &identifierDfa) {
		std::string name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		set(reference(name));
	} else if (&i->r == &builtins().c_string) {
		std::u32string text = builtins().c_string.extract(document, *i, asg);
		set(literal(text));
	} else if (&i->r == &parentheticalDfa) {
		permutation const & q = *asg.permutations.find(*i)->second.begin();
		auto j = q.begin();
		auto parenthetical_type = &j->r;
		while (&j->r != &expressionDfa) {
			++j;
		}
		if (parenthetical_type == &openSquare) {
			set(optional_t(process_expression(document, *j, asg)));
		} else if (parenthetical_type == &openCurly) {
			set(repetition_t(process_expression(document, *j, asg)));
		} else if (parenthetical_type == &openParen) {
			set(process_expression(document, *j, asg));
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

erased<node> wirth_t::process_term(std::u32string const & document, match const & term, abstract_syntax_graph const & asg) const {
	std::vector<match> factors;

	permutation const & p = *(*asg.permutations.find(term)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &factorDfa) {
			factors.push_back(entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor(document, factors[0], asg);
	}
	sequence_t result;
	for (match const & factor : factors) {
		result.children.push_back(process_factor(document, factor, asg));
	}
	return result;
}

erased<node> wirth_t::process_expression(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg) const {
	std::vector<match> terms;

	permutation const & p = *(*asg.permutations.find(expression)).second.begin();
	for (match const & entry : p) {
		if (&entry.r == &termDfa) {
			terms.push_back(entry);
		}
	}
	if (terms.size() == 1) {
		return process_term(document, terms[0], asg);
	}
	choice_t result;
	for (match const & term : terms) {
		result.children.push_back(process_term(document, term, asg));
	}
	return result;
}

erased<node> wirth_t::compile_expression(std::u32string const & source) const {
	parser p;
	auto asg = p.parse(*this, expressionDfa, source, builtins().progress_bar);
	if (!asg.is_rooted()) {
		throw std::runtime_error("could not parse expression");
	}
	if (asg.variation_count() > 1) {
		throw std::runtime_error("more than one interpretation of the source");
	}
	//auto test = asg.to_dot(); //TODO: Make sure this is commented out
	return process_expression(source, asg.root, asg);
}

builder wirth_t::load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) const {
	std::set<std::string> names;
	builder result;
	result.root_id = rootId;
	for (auto const & entry : definitions) {
		auto const & id = entry.first;
		auto const & definition = entry.second;
		auto res = names.insert(entry.first);
		if (!res.second) {
			throw std::runtime_error(("duplicate reference ID " + id).c_str());
		}
		std::cout << "\n" << id << "\n";
		result.productions.emplace_back(id, compile_expression(definition.source), definition.assoc, definition.filter, definition.precedences);
	}
	return result;
}


builder wirth_t::load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) const {
	parser p;
	abstract_syntax_graph asg = p.parse(*this, document);
	std::set<std::u32string> names;
	throw_assert(asg.is_rooted());
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
					break;
				}
			}
			auto assoc = associativities.count(name) > 0 ? associativities.find(name)->second : associativity::none;
			auto filter = longestNames.count(name) > 0 ? builtins().longest : filter_function();
			definitions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, std::set<std::string>()));
		}
	}
	return load_grammar(rootId, definitions);
}

wirth_t::production::production(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences) : source(source), assoc(assoc), filter(filter), precedences(precedences) {
}

builder generate_wirth() {
	return builder("root", {
		               production("whiteSpace", sequence({
			                          reference("white_space"),
			                          repetition(reference("white_space"))}),
		                          associativity::none, builtins().longest
		               ),

		               production("comment", sequence({
			                          literal("#"),
			                          repetition(reference("not_newline")),
			                          literal("\n")
		                          })),

		               production("identifier", sequence({
			                          choice({reference("letter"), literal("_")}),
			                          repetition(choice({reference("letter"), literal("_"), reference("decimal_digit")}))
		                          }),
		                          associativity::none, builtins().longest),

		               production("production", sequence({
			                          reference("identifier"),
			                          optional(reference("whiteSpace")),
			                          literal(U"="),
			                          optional(reference("whiteSpace")),
			                          reference("expression"),
			                          optional(reference("whiteSpace")),
			                          literal(U".")
		                          })),

		               production("expression", sequence({
			                          reference("term"),
			                          repetition(sequence({
				                          optional(reference("whiteSpace")),
				                          literal("|"),
				                          optional(reference("whiteSpace")),
				                          reference("term")
			                          }))
		                          })),

		               production("term", sequence({
			                          reference("factor"),
			                          repetition(sequence({
				                          optional(reference("whiteSpace")),
				                          reference("factor")
			                          }))
		                          })),

		               production("parenthetical", choice({
			                          sequence({
				                          literal("["), optional(reference("whiteSpace")), reference("expression"), optional(reference("whiteSpace")), literal("]")
			                          }),
			                          sequence({
				                          literal("("), optional(reference("whiteSpace")), reference("expression"), optional(reference("whiteSpace")), literal(")")
			                          }),
			                          sequence({
				                          literal("{"), optional(reference("whiteSpace")), reference("expression"), optional(reference("whiteSpace")), literal("}")
			                          })
		                          })),

		               production("tag", sequence({literal("%"), reference("identifier")})),

		               production("factor", choice({
			                          sequence({optional(literal("$")), reference("identifier")}),
			                          sequence({optional(literal("$")), reference("c_string")}),
			                          sequence({optional(reference("tag")), reference("parenthetical")})
		                          }), associativity::none, filter_function(), {"factor"}),

		               production("root", repetition(choice({
			                          reference("production"),
			                          reference("comment"),
			                          reference("whiteSpace")
		                          })))
	               });

}

static state_machine const & convert(state_machine_base const & s) {
	return *static_cast<state_machine const *>(&s);
}

wirth_t::wirth_t() : grammar(generate_wirth()),
                               openSquare(get_literal("[")),
                               openParen(get_literal("(")),
                               openCurly(get_literal("{")),
                               dollarSign(get_literal("$")),

                               productionDfa(convert(get_state_machine("production"))),
                               expressionDfa(convert(get_state_machine("expression"))),
                               termDfa(convert(get_state_machine("term"))),
                               parentheticalDfa(convert(get_state_machine("parenthetical"))),
                               tagDfa(convert(get_state_machine("tag"))),
                               factorDfa(convert(get_state_machine("factor"))),
                               identifierDfa(convert(get_state_machine("identifier"))) {
	std::string check = termDfa.to_dot();

}

erased<node> wirth_t::process_production(std::u32string const & document, match const & production, abstract_syntax_graph const & asg) const {
	for (match const & entry : *(*asg.permutations.find(production)).second.begin()) {
		if (&entry.r == &expressionDfa) {
			return process_expression(document, entry, asg);
		}
	}
	throw;
}


} //namespace details
details::wirth_t const& wirth() {
	static details::wirth_t value;
	return value;
}
} //namespace parlex
