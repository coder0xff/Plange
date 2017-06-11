#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "parlex/state_machine_base2.hpp"

namespace parlex {

typedef std::map<state_machine_base2 const *, std::set<state_machine_base2 const *>> precedence_collection;

} // namespace parlex

#endif //PRECEDENCE_COLLECTION_HPP
