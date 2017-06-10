#ifndef BEHAVIOR2_HPP
#define BEHAVIOR2_HPP

#include "parlex/details/nfa.hpp"
#include "parlex/recognizer.hpp"
#include "erased.hpp"

namespace parlex {

class state_machine;

class behavior2 {
public:
	class leaf;
	typedef details::nfa<leaf const *, int> nfa;

	class node {
	public:
		virtual ~node() = default;
		typedef std::vector<erased<node>> children_t;
		std::string tag;
		void add_child(erased<node> child);
		children_t const& get_children() const;
		virtual nfa to_nfa() const = 0;
	protected:
		node() = default;

		node(node const & other);


		children_t children;
		node * parent;
	};

	class leaf final : public node {
	public:
		explicit leaf(recognizer const & r);

	private:
		nfa to_nfa() const override;
	public:
		recognizer const & r;
	};

	class choice final : public node {
	public:
		nfa to_nfa() const override;
	};

	class optional final : public node {
	public:
		nfa to_nfa() const override;
	};

	class repetition final : public node {
	public:
		nfa to_nfa() const override;
	};

	class sequence final : public node {
	public:
		nfa to_nfa() const override;
	};

	static nfa compile(erased<node> const root);

}; //class behavior2

} // namespace parlex

#endif //BEHAVIOR2_HPP
