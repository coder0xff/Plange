#ifndef INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#define INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#include "permutation.hpp"
#include <map>


namespace parlex::detail {
	
	struct ast_node : match {
		typedef std::vector<ast_node> sequence;
		typedef sequence::iterator iterator;
		typedef sequence::const_iterator const_iterator;
		sequence const children;

		// The grammar leaf that this ast_node satisfies
		behavior::leaf const * leaf;

		ast_node(match const &, std::vector<ast_node> const & children, behavior::leaf const * leaf);
		std::string to_dot() const;
	};

	typedef ast_node abstract_syntax_tree;
}



#endif //INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
