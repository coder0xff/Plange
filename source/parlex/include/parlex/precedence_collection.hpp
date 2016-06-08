#ifndef PRECEDENCE_COLLECTION_HPP
#define PRECEDENCE_COLLECTION_HPP

#include <map>

#include "parlex/state_machine.hpp"

namespace parlex {

typedef std::map<state_machine const *, std::set<state_machine const *>> precedence_collection;

}

#endif
