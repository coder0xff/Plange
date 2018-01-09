#include "parlex/detail/wirth.hpp"

#include "parlex/detail/builtins.hpp"

#include "parlex/detail/parser.hpp"

#include "utils.hpp"
#include "parlex/builder.hpp"
#include "utf.hpp"
#include <iostream>
#include "parlex/detail/c_string.hpp"

namespace parlex {
namespace detail {

erased<node> wirth_t::process_factor(std::u32string const & document, ast_node const & factor) const {

	auto i = factor.children.begin();
	std::string tag;
	if (i->recognizer_index == dollar_sign) {
		++i;
		if (i->recognizer_index == identifier_dfa) {
			tag = tolower(to_utf8(document.substr(i->document_position, i->consumed_character_count)));
		} else if (i->recognizer_index == c_string_recognizer_index) {
			tag = to_utf8(c_string_t::extract(*this, document, *i));
		} else {
			throw;
		}
	}
	
	if (i->recognizer_index == tag_dfa) {
		auto const & j = i->children[1];
		++i;
		throw_assert(j.recognizer_index == identifier_dfa);
		tag = to_utf8(document.substr(j.document_position, j.consumed_character_count));
	}

	std::unique_ptr<erased<node>> result;
	auto const set = [&result](erased<node> const & node) { result.reset(new erased<detail::node>(node)); };
	if (i->recognizer_index == identifier_dfa) {
		auto const name = to_utf8(document.substr(i->document_position, i->consumed_character_count));
		set(reference(name));
	} else if (i->recognizer_index == c_string_recognizer_index) {
		auto const text = c_string_t::extract(*this, document, *i);
		set(literal(text));
	} else if (i->recognizer_index == parenthetical_dfa) {
		auto const & q = i->children;
		auto j = q.begin();
		auto const parentheticalType = j->recognizer_index;
		while (j->recognizer_index != expression_dfa) {
			++j;
		}
		if (parentheticalType == open_square) {
			set(optional(process_expression(document, *j)));
		} else if (parentheticalType == open_curly) {
			set(repetition(process_expression(document, *j)));
		} else if (parentheticalType == open_paren) {
			set(process_expression(document, *j));
		} else {
			throw;
		}
	} else {
		throw;
	}

	if (!tag.empty()) {
		(*result)->tag = tag;
	}
	return *result;
}

erased<node> wirth_t::process_term(std::u32string const & document, ast_node const & term) const {
	std::vector<ast_node const *> factors;

	for (auto const & entry : term.children) {
		if (entry.recognizer_index == factor_dfa) {
			factors.push_back(&entry);
		}
	}
	if (factors.size() == 1) {
		return process_factor(document, *factors[0]);
	}
	sequence result;
	for (auto factor : factors) {
		result.children.push_back(process_factor(document, *factor));
	}
	return result;
}

erased<node> wirth_t::process_expression(std::u32string const & document, ast_node const & expression) const {
	std::vector<ast_node const *> terms;

	auto const & p = expression.children;
	for (auto const & entry : p) {
		if (entry.recognizer_index == term_dfa) {
			terms.push_back(&entry);
		}
	}
	if (terms.size() == 1) {
		return process_term(document, *terms[0]);
	}
	choice result;
	for (auto term : terms) {
		result.children.push_back(process_term(document, *term));
	}
	return result;
}

erased<node> wirth_t::compile_expression(std::u32string const & source) const {
	parser p;
	auto assl = p.parse(*this, get_recognizer(expression_dfa), source, progress_bar);
	if (!assl.is_rooted()) {
		throw std::runtime_error("could not parse expression");
	}
	auto const ast = assl.tree();
	return process_expression(source, ast);
}

builder wirth_t::load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) const {
	std::set<std::string> names;
	builder result;
	result.root_name = rootId;
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


builder wirth_t::load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames, std::set<std::string> const & shortestNames) const {
	parser p;
	auto assl = p.parse(*this, document);
	auto const ast = assl.tree();
	std::set<std::u32string> names;
	std::map<std::string, production> definitions;
	auto const & top = ast.children;
	for (auto const & entry : top) {
		if (entry.recognizer_index == production_dfa) {
			auto const & namePart = entry.children[0];
			auto const u32Name = document.substr(namePart.document_position, namePart.consumed_character_count);
			auto const name = to_utf8(u32Name);
			auto const res = names.insert(u32Name);
			if (!res.second) {
				throw std::runtime_error(("duplicate reference ID " + name).c_str());
			}
			std::u32string source;
			for (auto const & entry2 : entry.children) {
				if (entry2.recognizer_index == expression_dfa) {
					source = document.substr(entry2.document_position, entry2.consumed_character_count);
					break;
				}
			}
			auto assoc = associativities.count(name) > 0 ? associativities.find(name)->second : associativity::NONE;
			auto filter = filter_function();
			if (longestNames.count(name) > 0) {
				filter = longest();
			} else if (shortestNames.count(name) > 0) {
				filter = shortest();
			}
			definitions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(source, assoc, filter, std::set<std::string>()));
		}
	}
	return load_grammar(rootId, definitions);
}

wirth_t::production::production(std::u32string const & source, associativity const assoc, filter_function const & filter, std::set<std::string> const & precedences) : source(source), assoc(assoc), filter(filter), precedences(precedences) {
}

builder generate_wirth() {
	return builder("root", {
		production("whiteSpace",
			sequence({
				reference("white_space"),
				repetition(reference("white_space"))
			}),
			associativity::NONE, longest()
		),

		production("comment",
			sequence({
				literal(U"#"),
				repetition(reference("not_newline")),
				literal(U"\n")
			})
		),

		production("identifier",
			sequence({
				choice({
					reference("letter"),
					literal(U"_")
				}),
				repetition(
					choice({
						reference("letter"),
						literal(U"_"),
						reference("decimal_digit")
					})
				)
			}),
			associativity::NONE, longest()
		),

		production("production", 
			sequence({
				reference("identifier"),
				optional(reference("whiteSpace")),
				literal(U"="),
				optional(reference("whiteSpace")),
				reference("expression"),
				optional(reference("whiteSpace")),
				literal(U".")
			})
		),

		production("expression", 
			sequence({
				reference("term"),
				repetition(
					sequence({
						optional(reference("whiteSpace")),
						literal(U"|"),
						optional(reference("whiteSpace")),
						reference("term")
					})
				)
			})
		),

		production("term", 
			sequence({
				reference("factor"),
				repetition(
					sequence({
						optional(reference("whiteSpace")),
						reference("factor")
					})
				)
			})
		),

		production("parenthetical",
			choice({
				sequence({
					literal(U"["),
					optional(reference("whiteSpace")),
					reference("expression"),
					optional(reference("whiteSpace")),
					literal(U"]")
				}),
				sequence({
					literal(U"("),
					optional(reference("whiteSpace")),
					reference("expression"),
					optional(reference("whiteSpace")),
					literal(U")")
				}),
				sequence({
					literal(U"{"),
					optional(reference("whiteSpace")),
					reference("expression"),
					optional(reference("whiteSpace")),
					literal(U"}")
				})
			})
		),

		production("tag",
			sequence({
				literal(U"%"),
				reference("identifier")
			})
		),

		production("factor", 
			choice({
				sequence({
					optional(literal(U"$")),
					reference("identifier")
				}),
				sequence({
					optional(literal(U"$")),
					reference("c_string")
				}),
				sequence({
					optional(reference("tag")),
					reference("parenthetical")
				})
			}),
			associativity::NONE, filter_function(), {"factor"}
		),

		production("root", 
			repetition(choice({
				reference("production"),
				reference("comment"),
				reference("whiteSpace")
			}))
		)
	}
);

}

wirth_t::wirth_t() : grammar(generate_wirth()),
                     open_square(lookup_literal_recognizer_index(U"[")),
                     open_paren(lookup_literal_recognizer_index(U"(")),
                     open_curly(lookup_literal_recognizer_index(U"{")),
                     dollar_sign(lookup_literal_recognizer_index(U"$")),

                     production_dfa(lookup_recognizer_index("production")),
                     expression_dfa(lookup_recognizer_index("expression")),
                     term_dfa(lookup_recognizer_index("term")),
                     parenthetical_dfa(lookup_recognizer_index("parenthetical")),
                     tag_dfa(lookup_recognizer_index("tag")),
                     factor_dfa(lookup_recognizer_index("factor")),
                     identifier_dfa(lookup_recognizer_index("identifier")),
					 c_string_recognizer_index(grammar::lookup_recognizer_index("c_string")) {}

erased<node> wirth_t::process_production(std::u32string const & document, ast_node const & production) const {
	for (auto const & entry : production.children) {
		if (entry.recognizer_index == expression_dfa) {
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
