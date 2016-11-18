#include "source_code.hpp"

#include <cassert>

#include "stdafx.hpp"
#include "parlex/parser.hpp"
#include "plange_grammar.hpp"
#include "utils.hpp"
#include "scope.hpp"

#pragma warning(push, 0)
#include <llvm/IR/Constants.h>
#pragma warning(pop)

//filter super delimiters
//Any PAYLOAD that fully contains another PAYLOAD is not a PAYLOAD
void payload_postprocess(parlex::abstract_syntax_graph & asg) {
	std::set<parlex::match> payloadMatches;
	for (auto const & entry : asg.permutations) {
		if (entry.first.r.id == "PAYLOAD") {
			payloadMatches.insert(entry.first);
		}
	}
	std::set<parlex::match> payloadsToCut;
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

std::vector<std::set<parlex::match>> matches_by_height(parlex::abstract_syntax_graph const & asg) {
	std::map<parlex::match, std::set<parlex::match>> reversedDependencies;
	std::set<parlex::match> pending;
	std::map<parlex::match, size_t> reversedResults;
	for (auto const & entry : asg.permutations) {
		pending.insert(entry.first);
		reversedResults[entry.first] = 0;
		for (auto const & p : entry.second) {
			for (auto const & m : p) {
				reversedDependencies[m].insert(entry.first);
			}
		}
	}
	while (!pending.empty()) {
		parlex::match m = *pending.begin();
		pending.erase(m);
		size_t h = reversedResults[m] + 1;
		for (auto const & dep : reversedDependencies[m]) {
			if (h > reversedResults[dep]) {
				reversedResults[dep] = h;
				pending.insert(dep);
			}
		}
	}
	std::vector<std::set<parlex::match>> result;
	for (auto const & e : reversedResults) {
		parlex::match m = e.first;
		size_t height = e.second;
		if (result.size() <= height) {
			result.resize(height + 1);
		}
		result[height].insert(m);
	}
	return result;
}

plc::source_code::source_code(std::string const& pathname, std::u32string const& document, parlex::parser& parser, llvm::LLVMContext & llvmContext) :
	document(document),
	asg(parser.parse(plange, { payload_postprocess }, document)),
	module(new llvm::Module(pathname, llvmContext))
{
	//compute line number lookup table
	size_t pos = 0;
	int line = 0;
	while (pos != std::u32string::npos) {
		line_number_by_first_character[pos++] = line++;
		pos = document.find(U'\n', pos);
	}

	//std::string test = graph.to_cst_dot(document); //todo: make sure this is commented out
	if (!asg.is_rooted()) {
		ERROR(CouldNotParse, pathname + " syntax tree: " + asg.to_dot());
	}

	std::vector<std::set<parlex::match>> matchesByHeight;


	for (auto const& matches : matches_by_height(asg)) {
		for (auto const& m : matches) {
			auto const& permutations = asg.permutations.find(m)->second;
			if (permutations.size() > 1) {
				auto posStart = get_line_number_and_column(m.document_position);
				auto posEnd = get_line_number_and_column(m.document_position + m.consumed_character_count - 1);
				std::string message;
				if (posStart.first == posEnd.first) {
					message = pathname + ":" + m.r.id + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.second + 1);
				} else {
					message = pathname + ":" + m.r.id + " at " + std::to_string(posStart.first + 1) + ":" + std::to_string(posStart.second + 1) + "-" + std::to_string(posEnd.first + 1) + ":" + std::to_string(posEnd.second + 1);
				}
				for (auto const& p : permutations) {
					message += "\n";
					for (auto const& childMatch : p) {
						message += childMatch.r.id + " ";
					}
					message = message.substr(0, message.length() - 1);
				}
				ERROR(AmbiguousParse, message);
			}
		}
	}
	//std::string dot = asg.to_dot(); //TODO: make sure this is commented out
}

plc::source_code::~source_code() { }

std::pair<int, int> plc::source_code::get_line_number_and_column(int charIndex) {
	std::map<int, int>::iterator i = line_number_by_first_character.lower_bound(charIndex);
	if (i != line_number_by_first_character.end() && i->first == charIndex) {
		return std::make_pair(i->second, 0);
	}
	assert(i != line_number_by_first_character.begin());
	--i;
	return std::make_pair(i->second, charIndex - i->first);
}

llvm::Value * plc::source_code::get_or_add_global_string(llvm::LLVMContext & context, std::u32string const & s)
{
	auto i = global_strings.find(s);
	if (i != global_strings.end()) return i->second;
	llvm::StringRef Str(to_utf8(s));
	llvm::Constant *StrConstant = llvm::ConstantDataArray::getString(context, Str);
	auto gv = new llvm::GlobalVariable(*module, StrConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, StrConstant);
	std::string name = "str" + std::to_string(global_strings.size());
	gv->setName(name);
	//gv->setUnnamedAddr(true)
	return global_strings[s] = gv;
}

void plc::source_code::compile() {
	scope.reset(new plc::scope(*this, nullptr, asg.root));
}