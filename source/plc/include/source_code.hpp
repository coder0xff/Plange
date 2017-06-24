#ifndef SOURCE_CODE_HPP
#define SOURCE_CODE_HPP
#include <map>

namespace plc {

class scope;

class source_code {
public:
	source_code(std::string const& pathname, std::u32string const& document);
	source_code(std::string const& pathname);
	~source_code();
	std::string pathname;
	std::u32string const document;
	std::pair<int, int> get_line_number_and_column(int charIndex) const;
private:
	std::map<int, int> line_number_by_first_character;
};

}
#endif
