#ifndef INCLUDED_PARLEX_DOCUMENT_REPRESENTATION_HPP
#define INCLUDED_PARLEX_DOCUMENT_REPRESENTATION_HPP

#include "parlex/builder.hpp"

namespace parlex {
namespace detail {

// a leaf node that may reduce its parent's representation to a simpler form
struct unit : node {
	explicit unit(node const & n);
	node const & original_leaf;

	automaton to_nfa() const override;
};

// a leaf node representing a data structure
struct aggregate : node {
	typedef std::vector<std::pair<std::string /* data member name */, val<node>>> data_members_t;
	data_members_t data_members;
	void add_member(std::string const & name, val<node> const & type);

	automaton to_nfa() const override;
};

val<node> compute_document_representation(val<node> const & root);

} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_DOCUMENT_REPRESENTATION_HPP
