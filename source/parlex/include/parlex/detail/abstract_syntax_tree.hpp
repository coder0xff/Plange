#ifndef INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#define INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#include "permutation.hpp"
#include <map>


namespace parlex::detail {
class grammar;

struct ast_node : match {
		typedef std::vector<ast_node> sequence;
		typedef sequence::iterator iterator;
		typedef sequence::const_iterator const_iterator;
		sequence const children;

		// The grammar leaf that this ast_node satisfies
		leaf const * l;

		ast_node(match const & m, std::vector<ast_node> const & children, leaf const * l);
		std::string to_dot(grammar const & g) const;
	};

	typedef ast_node abstract_syntax_tree;
}



#endif //INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
