#ifndef INCLUDED_PARLEX_PRECEDENCE_COLLECTION_HPP
#define INCLUDED_PARLEX_PRECEDENCE_COLLECTION_HPP

#include "coherent_set.hpp"

namespace parlex {
namespace detail {

typedef std::vector<collections::coherent_set<size_t>> precedence_collection;

}
} // namespace parlex

#endif // INCLUDED_PARLEX_PRECEDENCE_COLLECTION_HPP
