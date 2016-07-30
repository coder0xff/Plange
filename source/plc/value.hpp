#ifndef VALUE_HPP
#define VALUE_HPP
#include <cstdint>
#include <vector>

class value {
public:
	value * type;
	std::vector<int8_t> storage;

	value(value* type, const std::vector<int8_t>& storage);
	//reference equality
	bool operator ==(value const & rhs);
};

#endif //VALUE_HPP
