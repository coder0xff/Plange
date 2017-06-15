#ifndef POST_PROCESSOR_HPP
#define POST_PROCESSOR_HPP

#include <functional>

namespace parlex {

struct abstract_syntax_graph;
typedef std::function<void(abstract_syntax_graph &)> post_processor;

} // namespace parlex

#endif //POST_PROCESSOR_HPP
