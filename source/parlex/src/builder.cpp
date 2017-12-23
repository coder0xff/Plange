#include "parlex/builder.hpp"

#include <sstream>

#include "utf.hpp"
#include "graphviz_dot.hpp"
#include "covariant_invoke.hpp"

namespace parlex {
namespace detail {

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

erased<detail::node> literal(std::u32string const & content) { return erased<detail::node>(detail::literal_t(content)); }

erased<detail::node> literal(std::string const & tag, std::u32string const & content) { return erased<detail::node>(detail::literal_t(tag, content)); }

erased<detail::node> literal(std::u32string && content) { return erased<detail::node>(detail::literal_t(move(content))); }

erased<detail::node> literal(std::string && tag, std::u32string && content) { return erased<detail::node>(detail::literal_t(move(tag), move(content))); }

erased<detail::node> literal(std::string const & content) { return erased<detail::node>(detail::literal_t(to_utf32(content))); }

erased<detail::node> literal(std::string const & tag, std::string const & content) { return erased<detail::node>(detail::literal_t(tag, to_utf32(content))); }

erased<detail::node> literal(std::string && tag, std::string const & content) { return erased<detail::node>(detail::literal_t(move(tag), to_utf32(content))); }


erased<detail::node> reference(std::string const & id) { return erased<detail::node>(detail::reference_t(id)); }

erased<detail::node> reference(std::string const & tag, std::string const & id) { return erased<detail::node>(detail::reference_t(tag, id)); }

erased<detail::node> reference(std::string && id) { return erased<detail::node>(detail::reference_t(move(id))); }

erased<detail::node> reference(std::string && tag, std::string && id) { return erased<detail::node>(detail::reference_t(move(tag), move(id))); }

production::production(std::string const & id, erased<detail::node> const & behavior, associativity const assoc /*= associativity::none*/, filter_function const & filter /*= filter_function()*/, std::set<std::string> const & precedences /*= set<string>() */) : id(id), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
	this->behavior->tag = id;
}

namespace detail {

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

} // namespace detail

std::string production::to_dot() const {
	return directed_graph<detail::node const *>(
		&*behavior, detail::node_to_name,
		[&](detail::node const * n)
		{
			auto asSequence = dynamic_cast<detail::sequence_t const *>(n);
			std::vector<std::pair<std::string, detail::node const *>> edges;
			for (size_t childIndex = 0; childIndex < n->children.size(); ++childIndex) {
				auto const & erasedChild = n->children[childIndex];
				auto edgeName = asSequence != nullptr ? "label=" + std::to_string(childIndex) : "";
				edges.push_back(make_pair(edgeName, &*erasedChild));
			}
			return edges;
		}
	);
}

builder::builder(std::string const rootId, std::list<production> const & productions) : root_id(rootId), productions(move(productions)) {
}

} // namespace parlex
