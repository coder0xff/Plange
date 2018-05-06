#include "parlex/detail/token.hpp"

#include "parlex/detail/job.hpp"
#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

token::token(job & j, match_class const & matchClass, terminal const & t) {
	if (t.test(j.document, matchClass.document_position)) {
		//DBG("found a '", t.name, "' at ", documentPosition);
		enque_derivation(j, matchClass, t.length, derivation());
	} else {
		//DBG("no '", t.name, "' at ", documentPosition);
	}
	terminate(j, matchClass);
}

} // namespace detail
} // namespace parlex
