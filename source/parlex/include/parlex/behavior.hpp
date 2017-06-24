#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include "parlex/details/nfa.hpp"
#include "parlex/recognizer.hpp"
#include "erased.hpp"

namespace parlex {

class state_machine;

namespace behavior {

class leaf;
using nfa2 = details::nfa<leaf const *, int>;
std::string nfa2_to_dot(nfa2 const & nfa);

class node {
public:
	virtual ~node() = default;
	using children_t = std::vector<erased<node>>;
	std::string tag;
	void add_child(erased<node> child);
	children_t const& get_children() const;
	virtual nfa2 to_nfa() const = 0;
	std::string to_dot() const;
	nfa2 compile() const;
protected:
	node() = default;

	node(node const & other);


	children_t children;
	node * parent;
};

class leaf final : public node {
public:
	explicit leaf(recognizer const & r);
	recognizer const & r;
	std::string const & id;
private:
	nfa2 to_nfa() const override;
};

class choice final : public node {
public:
	nfa2 to_nfa() const override;
};

class optional final : public node {
public:
	nfa2 to_nfa() const override;
};

class repetition final : public node {
public:
	nfa2 to_nfa() const override;
};

class sequence final : public node {
public:
	nfa2 to_nfa() const override;
};

} // namespace behavior
} // namespace parlex

#endif //BEHAVIOR_HPP
