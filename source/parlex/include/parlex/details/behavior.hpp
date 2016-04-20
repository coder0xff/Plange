#include <memory>
#include <string>

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

class behavior_node {
public:
	virtual intermediate_nfa to_intermediate_nfa() const = 0;
};

class behavior_leaf : public behavior_node, public std::enable_shared_from_this<behavior_leaf> {
public:
	virtual recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::vector<builtins::string_terminal> & literals, std::map<std::u32string, int> literals_map) const = 0;
};

class choice : public behavior_node {
public:
	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const;
};

class literal : public behavior_leaf {
public:
	std::u32string contents;
	literal(std::u32string contents);
	intermediate_nfa to_intermediate_nfa() const;
	recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::vector<builtins::string_terminal> & literals, std::map<std::u32string, int> literals_map) const;
};

class optional : public behavior_node {
public:
	std::shared_ptr<behavior_node> child;
	optional(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const;
};

class production : public behavior_leaf {
public:
	std::string name;
	production(std::string name);
	intermediate_nfa to_intermediate_nfa() const;
	recognizer const & get_recognizer(std::map<std::string, state_machine> const & productions, std::vector<builtins::string_terminal> & literals, std::map<std::u32string, int> literals_map) const;
};

class repetition : public behavior_node {
public:
	std::shared_ptr<behavior_node> child;
	repetition(std::shared_ptr<behavior_node> && child);
	intermediate_nfa to_intermediate_nfa() const;
};

class sequence : public behavior_node {
public:
	std::vector<std::shared_ptr<behavior_node>> children;
	intermediate_nfa to_intermediate_nfa() const;
};

std::map<std::string, nfa<std::shared_ptr<recognizer>, int>> to_nfas(std::map<std::string, std::shared_ptr<behavior_node>> const & trees);

}
}
