#include "parlex/state_machine_base.hpp"

#include "parlex/behavior.hpp"

#include "parlex/details/subjob.hpp"

namespace parlex {

state_machine_base::state_machine_base(std::string const & id) : recognizer(id) {
}

void state_machine_base::start(details::subjob & sj, size_t documentPosition) const {
	process(sj.construct_start_state_context(documentPosition), get_start_state());
}

void state_machine_base::on(details::context_ref const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf) {
	c.owner().on(c, r, nextDfaState, leaf);
}

void state_machine_base::accept(details::context_ref const & c) {
	c.owner().accept(c);
}

} // namespace parlex
