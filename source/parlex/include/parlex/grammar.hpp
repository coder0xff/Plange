#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <string>

#include "state_machine.hpp"

namespace parlex {

typedef std::map<std::string, state_machine> grammar;

}

#endif