#include "plc_utils.hpp"

#include <fstream>

#include "errors.hpp"
#include "utf.hpp"

namespace plc {

std::u32string read_utf_file(std::string const & pathname)
{
	std::ifstream ifs(pathname, std::ios::binary);
	if (!ifs) {
		ERROR(CouldNotOpenFile, pathname);
	}
	return read_with_bom(move(ifs));
}

}