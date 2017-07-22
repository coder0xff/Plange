#ifndef POST_PROCESSOR_HPP
#define POST_PROCESSOR_HPP

#include <functional>

namespace parlex {
namespace details {

struct abstract_syntax_graph;

} // namespace details

typedef std::function<void(details::abstract_syntax_graph &)> post_processor;

} // namespace parlex

#endif //POST_PROCESSOR_HPP
