#include "parlex/detail/state_machine_base.hpp"

#include "parlex/detail/subjob.hpp"
#include "parlex/detail/job.hpp"

namespace parlex {
namespace detail {

state_machine_base::state_machine_base(std::string const & name) : recognizer(name) {
}

void state_machine_base::start(job & j, uint32_t const subjobId, subjob & sj, context const & c) const {
	process(j, subjobId, sj, c, get_start_state());
}

void state_machine_base::on(job & j, uint16_t const recognizerIndex, uint32_t const subscriber, subjob & sj, context const & c, uint8_t const nextDfaState, leaf const * leaf) {
	sj.on(j, recognizerIndex, c, subscriber, nextDfaState, leaf);
}

void state_machine_base::accept(job & j, subjob & sj, uint32_t const subjobId, context const & c) {
	sj.accept(j, j.get_match_class(subjobId), c);
}

} // namespace detail
} // namespace parlex
