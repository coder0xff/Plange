#ifndef INCLUDED_PLC_VISIBILITY_HPP
#define INCLUDED_PLC_VISIBILITY_HPP

namespace plc {

	enum class visibility {
		PUBLIC,
		PROTECTED,
		PROTECTED_INTERNAL,
		INTERNAL,
		PRIVATE
	};

	// ReSharper disable once CppInconsistentNaming
	struct VISIBILITY_MODIFIER;

	visibility visibility_from_ast(VISIBILITY_MODIFIER const &);
}

#endif