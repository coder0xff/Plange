#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "parlex/detail/state_machine_base.hpp"

namespace parlex {
namespace detail {

typedef std::map<recognizer const *, std::set<recognizer const *>> precedence_collection;

}
} // namespace parlex

#endif //PRECEDENCE_COLLECTION_HPP
