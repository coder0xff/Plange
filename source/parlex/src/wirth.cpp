#include "parlex/detail/wirth.hpp"

#include "parlex/detail/builtins.hpp"

#include "parlex/detail/parser.hpp"

#include "utils.hpp"
#include "parlex/builder.hpp"
#include "utf.hpp"
#include <iostream>

namespace parlex {
namespace detail {

erased<node> wirth_t::process_factor(std::u32string const & document, ast_node const & factor) const {
	auto i = factor.children.begin();
	std::string tag;
	if (&i->r == &dollar_sign) {
		++i;
		if (&i->r == &identifier_dfa) {
			tag = tolower(to_utf8(document.substr(i->document_position, i->consumed_character_count)));
		} else if (&i->r == &builtins().c_string) {
			tag = to_utf8(builtins().c_string.extract(document, *i));
		} else {
			throw;
		}
	}
	
	if (&i->r == &tag_dfa) {
		auto const & j = i->children[1];
		++i;
		throw_assert(&j.r == &identifier_dfa);
		tag = to_utf8(document.substr(j.document_position, j.consumed_character_count));
	}

	std::unique_ptr<erased<node>> result;
	auto set = [&result](erased<node> const & node) { result.reset(new erased<detail::node>(node)); };
	if (&i->r == &identifier_dfa) {
		auto const name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		set(reference(name));
	} else if (&i->r == &builtins().c_string) {
		auto const text = builtins().c_string.extract(document, *i);
		set(literal(text));
	} else if (&i->r == &parenthetical_dfa) {
		auto const & q = i->children;
		auto j = q.begin();
		auto const parentheticalType = &j->r;
		while (&j->r != &expression_dfa) {
			++j;
		}
		if (parentheticalType == &open_square) {
			set(optional_t(process_expression(document, *j)));
		} else if (parentheticalType == &open_curly) {
			set(repetition_t(process_expression(document, *j)));
		} else if (parentheticalType == &open_paren) {
			set(process_expression(document, *j));
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

erased<node> wirth_t::process_term(std::u32string const & document, ast_node const & term) const {
	std::vector<ast_node const *> factors;

	for (auto const & entry : term.children) {
		if (&entry.r == &factor_dfa) {
			factors.push_back(&entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor(document, *factors[0]);
	}
	sequence_t result;
	for (auto factor : factors) {
		result.children.push_back(process_factor(document, *factor));
	}
	return result;
}

erased<node> wirth_t::process_expression(std::u32string const & document, ast_node const & expression) const {
	std::vector<ast_node const *> terms;

	auto const & p = expression.children;
	for (auto const & entry : p) {
		if (&entry.r == &term_dfa) {
			terms.push_back(&entry);
		}
	}
	if (terms.size() == 1) {
		return process_term(document, *terms[0]);
	}
	choice_t result;
	for (auto term : terms) {
		result.children.push_back(process_term(document, *term));
	}
	return result;
}

erased<node> wirth_t::compile_expression(std::u32string const & source) const {
	parser p;
	auto assl = p.parse(*this, expression_dfa, source, builtins().progress_bar);
	if (!assl.is_rooted()) {
		throw std::runtime_error("could not parse expression");
	}
	auto const ast = assl.tree();
	return process_expression(source, ast);
}

builder wirth_t::load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) const {
	std::set<std::string> names;
	builder result;
	result.root_id = rootId;
	for (auto const & entry : definitions) {
		auto const & id = entry.first;
		auto const & definition = entry.second;
		auto const res = names.insert(entry.first);
		if (!res.second) {
			throw std::runtime_error(("duplicate reference ID " + id).c_str());
		}
		result.productions.emplace_back(id, compile_expression(definition.source), definition.assoc, definition.filter, definition.precedences);
	}
	return result;
}


builder wirth_t::load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) const {
	parser p;
	auto assl = p.parse(*this, document);
	auto const ast = assl.tree();
	std::set<std::u32string> names;
	std::map<std::string, production> definitions;
	auto const & top = ast.children;
	for (auto const & entry : top) {
		if (&entry.r == &production_dfa) {
			auto const & namePart = entry.children[0];
			auto const u32Name = document.substr(namePart.document_position, namePart.consumed_character_count);
			auto const name = to_utf8(u32Name);
			auto const res = names.insert(u32Name);
			if (!res.second) {
				throw std::runtime_error(("duplicate reference ID " + name).c_str());
			}
			std::u32string source;
			for (auto const & entry2 : entry.children) {
				if (&entry2.r == &expression_dfa) {
					source = document.substr(entry2.document_position, entry2.consumed_character_count);
					break;
				}
			}
			auto assoc = associativities.count(name) > 0 ? associativities.find(name)->second : associativity::NONE;
			auto filter = longestNames.count(name) > 0 ? builtins().longest : filter_function();
			definitions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, std::set<std::string>()));
		}
	}
	return load_grammar(rootId, definitions);
}

wirth_t::production::production(std::u32string const & source, associativity const assoc, filter_function const filter, std::set<std::string> const & precedences) : source(source), assoc(assoc), filter(filter), precedences(precedences) {
}

builder generate_wirth() {
	return builder("root", {
		               production("whiteSpace", sequence({
			                          reference("white_space"),
			                          repetition(reference("white_space"))}),
		                          associativity::NONE, builtins().longest
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
		                          associativity::NONE, builtins().longest),

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
		                          }), associativity::NONE, filter_function(), {"factor"}),

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
                               open_square(grammar::get_literal("[")),
                               open_paren(grammar::get_literal("(")),
                               open_curly(grammar::get_literal("{")),
                               dollar_sign(grammar::get_literal("$")),

                               production_dfa(convert(grammar::get_state_machine("production"))),
                               expression_dfa(convert(grammar::get_state_machine("expression"))),
                               term_dfa(convert(grammar::get_state_machine("term"))),
                               parenthetical_dfa(convert(grammar::get_state_machine("parenthetical"))),
                               tag_dfa(convert(grammar::get_state_machine("tag"))),
                               factor_dfa(convert(grammar::get_state_machine("factor"))),
                               identifier_dfa(convert(grammar::get_state_machine("identifier"))) {
}

erased<node> wirth_t::process_production(std::u32string const & document, ast_node const & production) const {
	for (auto const & entry : production.children) {
		if (&entry.r == &expression_dfa) {
			return process_expression(document, entry);
		}
	}
	throw;
}


} //namespace detail
detail::wirth_t const& wirth() {
	static detail::wirth_t value;
	return value;
}
} //namespace parlex
