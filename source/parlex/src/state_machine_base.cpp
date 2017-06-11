#include "parlex/state_machine_base2.hpp"

#include "parlex/behavior2.hpp"

#include "parlex/details/subjob.hpp"

namespace parlex {

state_machine_base2::state_machine_base2(std::string const & id) : recognizer(id) {
}

void state_machine_base2::start(details::subjob & sj, size_t documentPosition) const {
	process(sj.construct_start_state_context(documentPosition), get_start_state());
}

void state_machine_base2::on(details::context_ref const & c, recognizer const & r, int nextDfaState, behavior2::leaf const * leaf) {
	c.owner().on(c, r, nextDfaState, leaf);
}

void state_machine_base2::accept(details::context_ref const & c) {
	c.owner().accept(c);
}

} // namespace parlex
