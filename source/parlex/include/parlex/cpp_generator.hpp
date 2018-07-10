#ifndef INCLUDED_PARLEX_CPP_GENERATOR_HPP
#define INCLUDED_PARLEX_CPP_GENERATOR_HPP

#include <list>
#include <map>
#include <vector>

namespace parlex {

struct builder;

class cpp_generator {
public:
	typedef std::map<std::string /* filename */, std::string /* content */> file_dictionary;

	struct output_files {
		file_dictionary headers;
		file_dictionary sources;
		void add(output_files const & other);
	};

	static output_files generate(std::string const & name, std::list<std::string> const & namespaces, builder const & b);
};

} // namespace parlex

#endif // INCLUDED_PARLEX_CPP_GENERATOR_HPP
