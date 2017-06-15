#ifndef GRAMMAR_DEFINITION_HPP
#define GRAMMAR_DEFINITION_HPP

#include <vector>

#include "erased.hpp"
#include "associativity.hpp"
#include "filter_function.hpp"

namespace parlex {

struct grammar_definition {
	struct node {
		virtual ~node() = default;
		typedef std::vector<erased<node>> children_t;
		std::string tag;
		children_t children;
	};

	struct literal final : node {
		explicit literal(std::u32string const & content) : id(to_utf8(content)), content(content) {}
		std::string const id;
		std::u32string const content;
	};

	struct production final : node {
		explicit production(std::string const & id) : id(id) {}
		std::string const id;
	};

	struct choice final : node {
	};

	struct optional final : node {
	};

	struct repetition final : node {
	};

	struct sequence final : node {
	};

	struct definition {
		std::string id;
		erased<node> behavior;
		filter_function filter;
		associativity assoc;
		std::set<std::string> precedences;
	};

	std::string root_id;
	std::list<definition> productions;
};

} // namespace parlex

#endif //GRAMMAR_DEFINITION_HPP
