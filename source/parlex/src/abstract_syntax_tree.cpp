#include "../include/parlex/details/abstract_syntax_tree.hpp"

#include "graphviz_dot.hpp"

#include "parlex/details/behavior.hpp"

std::string parlex::details::ast_node::to_dot() const
{
	auto name_func = [&](ast_node const * n) { return n->leaf->r.id; };
	auto edge_func = [&](ast_node const * n) {
		std::vector<std::pair<std::string, ast_node const *>> results;
		for (auto i = n->children.begin(); i != n->children.end(); ++i) {
			results.emplace_back(std::to_string(i - n->children.begin() + 1), &*i);
		}
		return results;
	};
	auto prop_func = [&](ast_node const * n) { return std::string(); };
	return directed_graph<ast_node const *>(this, name_func, edge_func, prop_func);
}
