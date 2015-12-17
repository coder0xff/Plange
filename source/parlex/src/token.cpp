#include <iostream>

#include "token.hpp"
#include "terminal.hpp"
#include "job.hpp"

namespace parlex {
namespace details {

token::token(job & owner, terminal const & t, int documentPosition) : producer(owner, t, documentPosition) { 
	if (t.test(owner.document, documentPosition)) {
		std::cout << "found a " << t.get_id() << " at " << documentPosition << std::endl;
		enque_permutation(t.get_length(), std::vector<match>());		
	} else {
		std::cout << "no " << t.get_id() << " at " << documentPosition << std::endl;
	}

}

}
}