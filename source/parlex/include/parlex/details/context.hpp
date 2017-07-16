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
struct context_ref_counter;

//context_ref is a development and debugging structure
//that implements a checked pointer and should
//be *manually* reduced to a simple pointer at some time.
class context_ref {
	context_ref_counter * rc;
public:
	int const id;
	context_ref();
	context_ref(context_ref_counter & rc);
	context_ref(context_ref const & other);
	context_ref(context_ref && other) noexcept;
	~context_ref();

	bool is_null() const;
	subjob& owner() const;
	context_ref const& prior() const;
	size_t current_document_position() const;
	std::optional<fast_match> from_transition() const; //unique_ptr serves as optional
	std::vector<match> result() const;
};

//the parse context for some state_machine's state during one of its executions
class context {
public:
	int const id;
	subjob & owner;
	context_ref const prior;
	int const currentDocumentPosition;
	std::optional<fast_match> const fromTransition; // optional
private:
	context_ref_counter & rc;

public:
	context(subjob & owner, context_ref const & prior, int documentPosition, std::optional<fast_match> const & from_transition);
	context(context const & other) = delete;
	context(context && move) = delete;
	~context();

	context_ref get_ref() const;
	std::vector<match> result() const;
};

}
}

#endif
