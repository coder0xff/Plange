#include "visibility.hpp"

#include "grammar.hpp"

namespace plc {

visibility visibility_from_ast(VISIBILITY_MODIFIER const & value) {
	struct visitor {
		visibility operator()(parlex::detail::document::text<literal_public_t>) const {
			return visibility::PUBLIC;
		}
	
		visibility operator()(parlex::detail::document::text<literal_protected_t>) const {
			return visibility::PROTECTED;
		}
	
		visibility operator()(parlex::detail::document::text<literal_protected0x20internal_t>) const {
			return visibility::PROTECTED_INTERNAL;
		}
	
		visibility operator()(parlex::detail::document::text<literal_internal_t>) const {
			return visibility::INTERNAL;
		}
	
		visibility operator()(parlex::detail::document::text<literal_private_t>) const {
			return visibility::PRIVATE;
		}
	};

	VISIBILITY_MODIFIER_base const & base = value;
	return std::visit(visitor(), base);
}

}
