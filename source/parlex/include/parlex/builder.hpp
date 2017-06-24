#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <vector>

#include "erased.hpp"
#include "filter_function.hpp"
#include "associativity.hpp"

namespace parlex {
namespace builder {

struct node {
	virtual ~node() = default;
	using children_t = std::vector<erased<node>>;
	std::string tag;
	children_t children;
protected:
	node() = default;
	node(std::initializer_list<erased<node>> const & children);
	node(std::string const & tag, std::initializer_list<erased<node>> const & children);
	node(std::initializer_list<erased<node>> && children);
	node(std::string && tag, std::initializer_list<erased<node>> && children);
	node(node const & copy) = default;
};

struct literal_t final : node {
	explicit literal_t(std::u32string const & content);
	explicit literal_t(std::string const & tag, std::u32string const & content);
	explicit literal_t(std::u32string && content);
	explicit literal_t(std::string && tag, std::u32string && content);
	literal_t(literal_t const & copy) = default;

	std::string const id;
	std::u32string const content;
};

erased<node> literal(std::u32string const & content);
erased<node> literal(std::string const & tag, std::u32string const & content);
erased<node> literal(std::u32string && content);
erased<node> literal(std::string && tag, std::u32string && content);
erased<node> literal(std::string const & content);
erased<node> literal(std::string const & tag, std::string const & content);
erased<node> literal(std::string && tag, std::string const & content);

struct reference_t final : node {
	explicit reference_t(std::string const & id);
	explicit reference_t(std::string const & tag, std::string const & id);
	explicit reference_t(std::string && id);
	explicit reference_t(std::string && tag, std::string && id);

	reference_t(reference_t const & copy) = default;

	std::string const id;
};

erased<node> reference(std::string const & id);
erased<node> reference(std::string const & tag, std::string const & id);
erased<node> reference(std::string && id);
erased<node> reference(std::string && tag, std::string && id);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAKE_NODE_TYPE(name)                                                                                                                           \
struct name##_t final : node {                                                                                                                          \
	name##_t() {}                                                                                                                                        \
	name##_t(std::initializer_list<erased<node>> const & children) : node(children) {}                                                                    \
	name##_t(std::string const & tag, std::initializer_list<erased<node>> const & children) : node(tag, children) {}                                       \
	name##_t(std::initializer_list<erased<node>>&& children) : node(move(children)) {}                                                                      \
	name##_t(std::string && tag, std::initializer_list<erased<node>>&& children) : node(move(tag), move(children)) {}                                        \
	name##_t(name##_t const & copy) = default;                                                                                                                \
};                                                                                                                                                             \
                                                                                                                                                                \
inline erased<node> name(std::initializer_list<erased<node>> const & children) { return erased<node>(name##_t(children)); }                                      \
inline erased<node> name(std::string const & tag, std::initializer_list<erased<node>> const & children) { return erased<node>(name##_t(tag, children)); }         \
inline erased<node> name(std::initializer_list<erased<node>>&& children) { return erased<node>(name##_t(move(children))); }                                        \
inline erased<node> name(std::string && tag, std::initializer_list<erased<node>>&& children) { return erased<node>(name##_t(move(tag), move(children))); }          \
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MAKE_NODE_TYPE(sequence)
MAKE_NODE_TYPE(choice)
#undef MAKE_NODE_TYPE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAKE_NODE_TYPE(name)                                                                                                                           \
struct name##_t final : node {                                                                                                                          \
	name##_t() {}                                                                                                                  \
	name##_t(erased<node> const & child) : node({ child }) {}                                                                                          \
	name##_t(std::string const & tag, erased<node> const & child) : node(tag, { child }) {}                                                          \
	name##_t(std::initializer_list<erased<node>> const & children) : node({ sequence_t {children} }) {}                                                                    \
	name##_t(std::string const & tag, std::initializer_list<erased<node>> const & children) : node(tag, { sequence_t {children} }) {}                                       \
	name##_t(std::initializer_list<erased<node>>&& children) : node({ sequence_t {move(children)} }) {}                                                                      \
	name##_t(std::string && tag, std::initializer_list<erased<node>>&& children) : node(move(tag), move(children)) {}                                        \
	name##_t(name##_t const & copy) = default;                                                                                                              \
};                                                                                                                                                           \
                                                                                                                                                              \
inline erased<node> name(erased<node> const & child) { return erased<node>(name##_t(child)); }                                                                 \
inline erased<node> name(std::string const & tag, erased<node> const & child) { return erased<node>(name##_t(tag, child)); }                                    \
inline erased<node> name(std::initializer_list<erased<node>> const & children) { return erased<node>(name##_t(children)); }                                      \
inline erased<node> name(std::string const & tag, std::initializer_list<erased<node>> const & children) { return erased<node>(name##_t(tag, children)); }         \
inline erased<node> name(std::initializer_list<erased<node>>&& children) { return erased<node>(name##_t(move(children))); }                                        \
inline erased<node> name(std::string && tag, std::initializer_list<erased<node>>&& children) { return erased<node>(name##_t(move(tag), move(children))); }          \
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MAKE_NODE_TYPE(optional)
MAKE_NODE_TYPE(repetition)

#undef MAKE_NODE_TYPE

struct production {
	production(
		std::string const & id,
		erased<node> const & behavior,
		associativity assoc = associativity::none,
		filter_function const & filter = filter_function(),
		std::set<std::string> const & precedences = std::set<std::string>()
	);

	std::string id;
	erased<node> behavior;
	filter_function filter;
	associativity assoc;
	std::set<std::string> precedences;

	std::string to_dot() const;
};

struct grammar {
	grammar() = default;

	std::string root_id;
	std::list<production> productions;

	grammar(std::string rootId, std::list<production> const & productions);
};

} // namespace builder
} // namespace parlex

//////////////////////////////////////////////////////////////////////////////////////////////////////
#define DECLARE_DFA(name)                                                                            \
	class name##_t : public parlex::state_machine_base {                                              \
	public:                                                                                            \
		name##_t();                                                                                     \
		void process(parlex::details::context_ref const & c, size_t dfaState) const override;            \
		int get_start_state() const final;                                                                \
		parlex::filter_function get_filter() const final;                                                  \
		parlex::associativity get_assoc() const final;                                                      \
	}                                                                                                        \
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_TERMINAL(name, U32content) static parlex::details::string_terminal name(U32content)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define DEFINE_DFA(name, cases, startStates)                                                                          \
	name##_t::name##_t() : state_machine_base(#name) {}                                                                \
	void name##_t::process(parlex::details::context_ref const & c, size_t dfaState) const {                             \
		switch (dfaState) {                                                                                              \
		cases                                                                                                             \
		default:                                                                                                           \
			throw std::logic_error("invalid state: " + std::to_string(dfaState));                                           \
		}                                                                                                                    \
	}                                                                                                                         \
	name##_t name                                                                                                              \
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DFA_STATE case
#define DFA_ACCEPT accept(c)
#define DFA_EDGE(recognizer, out_neighbor) on(c, recognizer, out_neighbor)

#define DEFINE_GRAMMAR(builtins, name, main, productions, precedences) \
	parlex::compiled_grammar name(builtins, main, std::vector<std::reference_wrapper<parlex::state_machine_base const>>productions, std::vector<std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>>precedences)

#define GRAMMAR_PRECEDENCE(a, b) (std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>(a, b))

#endif //BUILDER_HPP
