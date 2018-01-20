#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <optional>
#include <vector>

#include "parlex/builder.hpp"
#include "parlex/detail/permutation.hpp"

namespace parlex {
namespace detail {

class subjob;

//the parse context for some state_machine's state during one of its executions
class context {
public:
	context const* const prior;
	uint32_t const current_document_position;
	std::optional<match> const from_transition;
	leaf const * const l;

	context(context const * const prior, uint32_t documentPosition, std::optional<match> const & fromTransition, leaf const * l);
	context(context const & other) = delete;
	context(context && move) = delete;
	~context();

	permutation result() const;
};

}
}

#endif
