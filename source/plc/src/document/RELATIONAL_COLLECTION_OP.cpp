// This file was generated using Parlex's cpp_generator

#include "HAS.hpp"
#include "IN.hpp"
#include "NOT_HAS.hpp"
#include "NOT_IN.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<RELATIONAL_COLLECTION_OP> RELATIONAL_COLLECTION_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<RELATIONAL_COLLECTION_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<RELATIONAL_COLLECTION_OP>(value.value());
	}
	return std::optional<RELATIONAL_COLLECTION_OP>();
}

} // namespace plc
