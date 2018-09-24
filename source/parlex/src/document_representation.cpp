#include "parlex/document_representation.hpp"

#include <optional>

#include "covariant_invoke.hpp"

namespace parlex {
namespace detail {

unit::unit(node const & n) : original_leaf(n) {
	tag = n.tag;
}

automaton unit::to_nfa() const
{
	throw std::logic_error("This operation is invalid");
}

static val<node> copy_with_conversions(val<node> const & n) {
	auto const & nPtr = *n;

#define DO_AS(name) \
	[&](name const & v) { \
		name result; \
		result.tag = v.tag; \
		for (auto const & child : v.children) { \
			result.children.push_back(copy_with_conversions(child)); \
		} \
		return result; \
	}

	return covariant_invoke<val<node>> (nPtr, 
		[&](literal const & v) { return v; },
		[&](reference const & v) { return v; },
		DO_AS(choice),
		DO_AS(optional),
		DO_AS(repetition),
		DO_AS(sequence)
	);
}

static val<node> reduce(val<node> const & n) {
	auto getChildren = [&](std::function<std::optional<val<node>> (val<node> const &)> selector)
	{
		node::children_t newChildren;
		for (auto & child : n->children) {
			auto maybeChild = selector(reduce(child));
			if (maybeChild.has_value()) {
				newChildren.push_back(maybeChild.value());
			}
		}
		return newChildren;
	};

	return covariant_invoke<val<node>>(*n,
		[&](unit const & v) { return v; },
		[&](aggregate const & v) { return v; },
		[&](choice const & v) { return v; },
		[&](optional const & v) { return v; },
		[&](repetition const & v) { return v; },
		[&](sequence const & v) {
			auto children = getChildren([&](val<node> const & child) {
				std::optional<val<node>> result;
				auto const * asUnitPtr = dynamic_cast<unit const *>(&*child);
				if (asUnitPtr == nullptr || !asUnitPtr->tag.empty()) {
					result = child;
				}
				return result;
			});
			if (std::all_of(children.begin(), children.end(), [](val<node> const & child) { return !child->tag.empty(); })) {
				aggregate result;
				auto childIndex = 0;
				for (auto const & child : children) {
					auto childCopy = child;
					childCopy->tag = "";
					result.add_member(child->tag, childCopy);
					++childIndex;
				}
				return val<node>(result);
			}
			sequence result;
			result.children = children;
			return val<node>(result);
		}
	);
}

void aggregate::add_member(std::string const & name, val<node> const & type) {
	for (auto const & member : data_members) {
		if (member.first == name) {
			throw std::runtime_error("duplicate member name");
		}
	}
	data_members.emplace_back(name, type);
}


automaton aggregate::to_nfa() const
{
	throw std::logic_error("This operation is invalid");
}

val<node> compute_document_representation(val<node> const & root) {
	return copy_with_conversions(root);
}


} // namespace detail
} // namespace parlex
