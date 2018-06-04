#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/grammar.hpp"

#include <string>
#include <utility>

#include "graphviz_dot.hpp"


parlex::detail::ast_node::ast_node(transition const & t, std::vector<ast_node> children) : transition(t), children(std::move(children)) {}

std::string parlex::detail::ast_node::to_dot(grammar const & g) const
{
	auto const nameFunc = [&](ast_node const * n)
	{
		std::stringstream result;
		result << g.get_recognizer(n->recognizer_index).name << " (" + std::to_string(n->document_position + 1) + " - " + std::to_string(n->consumed_character_count + n->document_position) + ")";
		return result.str();
	};
	auto const edgeFunc = [&](ast_node const * n) {
		std::vector<std::pair<std::string, ast_node const *>> results;
		for (auto i = n->children.begin(); i != n->children.end(); ++i) {
			results.emplace_back("label=" + enquote(std::to_string(i - n->children.begin() + 1)), &*i);
		}
		return results;
	};
	auto const propFunc = [&](ast_node const * n) { return std::string(); };
	return directed_graph<ast_node const *>(this, nameFunc, edgeFunc, propFunc);
}
