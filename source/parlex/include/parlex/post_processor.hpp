#ifndef INCLUDED_PARLEX_POST_PROCESSOR_HPP
#define INCLUDED_PARLEX_POST_PROCESSOR_HPP

#include <functional>

namespace parlex {
namespace detail {

struct abstract_syntax_semilattice;

} // namespace detail

typedef std::function<void(detail::abstract_syntax_semilattice &)> post_processor;

} // namespace parlex

#endif // INCLUDED_PARLEX_POST_PROCESSOR_HPP
