#ifndef ABSTRACT_SYNTAX_SEMILATTICE_HPP
#define ABSTRACT_SYNTAX_SEMILATTICE_HPP

#include <map>
#include <set>
#include <list>

#include "parlex/details/match.hpp"
#include "parlex/details/permutation.hpp"
#include "abstract_syntax_tree.hpp"

namespace parlex {
namespace details {

struct abstract_syntax_semilattice {
	explicit abstract_syntax_semilattice(transition root);
	std::map<match, std::set<permutation>> permutations;
	transition root;
	bool is_rooted() const;
	void cut(std::set<match> const & matches);
	void prune_detached();
	std::string to_dot() const;
	std::string to_concrete_dot(std::u32string const & document);
	std::list<std::string> warnings;
	uint64_t variation_count() const;
	std::set<permutation> const & lookup(match const & m) const;
	std::vector<ast_node> build_tree(match const & m) const;
	abstract_syntax_tree tree() const; // throws if variation_count() > 1
};

} // namespace details
} // namespace parlex

#endif //ABSTRACT_SYNTAX_SEMILATTICE_HPP
