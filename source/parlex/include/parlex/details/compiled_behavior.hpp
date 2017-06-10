#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include <memory>

#include "parlex/details/nfa.hpp"
#include "parlex/recognizer.hpp"
#include "erased.hpp"
#include "behavior.hpp"

namespace parlex {

class state_machine;

namespace details {

class behavior {
public:
	class node {
	public:
		typedef std::vector<erased<node>> children_t;
		std::string tag;
		children_t children;
	protected:
		node(children_t const & children) : children(children) {}
		node(node const & other) = default;
	};

	class leaf : public node {
	public:
		leaf(recognizer const & r) : node(children_t()), r(r) {}
		recognizer const & r;
	};

	class choice : public node {
	public:
		choice(children_t const & children) : node(children) {}
	};

	class optional : public node {
	public:
		explicit optional(erased<node> const & child) : node(children_t({ child })) {}
	};

	class repetition : public node {
	public:
		explicit repetition(erased<node> const & child) : node(children_t({ child })) {}
	};

	class sequence : public node {
	public:
		sequence(children_t const & children) : node(children) {}
	};

	behavior()
};

}
}

#endif //BEHAVIOR_HPP
