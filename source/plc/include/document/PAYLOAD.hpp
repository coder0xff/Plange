// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PAYLOAD_HPP
#define INCLUDED_PAYLOAD_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef parlex::details::document::built_in_terminal<parlex::details::all_t> PAYLOAD_base;

struct PAYLOAD: PAYLOAD_base {
	static PAYLOAD build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit PAYLOAD(PAYLOAD_base const & value) : PAYLOAD_base(value) {}
};
} // namespace plc



#endif //INCLUDED_PAYLOAD_HPP
