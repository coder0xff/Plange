#ifndef BEHAVIOR2_HPP
#define BEHAVIOR2_HPP

#include "parlex/details/nfa.hpp"
#include "parlex/recognizer.hpp"
#include "erased.hpp"

namespace parlex {

class state_machine;

namespace behavior2 {

	class leaf;
	using nfa2 = details::nfa<leaf const *, int>;

	class node {
	public:
		virtual ~node() = default;
		typedef std::vector<erased<node>> children_t;
		std::string tag;
		void add_child(erased<node> child);
		children_t const& get_children() const;
		virtual nfa2 to_nfa() const = 0;
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

} // namespace behavior2
} // namespace parlex

#endif //BEHAVIOR2_HPP
