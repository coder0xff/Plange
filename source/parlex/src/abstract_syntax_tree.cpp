#include "../include/parlex/details/abstract_syntax_tree.hpp"

#include "graphviz_dot.hpp"

#include "parlex/details/behavior.hpp"

parlex::details::ast_node::ast_node(match const & m, std::vector<ast_node> const & children, behavior::leaf const * leaf) : match(m), children(children), leaf(leaf) {}

std::string parlex::details::ast_node::to_dot() const
{
	auto name_func2 = [&](ast_node const * n)
	{
		std::stringstream result;
		result << n->r.id << " (" << n << ")";
		return result.str();
	};
	auto edge_func = [&](ast_node const * n) {
		std::vector<std::pair<std::string, ast_node const *>> results;
		for (auto i = n->children.begin(); i != n->children.end(); ++i) {
			results.emplace_back("label=" + enquote(std::to_string(i - n->children.begin() + 1)), &*i);
		}
		return results;
	};
	auto prop_func = [&](ast_node const * n) { return std::string(); };
	return directed_graph<ast_node const *>(this, name_func2, edge_func, prop_func);
}
