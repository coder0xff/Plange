#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "parlex/details/producer.hpp"

namespace parlex {
namespace details {

class terminal;

class token : public producer {
public:
	token(job & owner, terminal const & t, size_t documentPosition);
};

} // namespace details
} // namespace parlex

#endif //TOKEN_HPP
