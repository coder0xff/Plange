#ifndef ABSTRACT_SYNTAX_SEMILATTICE_HPP
#define ABSTRACT_SYNTAX_SEMILATTICE_HPP

#include <map>
#include <set>
#include <list>

#include "parlex/detail/match.hpp"
#include "parlex/detail/derivation.hpp"
#include "abstract_syntax_tree.hpp"

namespace parlex {
namespace detail {

// an upper semilattice with two types of nodes, representing all the possible interpretations of an input document
// If the documentation representation is unambiguous (variation_count() == 1) then tree() can produce an AST
struct abstract_syntax_semilattice {
	explicit abstract_syntax_semilattice(match root);
	std::map<match, std::set<derivation>> derivations_of_matches;
	match root;
	bool is_rooted() const;
	void cut(std::set<match> const & matches);
	void prune_detached();
	std::string to_dot(grammar const & g) const;
	std::vector<abstract_syntax_tree> to_asts() const;
	//std::string to_concrete_dot(std::u32string const & document);
	std::list<std::string> warnings;
	uint64_t variation_count() const;
	std::set<derivation> const & lookup(match const & m) const;
	std::vector<ast_node> build_tree(match const & m) const;
	abstract_syntax_tree tree() const; // throws if variation_count() > 1
};

} // namespace detail
} // namespace parlex

#endif //ABSTRACT_SYNTAX_SEMILATTICE_HPP
