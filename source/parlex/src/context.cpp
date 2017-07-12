#include "parlex/details/context.hpp"

#include <csignal>
#include <iostream>

#include "parlex/details/subjob.hpp"

#include "logging.hpp"
#include "utils.hpp"

std::atomic<int> refIDCounter(0);
std::atomic<int> contextIDCounter(0);

namespace parlex {
namespace details {

context::context(subjob & owner, context* const & prior, int documentPosition, std::optional<fast_match> const & fromTransition) :
	id(++contextIDCounter), owner(owner), prior(prior),
	currentDocumentPosition(documentPosition),
	fromTransition(fromTransition) {
	throw_assert((prior != nullptr) == fromTransition.has_value());
	//DBG("constructed context ", id);
}

context::~context() {
	//DBG("destructed context ", id);
}

std::vector<match> context::result() const {
	std::vector<match> result;
	context const* current = this;
	while (!current->prior) {
		result.push_back(match(*current->fromTransition));
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return std::vector<match>(result.rbegin(), result.rend());
}

}
}
