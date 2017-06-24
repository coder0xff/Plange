#ifndef UNICODE_HPP
#define UNICODE_HPP

#include "parlex/details/terminal.hpp"

namespace parlex {
namespace details {

#define  U32(name, condition) \
		class name##_t : public terminal { \
		public: \
			inline name##_t() : terminal(#name, 1) {} \
			bool test(std::u32string const& document, size_t documentPosition) const override final; \
		};

#include "parlex/details/unicode.inc"

#undef U32

} // namespace details
} // namespace parlex

#endif //UNICODE_HPP
