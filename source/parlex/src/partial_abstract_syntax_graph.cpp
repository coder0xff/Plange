#include "parlex/details/partial_abstract_syntax_graph.hpp"

#include "utils.hpp"

#include "parlex/recognizer.hpp"

namespace parlex {
namespace details {

partial_abstract_syntax_graph::partial_abstract_syntax_graph(std::set<match> const & matches) : matches(matches) { }

}
}
