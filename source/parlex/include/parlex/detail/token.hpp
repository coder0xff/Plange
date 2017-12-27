#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class terminal;

class token : public producer {
public:
	token(job & owner, size_t const documentPosition, size_t const recognizerIndex, terminal const & t);
};

} // namespace detail
} // namespace parlex

#endif //TOKEN_HPP
