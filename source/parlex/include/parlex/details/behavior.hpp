#include <memory>

#include "parlex/details/nfa.hpp"
#include "parlex/recognizer.hpp"

namespace parlex {

class state_machine;

namespace builtins {

class string_terminal;

}

namespace details {

class behavior_leaf;

typedef nfa<std::shared_ptr<const behavior_leaf>, int> intermediate_nfa;

std::string to_dot(intermediate_nfa const & nfa);

class behavior_node {
public:
	std::string tag;

protected:
	~behavior_node();

public:
	virtual intermediate_nfa to_intermediate_nfa() const = 0;
};

class behavior_leaf : public behavior_node, public std::enable_shared_from_this<behavior_leaf> {
public:
	virtual ~behavior_leaf();

	virtual recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::map<std::u32string, builtins::string_terminal> & literals) const = 0;
	virtual std::string get_id() const = 0;
};

class choice : public behavior_node {
public:
	virtual ~choice();

	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const override;
};

class literal : public behavior_leaf {
public:
	std::u32string contents;
	explicit literal(std::u32string contents);
	intermediate_nfa to_intermediate_nfa() const override;
	recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::map<std::u32string, builtins::string_terminal> & literals) const final;
	std::string get_id() const final;
};

class optional : public behavior_node {
public:
	virtual ~optional();

	std::shared_ptr<behavior_node> child;
	explicit optional(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const override;
};

class production : public behavior_leaf {
public:
	std::string name;
	explicit production(std::string name);
	intermediate_nfa to_intermediate_nfa() const override;
	recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::map<std::u32string, builtins::string_terminal> & literals) const override;
	std::string get_id() const final;
};

class repetition : public behavior_node {
public:
	virtual ~repetition();

	std::shared_ptr<behavior_node> child;
	explicit repetition(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const override;
};

class sequence : public behavior_node {
public:
	virtual ~sequence();

	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const override;
};

}
}
