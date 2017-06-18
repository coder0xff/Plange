#ifndef DOCUMENT_REPRESENTATION_HPP
#define DOCUMENT_REPRESENTATION_HPP

#include <map>

#include "builder.hpp"

namespace parlex {
namespace builder {
	
// represents a unit type that can reduce a parent to a simpler type 
struct unit_t : node {
	
};

struct aggregate_t : node {
	std::map<std::string, erased<node> const *> data_members;
};

struct field {
	node const * behavior;
};
	
struct struct_t {
	std::map<std::string, field> fields;
};

// simplify builder nodes into struct-like representations
erased<node> simplify(grammar g);

} // namespace builder
} // namespace parlex

#endif //DOCUMENT_REPRESENTATION_HPP
