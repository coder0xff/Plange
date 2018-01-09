#include "parlex/detail/context.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

context::context(context const* const prior, int const documentPosition, std::optional<match> const & fromTransition, leaf const * l) :
	prior(prior),
	current_document_position(documentPosition),
	from_transition(fromTransition),
	l(l) {
	throw_assert((prior != nullptr) == fromTransition.has_value());
	//DBG("constructed context ", target);
}

context::~context() {
	//DBG("destructed context ", name);
}

permutation context::result() const {
	permutation result;
	auto current = this;
	while (current->prior) {
		result.emplace_back(match(*current->from_transition), current->l);
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return permutation(result.rbegin(), result.rend());
}

}
}
