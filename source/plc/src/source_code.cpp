#include "stdafx.hpp"
#include "source_code.hpp"

#include <fstream>

#pragma warning(push, 0)
#include <llvm/IR/Constants.h>
#pragma warning(pop)

#include "utf.hpp"
#include "utils.hpp"

#include "parlex/details/abstract_syntax_semilattice.hpp"
#include "parlex/details/recognizer.hpp"

#include "compiler.hpp"
#include "scope.hpp"
#include "parlex/details/document.hpp"

//filter super delimiters
//Any PAYLOAD that fully contains another PAYLOAD is not a PAYLOAD
static void payload_postprocess(parlex::details::abstract_syntax_semilattice & asg) {
	std::set<parlex::details::match> payloadMatches;
	for (auto const & entry : asg.permutations_of_matches) {
		if (entry.first.r.id == "PAYLOAD") {
			payloadMatches.insert(entry.first);
		}
	}
	std::set<parlex::details::match> payloadsToCut;
	for (auto const & i : payloadMatches) {
		for (auto const & j : payloadMatches) {
			if (i < j || j < i) {
				int iSpanLeft = i.document_position;
				int iSpanRight = i.document_position + i.consumed_character_count - 1;
				int jSpanLeft = j.document_position;
				int jSpanRight = j.document_position + j.consumed_character_count - 1;
				if (iSpanLeft < jSpanLeft && iSpanRight >= jSpanLeft) {
					payloadsToCut.insert(i);
				} else if (iSpanLeft == jSpanLeft && iSpanRight > jSpanRight) {
					payloadsToCut.insert(i);
				}
			}
		}
	}
	asg.cut(payloadsToCut);
}

static std::vector<std::set<parlex::details::match>> matches_by_height(parlex::details::abstract_syntax_semilattice const & asg) {
	std::map<parlex::details::match, std::set<parlex::details::match>> reversedDependencies;
	std::set<parlex::details::match> pending;
	std::map<parlex::details::match, size_t> reversedResults;
	for (auto const & entry : asg.permutations_of_matches) {
		pending.insert(entry.first);
		reversedResults[entry.first] = 0;
		for (auto const & p : entry.second) {
			for (auto const & m : p) {
				reversedDependencies[m].insert(entry.first);
			}
		}
	}
	while (!pending.empty()) {
		parlex::details::match m = *pending.begin();
		pending.erase(m);
		size_t h = reversedResults[m] + 1;
		for (auto const & dep : reversedDependencies[m]) {
			if (h > reversedResults[dep]) {
				reversedResults[dep] = h;
				pending.insert(dep);
			}
		}
	}
	std::vector<std::set<parlex::details::match>> result;
	for (auto const & e : reversedResults) {
		parlex::details::match m = e.first;
		size_t height = e.second;
		if (result.size() <= height) {
			result.resize(height + 1);
		}
		result[height].insert(m);
	}
	return result;
}

plc::source_code::source_code(std::string const & pathname, std::u32string const & document) :
	pathname(pathname),
	document(document),
	line_number_by_first_character(construct_line_number_by_first_character(document)),
    ast(construct_ast(document, plange_grammar::get().STATEMENT_SCOPE.get_recognizer(), pathname)),
	representation(STATEMENT_SCOPE::build(ast)) {
}

static std::u32string read(std::string const & pathname) {
	std::ifstream ifs(pathname, std::ios::binary);
	if (!ifs) {
		ERROR(CouldNotOpenFile, pathname);
	}
	return read_with_bom(move(ifs));
}

plc::source_code::source_code(std::string const & pathname) : source_code(pathname, read(pathname)) {
}

plc::source_code::~source_code() {
}

std::pair<int, int> plc::source_code::get_line_number_and_column(std::map<int, int> const & lineNumberByFirstCharacter, int charIndex)
{
	std::map<int, int>::const_iterator i = lineNumberByFirstCharacter.lower_bound(charIndex);
	if (i != lineNumberByFirstCharacter.cend() && i->first == charIndex) {
		return std::make_pair(i->second, 0);
	}
	throw_assert(i != lineNumberByFirstCharacter.cbegin());
	--i;
	return std::make_pair(i->second, charIndex - i->first);

}

std::pair<int, int> plc::source_code::get_line_number_and_column(int charIndex) const {
	return get_line_number_and_column(line_number_by_first_character, charIndex);
}


std::string plc::source_code::describe_code_span(parlex::details::match const & m) const {
	return describe_code_span(m, line_number_by_first_character, pathname);
}

std::map<int, int> plc::source_code::construct_line_number_by_first_character(std::u32string const & document) {
	//compute line number lookup table
	std::map<int, int> result;
	size_t pos = 0;
	int line = 0;
	while (pos != std::u32string::npos) {
		result[pos++] = line++;
		pos = document.find(U'\n', pos);
	}
	return result;
}

std::string plc::source_code::describe_code_span(parlex::details::match const & m, std::map<int, int> const & lineNumberByFirstCharacter, std::string const & pathname)
{
	std::string result = pathname == "" ? "[generated]" : pathname;
	result += ":";
	std::pair<int, int>
		start = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position),
		end = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position + m.consumed_character_count - 1);
	result += std::to_string(start.first + 1) + ":" + std::to_string(start.second) + "-";
	if (end.first == start.first) {
		result += std::to_string(end.second);
	} else {
		result += std::to_string(end.first + 1) + ":" + std::to_string(end.second);
	}
	return result;

}

parlex::details::abstract_syntax_tree plc::source_code::construct_ast(std::u32string const & document, parlex::details::recognizer const & production, std::string const & pathname) {
	std::map<int, int> const lineNumberByFirstCharacter(construct_line_number_by_first_character(document));
	static parlex::details::parser p;
	parlex::details::abstract_syntax_semilattice assl = p.parse(plange_grammar::get(), production, document);
	// Was parsing successful?
	if (!assl.is_rooted()) {
		parlex::details::match const * lastValidStatement =  nullptr;
		parlex::details::state_machine_base const & STATEMENTStateMachine = plange_grammar::get().get_state_machine("STATEMENT");
		for (auto const & tableEntry : assl.permutations_of_matches) {
			parlex::details::match const & m = tableEntry.first;
			if (&m.r == &STATEMENTStateMachine) {
				if (lastValidStatement == nullptr || m.document_position + m.consumed_character_count > lastValidStatement->document_position + lastValidStatement->consumed_character_count) {
					lastValidStatement = &m;
				}
			}
		}
		if (lastValidStatement == nullptr) {
			ERROR(CouldNotParse, pathname + " syntax semilattice: " + assl.to_dot());
		} else {
			auto description = pathname + " last valid statement: " + describe_code_span(*lastValidStatement, lineNumberByFirstCharacter, pathname);
			ERROR(CouldNotParse, description);
		}
	}


	// Was parsing ambiguous?
	if (assl.variation_count() > 1) {
		std::vector<std::set<parlex::details::match>> matchesByHeight = matches_by_height(assl);
		for (size_t height = 0; height < matchesByHeight.size(); ++height) {
			auto const & matches = matchesByHeight[height];
			for (auto const & m : matches) {
				auto const & permutations = assl.permutations_of_matches.find(m)->second;
				if (permutations.size() > 1) {
					auto posStart = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position);
					auto posEnd = get_line_number_and_column(lineNumberByFirstCharacter, m.document_position + m.consumed_character_count - 1);
					std::string message;
					if (posStart.first == posEnd.first) {
						message = pathname + ":" + m.r.id + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.second + 1);
					}
					else {
						message = pathname + ":" + m.r.id + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.first + 1) + ":" + std::to_string(posEnd.second + 1);
					}
					for (auto const & permutation : permutations) {
						message += "\n";
						message += "permutation: ";
						for (auto const & childMatch : permutation) {
							message += childMatch.r.id + " ";
						}
						message = message.substr(0, message.length() - 1);
					}
					message += "\n";
					message += assl.to_dot();
					ERROR(AmbiguousParse, message);
				}
			}
		}
	}

	// Convert assl to ast
	return assl.tree();
}


