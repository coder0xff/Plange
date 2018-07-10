#ifndef INCLUDED_UTILITIES_GRAPHVIZ_DOT_HPP
#define INCLUDED_UTILITIES_GRAPHVIZ_DOT_HPP

#include <functional>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "utils.hpp"

template<typename VertexT>
std::string directed_graph(
	std::vector<VertexT> const & vertices,
	std::function<std::string(VertexT const &)> getName,
	std::function<std::vector<std::pair<std::string /*edge properties*/, VertexT>>(VertexT const &)> getEdges,
	std::function<std::string(VertexT const &)> getProperties = std::function<std::string(VertexT const &)>()
) {
	std::stringstream result;
	result << "digraph nfa {\n";

	for (auto const & vertex : vertices) {
		std::string const name = enquote(getName(vertex));
		std::string properties = getProperties ? getProperties(vertex) : "";
		if (!properties.empty()) {
			result << "\t" << name << " [" << properties << "];\n";
		}
	}

	for (auto const & vertex : vertices) {
		std::string const fromName = enquote(getName(vertex));
		auto edges = getEdges(vertex);
		for (auto const & edge : edges) {
			std::string const toName = enquote(getName(edge.second));
			result << "\t" << fromName << " -> " << toName;
			if (edge.first != "") {
				result << " [" << edge.first << "]";
			}
			result << ";\n";
		}
	}

	result << "}\n";

	return result.str();
}

template<typename VertexT>
std::string directed_graph(
	VertexT const & root,
	std::function<std::string(VertexT const &)> getName,
	std::function<std::vector<std::pair<std::string /*edge properties*/, VertexT>>(VertexT const &)> getEdges,
	std::function<std::string(VertexT const &)> getProperties = std::function<std::string(VertexT const &)>()
) {
	std::vector<VertexT> vertices;
	std::queue<VertexT> q;
	q.push(root);
	while (q.size() > 0) {
		VertexT vertex = q.front();
		q.pop();
		vertices.push_back(vertex);
		auto edges = getEdges(vertex);
		for (auto const & edge : edges) {
			q.push(edge.second);
		}
	}
	return directed_graph(vertices, getName, getEdges, getProperties);
}

#endif // INCLUDED_UTILITIES_GRAPHVIZ_DOT_HPP