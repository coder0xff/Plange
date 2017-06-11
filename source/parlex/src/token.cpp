#include "parlex/token.hpp"

#include "parlex/terminal.hpp"

#include "parlex/details/job.hpp"

namespace parlex {
namespace details {

token::token(job & owner, terminal const & t, size_t documentPosition) : producer(owner, t, documentPosition) {
	if (t.test(owner.document, documentPosition)) {
		//DBG("found a '", t.id, "' at ", documentPosition);
		enque_permutation(t.length, std::vector<match>());
	} else {
		//DBG("no '", t.id, "' at ", documentPosition);
	}
	terminate();
}

} // namespace details
} // namespace parlex
