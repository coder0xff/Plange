#include "parlex/detail/state_machine_base.hpp"

#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

state_machine_base::state_machine_base(std::string const & name) : recognizer(name) {
}

void state_machine_base::start(context const & c) const {
	process(c, get_start_state());
}

void state_machine_base::on(context const & c, size_t const recognizerIndex, size_t const nextDfaState, leaf const * leaf) {
	c.owner.on(c, recognizerIndex, nextDfaState, leaf);
}

void state_machine_base::accept(context const & c) {
	c.owner.accept(c);
}

} // namespace detail
} // namespace parlex
