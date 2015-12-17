#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "producer.hpp"

namespace parlex {

class terminal;

namespace details {

class token : public producer {
public:
	token(job & owner, terminal const & t, int documentPosition);
};

}
}

#endif //TOKEN_HPP