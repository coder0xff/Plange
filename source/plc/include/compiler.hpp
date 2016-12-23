#ifndef PLC_UTILS_HPP
#define PLC_UTILS_HPP

#include <vector>

#include "parlex/match.hpp"

#include "abstract_value.hpp"
#include "source_code.hpp"

namespace plc {

void compile(std::vector<std::reference_wrapper<source_code const>> sources);

}

#endif //PLC_UTILS_HPP
