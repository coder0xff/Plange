#include "SourceCode.h"

#include <cassert>

#include "parlex/parser.hpp"
#include "plange_grammar.hpp"
#include "Errors.h"
#include "Scope.h"

SourceCode::SourceCode(std::string const& pathname, std::u32string const& document, parlex::parser& parser) : graph(parser.parse(get_plange(), document)) {
	size_t pos = 0;
	int line = 0;
	while (pos != std::u32string::npos) {
		lineNumberByFirstChar[pos++] = line++;
		pos = document.find(U'\n', pos);
	}

	if (!graph.is_rooted()) {
		ERROR(CouldNotParse, pathname);
	}

	for (auto const& matches : graph.matchesByHeight) {
		for (auto const& m : matches) {
			auto const& permutations = graph.permutations.find(m)->second;
			if (permutations.size() > 1) {
				auto posStart = get_line_number_and_column(m.document_position);
				auto posEnd = get_line_number_and_column(m.document_position + m.consumed_character_count - 1);
				std::string message;
				if (posStart.first == posEnd.first) {
					message = pathname + ":" + m.r.get_id() + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.second + 1);
				} else {
					message = pathname + ":" + m.r.get_id() + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.first + 1) + ":" + std::to_string(posEnd.second + 1);
				}
				for (auto const& p : permutations) {
					message += "\n";
					for (auto const& childMatch : p) {
						message += childMatch.r.get_id() + " ";
					}
					message = message.substr(0, message.length() - 1);
				}
				ERROR(AmbiguousParse, message);
			}
		}
	}

	scope.reset(new Scope(*this));

}

SourceCode::~SourceCode() { }

std::pair<int, int> SourceCode::get_line_number_and_column(int charIndex) {
	std::map<int, int>::iterator i = lineNumberByFirstChar.lower_bound(charIndex);
	if (i->first == charIndex) {
		return std::make_pair(i->second, 0);
	} else {
		assert(i != lineNumberByFirstChar.begin());
		--i;
		return std::make_pair(i->second, charIndex - i->first);
	}
}
