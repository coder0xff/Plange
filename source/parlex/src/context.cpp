#include <cassert>
#include <csignal>
#include <iostream>

#include "parlex/details/context.hpp"
#include "parlex/details/subjob.hpp"
#include "logging.hpp"

std::atomic<int> refIDCounter(0);
std::atomic<int> contextIDCounter(0);

namespace parlex {
namespace details {

struct context_ref_counter {
	std::atomic<context *> c;
	std::atomic<int> counter;
	int const id;

	context_ref_counter(context * c) : c(c), counter(1), id(c->id) {
        //DBG("Constructed rc:", id);
	}

	void inc() { ++counter; }
	void dec() {
		if (--counter == 0) {
			delete this;
		}
	}
};

context::context(subjob & owner, context_ref const & prior, int documentPosition, match const * fromTransition) :
 id (++contextIDCounter), owner(owner), prior(prior),
 currentDocumentPosition(documentPosition),
 fromTransition(fromTransition != nullptr ? new match(*fromTransition) : nullptr), rc(*new context_ref_counter(this))
{
	assert(&owner);
	assert(!prior.is_null() == (fromTransition != nullptr));
	//DBG("constructed context ", id);
}

context::~context() {
	context* self = rc.c.exchange(nullptr);
	assert(self);
	rc.dec();
	//DBG("descructed context ", id);
}

context_ref context::get_ref() const {
	return context_ref(rc);
}

std::vector<match> context::result() const {
	std::vector<match> result;
	context_ref start = get_ref();
	context_ref const * current = &start;
	while (!current->prior().is_null()) {
		result.push_back(*current->from_transition());
		current = &current->prior();
	}
	return std::vector<match>(result.rbegin(), result.rend());
}

context_ref::context_ref() : rc(nullptr), id(++refIDCounter) { }

context_ref::context_ref(context_ref_counter &rc_) : rc(&rc_), id(++refIDCounter) {
	rc_.inc();
    //DBG("Constructed ref:", id, " to c:", rc_.id);
}

context_ref::context_ref(context_ref const & other) : rc(other.rc), id(++refIDCounter) {
	if (rc) {
		rc->inc();
        //DBG("Constructed ref:", id, " to c:", rc->id);
    }
}

context_ref::context_ref(context_ref&& other) : rc(other.rc), id(++refIDCounter) {
	if (rc) {
		rc->inc();
        //DBG("Constructed ref:", id, " to c:", rc->id);
    }
}

context_ref::~context_ref() {
	if (rc) {
        //DBG("Destructing ref:", id, " to c:", rc->id);
		rc->dec();
    }
}

bool context_ref::is_null() const {
	if (!rc) {
		return true;
	} else {
		if (!static_cast<context *>(rc->c)) {
			std::cerr << "ERROR: dangling ref id: " << id << ", context id: " << rc->id;
			raise(SIGABRT);
		}
		return false;
	}
}

subjob & context_ref::owner() const {
	assert(rc);
    //DBG("Dereferencing ref:", id, " to c:",rc->id);
	context* temp = rc->c;
	assert(temp);
	return temp->owner;
}

context_ref const & context_ref::prior() const {
	assert(rc);
    //DBG("Dereferencing ref:", id, " to c:",rc->id);
	context* temp = rc->c;
	assert(temp);
	return temp->prior;
}

int context_ref::current_document_position() const {
	assert(rc);
    //DBG("Dereferencing ref:", id, " to c:",rc->id);
	context* temp = rc->c;
	assert(temp);
	return temp->currentDocumentPosition;
}

std::unique_ptr<match> context_ref::from_transition() const {
	assert(rc);
    //DBG("Dereferencing ref:", id, " to c:",rc->id);
	context* temp = rc->c;
	assert(temp);
	if (temp->fromTransition) {
		return std::unique_ptr<match>(new match(*temp->fromTransition));
	}
	return std::unique_ptr<match>();
}

std::vector<match> context_ref::result() const {
	assert(rc);
	context* temp = rc->c;
	assert(temp);
	return temp->result();
}

}}
