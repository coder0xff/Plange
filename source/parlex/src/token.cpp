#include "parlex/detail/token.hpp"

#include "parlex/detail/job.hpp"
#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

token::token(job & owner, size_t const documentPosition, size_t const recognizerIndex, terminal const & t) : producer(owner, documentPosition, recognizerIndex, 0) {
	if (t.test(owner.document, documentPosition)) {
		//DBG("found a '", t.name, "' at ", documentPosition);
		enque_permutation(t.length, permutation());
	} else {
		//DBG("no '", t.name, "' at ", documentPosition);
	}
	terminate();
}

} // namespace detail
} // namespace parlex
