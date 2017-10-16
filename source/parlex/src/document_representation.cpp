#include "parlex/document_representation.hpp"
#include "covariant_invoke.hpp"
#include <optional>

namespace parlex {
namespace details {

unit::unit(node const & n) : original_leaf(n) {
	tag = n.tag;
}

static erased<node> copy_with_conversions(erased<node> const & n) {
	node const & nPtr = *n;

#define DO_AS(name) \
	[&](name const & v) { \
		name result; \
		result.tag = v.tag; \
		for (auto const & child : v.children) { \
			result.children.push_back(copy_with_conversions(child)); \
		} \
		return result; \
	}

	return covariant_invoke<erased<node>> (nPtr, 
		[&](literal_t const & v) { return v; },
		[&](reference_t const & v) { return v; },
		DO_AS(choice_t),
		DO_AS(optional_t),
		DO_AS(repetition_t),
		DO_AS(sequence_t)
	);
}

static erased<node> reduce(erased<node> const & n) {
	auto get_children = [&](std::function<std::optional<erased<node>> (erased<node> const &)> selector)
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

	return covariant_invoke<erased<node>>(*n,
		[&](unit const & v) { return v; },
		[&](aggregate const & v) { return v; },
		[&](choice_t const & v) { return v; },
		[&](optional_t const & v) { return v; },
		[&](repetition_t const & v) { return v; },
		[&](sequence_t const & v) {
			node::children_t children = get_children([&](erased<node> const & child) {
				std::optional<erased<node>> result;
				auto const * asUnitPtr = dynamic_cast<unit const *>(&*child);
				if (asUnitPtr == nullptr || asUnitPtr->tag != "") {
					result = child;
				}
				return result;
			});
// 			if (children.size() == 0) {
// 				auto result = erased<node>(unit(v));
// 				result->tag = v.tag;
// 				return result;
// 			}
			if (std::all_of(children.begin(), children.end(), [](erased<node> const & child) { return child->tag != ""; })) {
				aggregate result;
				int childIndex = 0;
				for (auto const & child : children) {
					erased<node> childCopy = child;
					childCopy->tag = "";
					result.add_member(child->tag, childCopy);
					++childIndex;
				}
				return erased<node>(result);
			}
			sequence_t result;
			result.children = children;
			return erased<node>(result);
		}
	);
}

void aggregate::add_member(std::string const & name, erased<node> const & type) {
	for (auto const & member : data_members) {
		if (member.first == name) {
			throw std::runtime_error("duplicate member name");
		}
	}
	data_members.emplace_back(name, type);
}

erased<node> compute_document_representation(erased<node> const & root) {
	return copy_with_conversions(root);
}


} // namespace details
} // namespace parlex
