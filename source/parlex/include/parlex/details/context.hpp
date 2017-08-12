#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <optional>
#include <vector>

#include "parlex/details/fast_match.hpp"
#include "parlex/details/permutation.hpp"

namespace parlex {
namespace details {
namespace behavior {

class leaf;

} // namespace behavior

class subjob;

//the parse context for some state_machine's state during one of its executions
class context {
public:
	int const id;
	subjob & owner;
	context const* const prior;
	size_t const currentDocumentPosition;
	std::optional<fast_match> const fromTransition;

	context(subjob & owner, context const* const prior, int documentPosition, std::optional<fast_match> const & from_transition);
	context(context const & other) = delete;
	context(context && move) = delete;
	~context();

	std::vector<match> result() const;
};

}
}

#endif
