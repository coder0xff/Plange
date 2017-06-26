#ifndef DOCUMENT_REPRESENTATION_HPP
#define DOCUMENT_REPRESENTATION_HPP

#include <map>

#include "builder.hpp"

namespace parlex {
namespace details {

// a leaf node that may reduce its parent's representation to a simpler form
struct unit : node {
	unit(node const & n);
	node const & original_leaf;
};

struct type : node {
	type(std::string const & name);
	std::string name;
};

// a leaf node representing a data structure
struct aggregate : node {
	std::map<std::string /* data member name */, erased<node>> data_members;
};

erased<node> compute_document_representation(erased<node> const & root);

} // namespace details
} // namespace parlex

#endif //DOCUMENT_REPRESENTATION_HPP
