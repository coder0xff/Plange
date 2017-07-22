#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "parlex/details/state_machine_base.hpp"

namespace parlex {
namespace details {

typedef std::map<state_machine_base const *, std::set<state_machine_base const *>> precedence_collection;

}
} // namespace parlex

#endif //PRECEDENCE_COLLECTION_HPP
