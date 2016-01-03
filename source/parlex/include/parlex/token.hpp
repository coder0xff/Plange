#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "parlex/details/producer.hpp"

namespace parlex {

class terminal;

namespace details {

class token : public producer {
public:
	token(job & owner, terminal const & t, size_t documentPosition);
};

}
}

#endif //TOKEN_HPP
