#ifndef INCLUDED_PARLEX_ASSOCIATIVITY_H
#define INCLUDED_PARLEX_ASSOCIATIVITY_H

namespace parlex {

enum class associativity {
	NONE,
	ANY,
	LEFT,
	RIGHT
};

} // namespace parlex

#endif // INCLUDED_PARLEX_ASSOCIATIVITY_H
