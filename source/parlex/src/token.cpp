#include "job.hpp"
#include "logging.hpp"
#include "terminal.hpp"
#include "token.hpp"

namespace parlex {
namespace details {

token::token(job & owner, terminal const & t, size_t documentPosition) : producer(owner, t, documentPosition) { 
	if (t.test(owner.document, documentPosition)) {
		DBG("found a '", t.get_id(), "' at ", documentPosition);
		enque_permutation(t.get_length(), std::vector<match>());		
	} else {
		DBG("no '", t.get_id(), "' at ", documentPosition);
	}

}

}
}