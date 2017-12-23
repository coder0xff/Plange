#include "parlex/detail/token.hpp"

#include "parlex/detail/job.hpp"
#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

token::token(job & owner, terminal const & t, size_t const documentPosition) : producer(owner, t, documentPosition) {
	if (t.test(owner.document, documentPosition)) {
		//DBG("found a '", t.id, "' at ", documentPosition);
		enque_permutation(t.length, permutation());
	} else {
		//DBG("no '", t.id, "' at ", documentPosition);
	}
	terminate();
}

} // namespace detail
} // namespace parlex
