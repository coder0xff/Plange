#include "parlex/recognizer.hpp"
#include "utils.hpp"
#include "parlex/details/partial_abstract_syntax_graph.hpp"

namespace parlex {
namespace details {

partial_abstract_syntax_graph::partial_abstract_syntax_graph(std::set<match> const & matches) : matches(matches) { }

}
}
