#include "parlex/builder.hpp"
#include "utf.hpp"

namespace parlex {
namespace builder {

node::node(std::initializer_list<erased<node>> const & children) : children(children) {
}

node::node(std::string const & tag, std::initializer_list<erased<node>> const & children) : tag(tag), children(children) {
}

node::node(std::initializer_list<erased<node>> && children) : children(move(children)) {
}

node::node(std::string && tag, std::initializer_list<erased<node>> && children) : tag(move(tag)), children(move(children)) {
}

literal_t::literal_t(std::u32string const & content) : id(to_utf8(content)), content(content) {
}

literal_t::literal_t(std::string const & tag, std::u32string const & content) : node(tag, {}), id(to_utf8(content)), content(content) {
}

literal_t::literal_t(std::u32string && content) : id(to_utf8(content)), content(move(content)) {
}

literal_t::literal_t(std::string && tag, std::u32string && content) : node(move(tag), {}), id(to_utf8(content)), content(move(content)) {
}

erased<node> literal(std::u32string const & content) { return erased<node>(literal_t(content)); }

erased<node> literal(std::string const & tag, std::u32string const & content) { return erased<node>(literal_t(tag, content)); }

erased<node> literal(std::u32string && content) { return erased<node>(literal_t(move(content))); }

erased<node> literal(std::string && tag, std::u32string && content) { return erased<node>(literal_t(move(tag), move(content))); }


reference_t::reference_t(std::string const & id) : id(id) {
}

reference_t::reference_t(std::string const & tag, std::string const & id) : node(tag, {}), id(id) {
}

reference_t::reference_t(std::string && id) : id(move(id)) {
}

reference_t::reference_t(std::string && tag, std::string && id) : node(move(tag), {}), id(move(id)) {
}

erased<node> reference(std::string const & id) { return erased<node>(reference_t(id)); }

erased<node> reference(std::string const & tag, std::string const & id) { return erased<node>(reference_t(tag, id)); }

erased<node> reference(std::string && id) { return erased<node>(reference_t(move(id))); }

erased<node> reference(std::string && tag, std::string && id) { return erased<node>(reference_t(move(tag), move(id))); }

production::production(std::string const & id, erased<node> const & behavior, associativity assoc /*= associativity::none*/, filter_function const & filter /*= filter_function()*/, std::set<std::string> const & precedences /*= set<string>() */) : id(id), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
}

grammar::grammar(std::string rootId, std::list<production> const & productions) : root_id(rootId), productions(move(productions)) {
}

} // namespace builder
} // namespace parlex
