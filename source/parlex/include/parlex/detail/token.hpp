#ifndef INCLUDED_PARLEX_TOKEN_HPP
#define INCLUDED_PARLEX_TOKEN_HPP

#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class terminal;

class token : public producer {
public:
	token(job & j, match_class const & matchClass, terminal const & t);
};

} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_TOKEN_HPP
