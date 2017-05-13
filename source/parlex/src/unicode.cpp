#include "parlex/builtins/unicode.hpp"

#define U32(name, condition) \
bool parlex::details::name##_t::test(std::u32string const& document, size_t documentPosition) const { \
	auto const & i = document[documentPosition]; \
	return condition; \
}

#include "parlex/unicode.inc"
