#include "scope.hpp"
#include "plange_grammar.hpp"

plc::scope::scope(source_code& source, scope* const parent, parlex::match const & syntax) : parent(parent), source_code_(source), is_pure(false), is_atomic(false), is_reentrant(false) {
	parlex::abstract_syntax_graph const& asg = source.asg;
	parlex::permutation parts = *asg.permutations.find(syntax)->second.begin();
	for (parlex::match part : parts) {
		if (part.r.id == "STATEMENT") {
			parlex::permutation statementParts = *source.asg.permutations.find(part)->second.begin();
			std::string statementType = statementParts[0].r.id;
			if (statementType == "DEFINITION") {

			}
			if (statementType == "ASSIGNMENT") {

			}
			else if (statementType == "EXPRESSION") {
				
			}
		}

	}
}

plc::scope::~scope() {}
