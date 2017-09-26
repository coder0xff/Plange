// This file was generated using Parlex's cpp_generator

#include "CASTS.hpp"
#include "DOWNCASTS.hpp"
#include "EXACTLY.hpp"
#include "IMPLEMENTS.hpp"
#include "INEQUALITY.hpp"
#include "INHERITS.hpp"
#include "IS.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "UPCASTS.hpp"
#include "RELATIONAL_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<RELATIONAL_OP> RELATIONAL_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<RELATIONAL_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<RELATIONAL_OP>(value.value());
	}
	return std::optional<RELATIONAL_OP>();
}

} // namespace plc
