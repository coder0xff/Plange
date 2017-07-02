#include "parlex/builder.hpp"

#include <queue>
#include <sstream>

#include "utf.hpp"
#include "graphviz_dot.hpp"
#include "covariant_invoke.hpp"

namespace parlex {
namespace details {

node::node(std::initializer_list<erased<node>> const & children) : children(children) {
}

node::node(std::string const & tag, std::initializer_list<erased<node>> const & children) : tag(tag), children(children) {
}

node::node(std::initializer_list<erased<node>> && children) : children(move(children)) {
}

node::node(std::string && tag, std::initializer_list<erased<node>> && children) : tag(move(tag)), children(move(children)) {
}

literal_t::literal_t(std::u32string const & content) : id(to_utf8(content)), content(content) {
}

literal_t::literal_t(std::string const & tag, std::u32string const & content) : node(tag, {}), id(to_utf8(content)), content(content) {
}

literal_t::literal_t(std::u32string && content) : id(to_utf8(content)), content(move(content)) {
}

literal_t::literal_t(std::string && tag, std::u32string && content) : node(move(tag), {}), id(to_utf8(content)), content(move(content)) {
}

reference_t::reference_t(std::string const & id) : id(id) {
}

reference_t::reference_t(std::string const & tag, std::string const & id) : node(tag, {}), id(id) {
}

reference_t::reference_t(std::string && id) : id(move(id)) {
}

reference_t::reference_t(std::string && tag, std::string && id) : node(move(tag), {}), id(move(id)) {
}

}

erased<details::node> literal(std::u32string const & content) { return erased<details::node>(details::literal_t(content)); }

erased<details::node> literal(std::string const & tag, std::u32string const & content) { return erased<details::node>(details::literal_t(tag, content)); }

erased<details::node> literal(std::u32string && content) { return erased<details::node>(details::literal_t(move(content))); }

erased<details::node> literal(std::string && tag, std::u32string && content) { return erased<details::node>(details::literal_t(move(tag), move(content))); }

erased<details::node> literal(std::string const & content) { return erased<details::node>(details::literal_t(to_utf32(content))); }

erased<details::node> literal(std::string const & tag, std::string const & content) { return erased<details::node>(details::literal_t(tag, to_utf32(content))); }

erased<details::node> literal(std::string && tag, std::string const & content) { return erased<details::node>(details::literal_t(move(tag), to_utf32(content))); }


erased<details::node> reference(std::string const & id) { return erased<details::node>(details::reference_t(id)); }

erased<details::node> reference(std::string const & tag, std::string const & id) { return erased<details::node>(details::reference_t(tag, id)); }

erased<details::node> reference(std::string && id) { return erased<details::node>(details::reference_t(move(id))); }

erased<details::node> reference(std::string && tag, std::string && id) { return erased<details::node>(details::reference_t(move(tag), move(id))); }

production::production(std::string const & id, erased<details::node> const & behavior, associativity assoc /*= associativity::none*/, filter_function const & filter /*= filter_function()*/, std::set<std::string> const & precedences /*= set<string>() */) : id(id), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
	this->behavior->tag = id;
}

namespace details {

static std::string node_to_name(node const * n) {
	std::stringstream result;

#define DO_AS(name) [](name##_t const & v) { return #name + (v.tag != "" ? " " + v.tag : ""); }
	result << covariant_invoke<std::string>(*n,
		[](literal_t const & v) { return v.id; },
		[](reference_t const & v) { return v.id; },
		DO_AS(choice),
		DO_AS(optional),
		DO_AS(repetition),
		DO_AS(sequence)
		);
#undef DO_AS

	result << " " << n;
	return result.str();
}

} // namespace details

std::string production::to_dot() const {
	return directed_graph<details::node const *>(
		&*behavior, details::node_to_name,
		[&](details::node const * n)
		{
		details::sequence_t const * as_sequence = dynamic_cast<details::sequence_t const *>(n);
			std::vector<std::pair<std::string, details::node const *>> edges;
			for (size_t childIndex = 0; childIndex < n->children.size(); ++childIndex) {
				auto const & erasedChild = n->children[childIndex];
				std::string edgeName = as_sequence != nullptr ? "label=" + std::to_string(childIndex) : "";
				edges.push_back(make_pair(edgeName, &*erasedChild));
			}
			return edges;
		}
	);
}

builder::builder(std::string rootId, std::list<production> const & productions) : root_id(rootId), productions(move(productions)) {
}

} // namespace parlex
