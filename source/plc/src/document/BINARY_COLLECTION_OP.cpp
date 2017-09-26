// This file was generated using Parlex's cpp_generator

#include "BIJECTION.hpp"
#include "INTERSECTION.hpp"
#include "SYMMETRIC_DIFFERENCE.hpp"
#include "UNION.hpp"
#include "BINARY_COLLECTION_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BINARY_COLLECTION_OP> BINARY_COLLECTION_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BINARY_COLLECTION_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BINARY_COLLECTION_OP>(value.value());
	}
	return std::optional<BINARY_COLLECTION_OP>();
}

} // namespace plc
