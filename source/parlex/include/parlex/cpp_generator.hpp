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
	static std::map<std::string /* filename */, std::string /* content */> generate(std::string const & name, builder::grammar const & g);
};

} // namespace parlex

#endif //PARLEX_CPP_GENERATOR_HPP
