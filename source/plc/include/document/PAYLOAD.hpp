// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PAYLOAD_HPP
#define INCLUDED_PAYLOAD_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef parlex::detail::document::built_in_terminal<parlex::detail::all_t> PAYLOAD_base;

struct PAYLOAD: PAYLOAD_base {
	static PAYLOAD build(std::u32string const & document, parlex::detail::ast_node const & n);
	explicit PAYLOAD(PAYLOAD_base const & value) : PAYLOAD_base(value) {}
};
} // namespace plc



#endif //INCLUDED_PAYLOAD_HPP
