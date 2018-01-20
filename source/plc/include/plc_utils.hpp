#ifndef PLC_UTILS_HPP
#define PLC_UTILS_HPP

#include <string>

namespace plc {

// This function emits errors via the logger
std::u32string read_utf_file(std::string const & pathname);

}

#endif //PLC_UTILS_HPP