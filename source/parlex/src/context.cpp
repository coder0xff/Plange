#include "parlex/detail/context.hpp"

#include <csignal>
#include <iostream>

#include "parlex/detail/subjob.hpp"

#include "logging.hpp"
#include "utils.hpp"

std::atomic<int> refIDCounter(0);
std::atomic<int> contextIDCounter(0);

namespace parlex {
namespace detail {

context::context(subjob & owner, context const* const prior, int documentPosition, std::optional<match> const & fromTransition, behavior::leaf const * leaf) :
	id(++contextIDCounter), owner(owner), prior(prior),
	currentDocumentPosition(documentPosition),
	fromTransition(fromTransition),
	leaf(leaf) {
	throw_assert((prior != nullptr) == fromTransition.has_value());
	//DBG("constructed context ", id);
}

context::~context() {
	//DBG("destructed context ", id);
}

permutation context::result() const {
	permutation result;
	context const* current = this;
	while (current->prior) {
		result.emplace_back(match(*current->fromTransition), current->leaf);
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return permutation(result.rbegin(), result.rend());
}

}
}
