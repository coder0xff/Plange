#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "parlex/state_machine.hpp"

namespace parlex {

typedef std::map<state_machine_base const *, std::set<state_machine_base const *>> precedence_collection;

}

#endif
