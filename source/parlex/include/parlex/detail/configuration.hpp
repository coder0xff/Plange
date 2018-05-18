#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <vector>

#include "parlex/builder.hpp"
#include "parlex/detail/derivation.hpp"

namespace parlex {
namespace detail {

class subjob;
struct transition_record;

//the parse configuration for some acceptor's state during one of its executions
struct configuration {
	uint8_t const dfa_state;
	uint32_t const current_document_position;
	transition_record const * const history;

	configuration(uint8_t dfa_state, uint32_t documentPosition, transition_record const * history);
	~configuration();

	derivation result() const;
};

}
}

#endif
