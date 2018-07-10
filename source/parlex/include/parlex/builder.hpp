#ifndef INCLUDED_PARLEX_BUILDER_HPP
#define INCLUDED_PARLEX_BUILDER_HPP

#include <vector>

#include "coherent_map.hpp"
#include "erased.hpp"

#include "parlex/associativity.hpp"
#include "parlex/detail/nfa.hpp"
#include "parlex/filter_function.hpp"

namespace parlex {
namespace detail {

struct leaf;
using automaton = nfa<leaf const *, size_t>;

struct node {
	virtual ~node() = default;
	using children_t = std::vector<erased<node>>;
	std::string tag;
	children_t children;
	node * parent = nullptr;
	// a table from all descendant leafs keys, to the child node containing the key
	collections::coherent_map<leaf const *, node const *> leaf_paths;

	void add_child(const erased<node>& child);
	virtual bool is_leaf() const;
	void compute_leaf_paths();
	virtual automaton to_nfa() const = 0;
	automaton compile();
	node const * follow_or_nullptr(leaf const * l) const;
protected:
	node() = default;
	node(std::initializer_list<erased<node>> const & children);
	node(std::string const & tag, std::initializer_list<erased<node>> const & children);
	node(node const & copy) = default;
};

struct leaf : node {
	uint16_t recognizer_index;
	bool is_leaf() const override;
protected:
	explicit leaf(std::string const & tag);
private:
	automaton to_nfa() const override;
};

} // namespace detail

struct literal final : detail::leaf {
	explicit literal(std::u32string const & content);
	explicit literal(std::string const & tag, std::u32string const & content);
	literal(literal const & copy) = default;

	std::u32string const content;
};

struct reference final : detail::leaf {
	explicit reference(std::string const & target);
	explicit reference(std::string const & tag, std::string const & target);

	reference(reference const & copy) = default;

	std::string const target;
};

struct sequence final : detail::node {
	sequence() = default;
	sequence(std::initializer_list<erased<node>>&& children) : node(children) {}
	sequence(std::string const & tag, std::initializer_list<erased<node>>&& children) : node(tag, children) {}
	sequence(sequence const & copy) = default;
	bool is_leaf() const override { return false; }
	detail::automaton to_nfa() const override;
};

struct choice final : detail::node {
	choice() = default;
	choice(std::initializer_list<erased<node>>&& children) : node(children) {}
	choice(std::string const & tag, std::initializer_list<erased<node>>&& children) : node(tag, children) {}
	choice(choice const & copy) = default;
	bool is_leaf() const override { return false; }
	detail::automaton to_nfa() const override;
};


struct optional final : detail::node {
	optional() = default;
	explicit optional(erased<node> const & child) : node({ child }) {}
	optional(std::string const & tag, erased<node> const & child) : node(tag, { child }) {}
	optional(optional const & copy) = default;
	detail::automaton to_nfa() const override;
};

struct repetition final : detail::node {
	repetition() = default;
	explicit repetition(erased<node> const & child) : node({child}) {}
	repetition(std::string const & tag, erased<node> const & child) : node(tag, {child}) {}
	repetition(repetition const & copy) = default;
	detail::automaton to_nfa() const override;
};

struct production {
	production(
		std::string const & name,
		erased<detail::node> const & behavior,
		associativity assoc = associativity::NONE,
		filter_function const & filter = filter_function(),
		std::set<std::string> const & precedences = std::set<std::string>()
	);

	std::string name;
	erased<detail::node> behavior;
	filter_function filter;
	associativity assoc;
	std::set<std::string> precedences;

	void extract_string_literals(std::set<std::u32string> & results) const;
	std::string to_dot() const;
};

struct sub_builder {
	sub_builder() = default;
	explicit sub_builder(std::vector<production> const & productions);
	std::vector<production> productions;
	std::set<std::u32string> extract_string_literals() const;
};

struct builder : sub_builder {
	std::string root_name;

	builder() = default;
	builder(std::string const & rootName, std::vector<production> const & productions);
};

} // namespace parlex

#endif // INCLUDED_PARLEX_BUILDER_HPP
