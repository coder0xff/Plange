#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <memory>
#include <vector>
#include <atomic>

#include "parlex/match.hpp"
#include "parlex/match_class.hpp"
#include "parlex/permutation.hpp"

namespace parlex {
namespace details {

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
	context_ref(context_ref&& other);
	~context_ref();

	bool is_null() const;
	subjob & owner() const;
	context_ref prior() const;
	int current_document_position() const;
	std::unique_ptr<match> from_transition() const; //unique_ptr serves as optional
	permutation result() const;
};

//the parse context for some state_machine's state during one of its executions
class context {
public:
	int const id;
	subjob & owner;
	context_ref const prior;
	int const currentDocumentPosition;
	std::unique_ptr<match const> const from_transition;	//unique_ptr serves as optional
private:
	context_ref_counter & rc;

public:
	context(subjob & owner, context_ref const & prior, int documentPosition, match const * from_transition);
	context(context const & other) = delete;
	context(context&& move) = delete;
	~context();

	context_ref get_ref() const;
	std::vector<match> result() const;
};

}
}

#endif
