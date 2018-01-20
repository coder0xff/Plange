#ifndef UNICODE_HPP
#define UNICODE_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

#define  U32(name, condition) \
		class name##_t : public terminal { \
		public: \
			inline name##_t() : terminal(#name, 1) {} \
			bool test(std::u32string const& document, uint32_t documentPosition) const override final; \
		};

#include "parlex/detail/unicode.inc"

#undef U32

} // namespace detail
} // namespace parlex

#endif //UNICODE_HPP
