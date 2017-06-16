#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "parlex/state_machine_base.hpp"
#include "parlex/details/string_terminal.hpp"
#include "erased.hpp"

namespace parlex {
namespace builder {
struct node {
	virtual ~node() = default;
	typedef std::vector<erased<node>> children_t;
	std::string tag;
	children_t children;
protected:
	node() {
	}

	node(std::initializer_list<erased<node>> const & children) : children(children) {
	}

	node(std::initializer_list<erased<node>> && children) : children(move(children)) {
	}
};

struct literal_t final : node {
	explicit literal_t(std::u32string const & content) : id(to_utf8(content)), content(content) {
	}

	literal_t(literal_t const & copy) = default;

	std::string const id;
	std::u32string const content;
};

inline erased<node> literal(std::u32string const & content) { return erased<node>(literal_t(content)); }
inline erased<node> literal(std::u32string && content) { return erased<node>(literal_t(move(content))); }

struct reference_t final : node {
	explicit reference_t(std::string const & id) : id(id) {
	}

	std::string const id;
};

inline erased<node> reference(std::string const & id) { return erased<node>(reference_t(id)); }
inline erased<node> reference(std::string && id) { return erased<node>(reference_t(move(id))); }

#define MAKE_NODE_TYPE(name) \
struct name##_t final : node { \
	name##_t() {} \
	name##_t(std::initializer_list<erased<node>> const & children) : node(children) {} \
	name##_t(std::initializer_list<erased<node>>&& children) : node(move(children)) {} \
}; \
 \
inline erased<node> name() { return erased<node>(name##_t()); } \
inline erased<node> name(std::initializer_list<erased<node>> const & children) { return erased<node>(name##_t(children)); } \
inline erased<node> name(std::initializer_list<erased<node>>&& children) { return erased<node>(name##_t(move(children))); }

MAKE_NODE_TYPE(choice)
MAKE_NODE_TYPE(optional)
MAKE_NODE_TYPE(repetition)
MAKE_NODE_TYPE(sequence)

struct production {
	production(
		std::string const & id,
		erased<node> const & behavior,
		associativity assoc = associativity::none,
		filter_function const & filter = filter_function(),
		std::set<std::string> const & precedences = std::set<std::string>()
	) : id(id), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
	}

// 	production(
// 		std::string const & id,
// 		erased<node> const & behavior,
// 		associativity assoc = associativity::none,
// 		filter_function const & filter = filter_function(),
// 		std::initializer_list<std::string>&& precedences = std::initializer_list<std::string>()
// 	) : id(id), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
// 	}

	std::string id;
	erased<node> behavior;
	filter_function filter;
	associativity assoc;
	std::set<std::string> precedences;
};

struct grammar {
	grammar() {
	}

	grammar(std::string rootId, std::list<production> const & productions) : root_id(rootId), productions(move(productions)) {}
	std::string root_id;
	std::list<production> productions;
};

} // namespace builder
} // namespace parlex

#define DECLARE_DFA(name) \
	class name##_t : public parlex::state_machine_base { \
	public: \
		name##_t(parlex::builtins_t const & builtins); \
		void process(parlex::details::context_ref const & c, size_t dfaState) const override; \
		parlex::builtins_t const & builtins; \
		int get_start_state() const final; \
		parlex::filter_function get_filter() const final; \
		parlex::associativity get_assoc() const final; \
	}

#define DEFINE_TERMINAL(name, U32content) static parlex::details::string_terminal name(U32content)

#define DEFINE_DFA(name, cases, startStates) \
	name##_t::name##_t(parlex::builtins_t const & builtins) : state_machine_base(#name), builtins(builtins) {} \
	void name##_t::process(parlex::details::context_ref const & c, size_t dfaState) const { \
		switch (dfaState) { \
		cases \
		default: \
			throw std::logic_error("invalid state: " + std::to_string(dfaState)); \
		} \
	} \
	name##_t name

#define DFA_STATE case
#define DFA_ACCEPT accept(c)
#define DFA_EDGE(recognizer, out_neighbor) on(c, recognizer, out_neighbor)

#define DEFINE_GRAMMAR(builtins, name, main, productions, precedences) \
	parlex::compiled_grammar name(builtins, main, std::vector<std::reference_wrapper<parlex::state_machine_base const>>productions, std::vector<std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>>precedences)

#define GRAMMAR_PRECEDENCE(a, b) (std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>(a, b))

#endif //BUILDER_HPP
