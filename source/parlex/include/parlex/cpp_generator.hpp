#ifndef PARLEX_CPP_GENERATOR_HPP
#define PARLEX_CPP_GENERATOR_HPP

#include <map>
#include <vector>
#include <list>

namespace parlex {

struct builder;

class cpp_generator {
public:
	typedef std::map<std::string /* filename */, std::string /* content */> file_dictionary;

	struct output_files {
		file_dictionary headers;
		file_dictionary sources;
		void add(output_files const & files);
	};

	static output_files generate(std::string const & name, std::list<std::string> const & namespaces, builder const & g);
};

} // namespace parlex

#endif //PARLEX_CPP_GENERATOR_HPP
