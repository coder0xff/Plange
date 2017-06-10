#ifndef DOCUMENT_REPRESENTATION_HPP
#define DOCUMENT_REPRESENTATION_HPP

#include <map>
#include <memory>
#include <vector>

#include "parlex/details/behavior.hpp"

namespace parlex {

struct node {
	std::vector<std::shared_ptr<node>> parents;
};

struct type_node : node {
	std::string name;
	std::map<std::string, std::shared_ptr<node>> elements;
};

struct vector_node : node {
	std::string user_tag;
	std::shared_ptr<node> child;
};

struct option_node : node {
	std::string user_tag;
	std::shared_ptr<node> child;
};

struct variant_node : node {
	std::string user_tag;
	std::vector<std::shared_ptr<node>> children;
};

struct terminal_node : node {
	std::string user_tag;
};

std::map<std::string, std::shared_ptr<type_node>> make(std::shared_ptr<details::behavior_node> root);


#endif
