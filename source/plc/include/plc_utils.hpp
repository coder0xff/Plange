#ifndef INCLUDED_PLC_PLC_UTILS_HPP
#define INCLUDED_PLC_PLC_UTILS_HPP

#include <string>

namespace plc {

// This function emits errors via the logger
std::u32string read_utf_file(std::string const & pathname);

}

#endif // INCLUDED_PLC_PLC_UTILS_HPP