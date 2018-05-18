#include "parlex/detail/configuration.hpp"

#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

configuration::configuration(uint8_t const dfa_state, uint32_t documentPosition, transition_record const * history) :
	dfa_state(dfa_state),
	current_document_position(documentPosition),
	history(history)
{
}

configuration::~configuration() {
	//DBG("destructed configuration ", name);
}

derivation configuration::result() const {
	derivation result;
	auto current = history;
	while (current) {
		result.emplace_back(match(current->data), current->data.l);
		current = current->prior;
	}
	// std::reverse would require a swap function to be defined for match
	return derivation(result.rbegin(), result.rend());
}

}
}
