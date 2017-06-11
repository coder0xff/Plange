#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "state_machine_base2.hpp"

namespace parlex {

typedef std::map<state_machine_base2 const *, std::set<state_machine_base2 const *>> precedence_collection;

}

#endif
