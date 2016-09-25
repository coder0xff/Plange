#ifndef POST_PROCESSOR_HPP
#define POST_PROCESSOR_HPP

#include <functional>

#include "abstract_syntax_graph.hpp"

namespace parlex {
	typedef std::function<void(abstract_syntax_graph &)> post_processor;
}

#endif
