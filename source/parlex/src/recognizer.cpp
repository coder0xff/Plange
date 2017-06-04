#include "parlex/recognizer.hpp"

#include <functional>

#include "utils.hpp"

namespace parlex {

recognizer::recognizer(std::string const& id) : id(id) {}

bool recognizer::is_terminal() const { return false; }

bool details::recognizer_reference_comparer::operator()(std::reference_wrapper<recognizer const> const & lhs, std::reference_wrapper<recognizer const> const & rhs) const
{
	recognizer const * lhsPtr = &lhs.get();
	throw_assert(lhsPtr);
	recognizer const * rhsPtr = &rhs.get();
	throw_assert(rhsPtr);
	return lhsPtr < rhsPtr;
}

std::ostream& operator<<(std::ostream& os, const recognizer & r) { return os << r.id; }

}
