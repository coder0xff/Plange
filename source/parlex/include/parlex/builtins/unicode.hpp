#ifndef UNICODE_HPP
#define UNICODE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
	namespace details {

#define  U32(name, condition) \
		class name##_t : public terminal { \
		public: \
			inline name##_t() : terminal(#name, 1) {} \
			bool test(std::u32string const& document, size_t documentPosition) const override final; \
		};

#include "parlex/unicode.inc"

#undef U32

	}

	namespace builtins {

#define U32(name, condition) \
		extern details::name##_t name;
		
#include "parlex/unicode.inc"

#undef U32

	}
}

#endif
