#include "source_code.hpp"

#include "parlex/detail/abstract_syntax_semilattice.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/recognizer.hpp"

#include "errors.hpp"
#include "plc_utils.hpp"
#include "scope.hpp"

#include "grammar.hpp"

static std::vector<std::set<parlex::detail::match>> matches_by_height(parlex::detail::abstract_syntax_semilattice const & asg) {
	std::map<parlex::detail::match, std::set<parlex::detail::match>> reversedDependencies;
	std::set<parlex::detail::match> pending;
	std::map<parlex::detail::match, size_t> reversedResults;
	for (auto const & entry : asg.derivations_of_matches) {
		pending.insert(entry.first);
		reversedResults[entry.first] = 0;
		for (auto const & p : entry.second) {
			for (auto const & m : p) {
				reversedDependencies[m].insert(entry.first);
			}
		}
	}
	while (!pending.empty()) {
		auto const m = *pending.begin();
		pending.erase(m);
		auto const h = reversedResults[m] + 1;
		for (auto const & dep : reversedDependencies[m]) {
			if (h > reversedResults[dep]) {
				reversedResults[dep] = h;
				pending.insert(dep);
			}
		}
	}
	std::vector<std::set<parlex::detail::match>> result;
	for (auto const & e : reversedResults) {
		auto const m = e.first;
		auto const height = e.second;
		if (result.size() <= height) {
			result.resize(height + 1);
		}
		result[height].insert(m);
	}
	return result;
}

namespace plc {

source_code::source_code(std::string const & pathname, std::u32string const & document) :
	pathname(pathname),
	document(document),
	line_number_by_first_character(construct_line_number_by_first_character(document)),
    ast(construct_ast(document, STATEMENT_SCOPE::acceptor(), pathname)),
	representation(STATEMENT_SCOPE::build(ast)) {
}

source_code::source_code(std::string const & pathname) : source_code(pathname, read_utf_file(pathname)) {
}

STATEMENT_SCOPE source_code::get_representation() const {
	return representation;
}

std::pair<uint32_t, uint32_t> source_code::get_line_number_and_column(std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, uint32_t const charIndex)
{
	auto i = lineNumberByFirstCharacter.lower_bound(charIndex);
	if (i != lineNumberByFirstCharacter.cend() && i->first == charIndex) {
		return std::make_pair(i->second, 0);
	}
	throw_assert(i != lineNumberByFirstCharacter.cbegin());
	--i;
	return std::make_pair(i->second, charIndex - i->first);

}

std::pair<uint32_t, uint32_t> source_code::get_line_number_and_column(uint32_t const charIndex) const {
	return get_line_number_and_column(line_number_by_first_character, charIndex);
}


std::string source_code::describe_code_span(int32_t firstCharacter, int32_t lastCharacter) const {
	return describe_code_span(firstCharacter, lastCharacter, line_number_by_first_character, pathname);
}

std::u32string source_code::get_xml_doc_string(XML_DOC_STRING const & v) const {
	struct visitor {
		XML_DOC_STRING_INTERIOR const * operator()(XML_DOC_STRING_INTERIOR_t const & v) const {
			return &*v.interior;
		}

		XML_DOC_STRING_INTERIOR const *  operator()(val<PAYLOAD>) const {
			return nullptr;
		}
	};
	auto current = &*v.interior;
	auto previous = current;
	while ((current = std::visit(visitor(), *(XML_DOC_STRING_INTERIOR_base *)current))) {
		previous = current;
	}
	auto const & payload = *std::get<val<PAYLOAD>>(*(XML_DOC_STRING_INTERIOR_base *)previous);
	return get_substring(payload);
}

std::map<uint32_t, uint32_t> source_code::construct_line_number_by_first_character(std::u32string const & document) {
	//compute line number lookup table
	std::map<uint32_t, uint32_t> result;
	intmax_t pos = 0;
	uint32_t line = 0;
	while (pos != std::u32string::npos) {
		result[uint32_t(pos++)] = uint32_t(line++);
		pos = document.find(U'\n', pos);
	}
	return result;
}

std::string source_code::describe_code_span(int32_t firstCharacter, int32_t lastCharacter, std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter) {
	std::string result;
	auto const start = get_line_number_and_column(lineNumberByFirstCharacter, firstCharacter);
	auto const end = get_line_number_and_column(lineNumberByFirstCharacter, lastCharacter);
	result += std::to_string(start.first + 1) + ":" + std::to_string(start.second) + "-";
	if (end.first == start.first) {
		result += std::to_string(end.second);
	} else {
		result += std::to_string(end.first + 1) + ":" + std::to_string(end.second);
	}
	return result;
}

std::string source_code::describe_code_span(int32_t firstCharacter, int32_t lastCharacter, std::map<uint32_t, uint32_t> const & lineNumberByFirstCharacter, std::string const & pathname)
{
	auto result = pathname.empty() ? "[generated]" : pathname;
	result += ":";
	auto const start = get_line_number_and_column(lineNumberByFirstCharacter, firstCharacter);
	auto const end = get_line_number_and_column(lineNumberByFirstCharacter, lastCharacter);
	result += std::to_string(start.first + 1) + ":" + std::to_string(start.second) + "-";
	if (end.first == start.first) {
		result += std::to_string(end.second);
	} else {
		result += std::to_string(end.first + 1) + ":" + std::to_string(end.second);
	}
	return result;
}

parlex::detail::abstract_syntax_tree source_code::construct_ast(std::u32string const & document, parlex::detail::recognizer const & recognizer, std::string const & pathname) {
	auto const lineNumberByFirstCharacter(construct_line_number_by_first_character(document));
	static parlex::detail::parser p;
	auto assl = p.parse(plange_grammar::get(), recognizer, document);
	// Was parsing successful?
	if (!assl.is_rooted()) {
		parlex::detail::match const * lastValidStatement =  nullptr;
		for (auto const & tableEntry : assl.derivations_of_matches) {
			auto const & m = tableEntry.first;
			if (plange_grammar::get().get_recognizer(m.recognizer_index).name == "STATEMENT") {
				if (lastValidStatement == nullptr || m.document_position + m.consumed_character_count > lastValidStatement->document_position + lastValidStatement->consumed_character_count) {
					lastValidStatement = &m;
				}
			}
		}
		if (lastValidStatement == nullptr) {
			ERROR(CouldNotParse, pathname);
		} else {
			auto const firstCharacter = lastValidStatement->document_position;
			auto const lastCharacter = lastValidStatement->document_position + lastValidStatement->consumed_character_count - 1;
			auto const description = pathname + " last valid statement: " + describe_code_span(firstCharacter, lastCharacter, lineNumberByFirstCharacter, pathname);
			ERROR(CouldNotParse, description);
		}
	}


	// Was parsing ambiguous?
	if (assl.variation_count() > 1) {
		auto matchesByHeight = matches_by_height(assl);
		for (const auto & matches : matchesByHeight) {
			for (auto const & m : matches) {
				auto const & derivations = assl.derivations_of_matches.find(m)->second;
				if (derivations.size() > 1) {
					auto const posStart = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position);
					auto const posEnd = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position + m.consumed_character_count - 1);
					std::string message;
					if (posStart.first == posEnd.first) {
						message = pathname + ":" + plange_grammar::get().get_recognizer(m.recognizer_index).name + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.second + 1);
					}
					else {
						message = pathname + ":" + plange_grammar::get().get_recognizer(m.recognizer_index).name + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.first + 1) + ":" + std::to_string(posEnd.second + 1);
					}
					for (auto const & derivation : derivations) {
						message += "\n";
						message += "derivation: \n";
						for (auto const & childMatch : derivation) {
							message += "\t" + plange_grammar::get().get_recognizer(childMatch.recognizer_index).name + " (" + describe_code_span(childMatch.document_position, childMatch.document_position + childMatch.consumed_character_count - 1, lineNumberByFirstCharacter) + ")\n";
						}
						message = message.substr(0, message.length() - 1);
					}
					message += "\n";
					/*message += assl.to_dot();*/
					ERROR(AmbiguousParse, message);
				}
			}
		}
	}

	// Convert assl to ast
	return assl.tree();
}

std::u32string const & source_code::get_document() const {
	return document;
}

}
