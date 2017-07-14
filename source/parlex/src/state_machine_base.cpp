#include "parlex/details/state_machine_base.hpp"

#include "parlex/details/behavior.hpp"
#include "parlex/details/subjob.hpp"

namespace parlex {
namespace details {

state_machine_base::state_machine_base(std::string const & id) : recognizer(id) {
}

void state_machine_base::start(subjob & sj, size_t documentPosition) const {
	process(&sj.construct_start_state_context(documentPosition), get_start_state());
}

void state_machine_base::on(context* const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf) {
	(c->owner).on(c, r, nextDfaState, leaf);
}

void state_machine_base::accept(context* const & c) {
	(c->owner).accept(c);
}

} // namespace details
} // namespace parlex
