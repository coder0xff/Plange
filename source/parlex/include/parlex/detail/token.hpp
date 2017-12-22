#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class terminal;

class token : public producer {
public:
	token(job & owner, terminal const & t, size_t documentPosition);
};

} // namespace detail
} // namespace parlex

#endif //TOKEN_HPP
