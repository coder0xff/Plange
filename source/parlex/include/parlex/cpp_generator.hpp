#ifndef PARLEX_CPP_GENERATOR_HPP
#define PARLEX_CPP_GENERATOR_HPP

#include <map>
#include <vector>

namespace parlex {
class builtins_t;

namespace builder {
struct production;
struct grammar;
}

class cpp_generator {
public:
	std::map<std::string /* filename */, std::string /* content */> generate(builtins_t const & builtins, std::string const & name, builder::grammar const & g, std::vector<std::string> const & namespaces);
};

} // namespace parlex

#endif //PARLEX_CPP_GENERATOR_HPP
