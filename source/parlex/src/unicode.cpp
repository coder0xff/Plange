#include "parlex/detail/unicode.hpp"

#define U32(name, condition) \
bool parlex::detail::name##_t::test(std::u32string const& document, uint32_t documentPosition) const { \
	auto const & i = document[documentPosition]; \
	return condition; \
}

#include "parlex/detail/unicode.inc"
