#ifndef INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#define INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#include "permutation.hpp"
#include <map>


namespace parlex::details {
	
	struct ast_node : match {
		std::vector<ast_node> const children;
		behavior::leaf const * leaf;

		ast_node(match const &, std::vector<ast_node> const & children, behavior::leaf const * leaf);
		std::string to_dot() const;
	};

	typedef ast_node abstract_syntax_tree;
}


#endif INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP