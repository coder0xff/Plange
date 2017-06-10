#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include <memory>

#include "parlex/details/nfa.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/recognizer.hpp"

namespace parlex {
class builtins_t;

class state_machine;

namespace details {

class behavior_leaf;

typedef nfa<std::shared_ptr<const behavior_leaf>, int> intermediate_nfa;

std::string to_dot(intermediate_nfa const & nfa);

class behavior_node {
public:
	std::string tag;
	virtual std::vector<std::shared_ptr<behavior_node>> get_children() = 0;
protected:
	~behavior_node();

public:
	virtual intermediate_nfa to_intermediate_nfa() const = 0;
};

class behavior_leaf : public behavior_node, public std::enable_shared_from_this<behavior_leaf> {
public:
	virtual ~behavior_leaf();

	virtual recognizer const & get_recognizer(builtins_t const & builtins, std::map<std::string, state_machine> const & productions, std::map<std::u32string, string_terminal> & literals) const = 0;
	virtual std::string get_id() const = 0;
	std::vector<std::shared_ptr<behavior_node>> get_children() override;
};

class choice : public behavior_node {
public:
	virtual ~choice();

	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const override;
	std::vector<std::shared_ptr<behavior_node>> get_children() override;
};

class literal : public behavior_leaf {
public:
	std::u32string contents;
	explicit literal(std::u32string contents);
	intermediate_nfa to_intermediate_nfa() const override;
	recognizer const & get_recognizer(builtins_t const & builtins, std::map<std::string, state_machine> const & productions, std::map<std::u32string, string_terminal> & literals) const override final;
	std::string get_id() const final;
};

class optional : public behavior_node {
public:
	virtual ~optional();

	std::shared_ptr<behavior_node> child;
	explicit optional(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const override;
	std::vector<std::shared_ptr<behavior_node>> get_children() override;
};

class production : public behavior_leaf {
public:
	std::string name;
	explicit production(std::string name);
	intermediate_nfa to_intermediate_nfa() const override;
	
	std::string get_id() const final;
	recognizer const & get_recognizer(builtins_t const & builtins, std::map<std::string, state_machine> const & productions, std::map<std::u32string, string_terminal> & literals) const override;
};

class repetition : public behavior_node {
public:
	virtual ~repetition();

	std::shared_ptr<behavior_node> child;
	explicit repetition(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const override;
	std::vector<std::shared_ptr<behavior_node>> get_children() override;
};

class sequence : public behavior_node {
public:
	virtual ~sequence();

	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const override;
	std::vector<std::shared_ptr<behavior_node>> get_children() override;
};

}
}

#endif //BEHAVIOR_HPP
