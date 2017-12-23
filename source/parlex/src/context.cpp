#include "parlex/detail/context.hpp"

#include "parlex/detail/subjob.hpp"

#include "utils.hpp"

std::atomic<int> ref_id_counter(0);
std::atomic<int> context_id_counter(0);

namespace parlex {
namespace detail {

context::context(subjob & owner, context const* const prior, int const documentPosition, std::optional<match> const & fromTransition, behavior::leaf const * leaf) :
	id(++context_id_counter), owner(owner), prior(prior),
	current_document_position(documentPosition),
	from_transition(fromTransition),
	leaf(leaf) {
	throw_assert((prior != nullptr) == fromTransition.has_value());
	//DBG("constructed context ", id);
}

context::~context() {
	//DBG("destructed context ", id);
}

permutation context::result() const {
	permutation result;
	auto current = this;
	while (current->prior) {
		result.emplace_back(match(*current->from_transition), current->leaf);
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return permutation(result.rbegin(), result.rend());
}

}
}
