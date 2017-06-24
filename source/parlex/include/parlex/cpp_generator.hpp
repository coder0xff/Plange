#ifndef PARLEX_CPP_GENERATOR_HPP
#define PARLEX_CPP_GENERATOR_HPP

#include <map>
#include <vector>

namespace parlex {
class builtins_t;

namespace builder {
struct grammar;
}

class cpp_generator {
public:
	typedef std::map<std::string /* filename */, std::string /* content */> file_dictionary;

	struct output_files {
		file_dictionary headers;
		file_dictionary sources;
	};

	static output_files generate(std::string const & name, builder::grammar const & g);
};

} // namespace parlex

#endif //PARLEX_CPP_GENERATOR_HPP
