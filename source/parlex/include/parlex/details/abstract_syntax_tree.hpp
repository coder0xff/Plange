#ifndef INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#define INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#include "permutation.hpp"
#include <map>


namespace parlex::details {
	
	struct ast_node {
		std::vector<ast_node> children;
		behavior::leaf const * leaf;
		size_t document_position;
		size_t consumed_character_count;

		std::string to_dot() const;
	};

	typedef ast_node abstract_syntax_tree;
}


#endif INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP