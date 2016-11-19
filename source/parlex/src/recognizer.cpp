#include "parlex/recognizer.hpp"

namespace parlex {

recognizer::recognizer(std::string const& id) : id(id) {}

bool recognizer::is_terminal() const { return false; }

bool details::recognizer_reference_comparer::operator()(std::reference_wrapper<recognizer const> const & lhs, std::reference_wrapper<recognizer const> const & rhs) const
{
	recognizer const * lhsPtr = &lhs.get();
	recognizer const * rhsPtr = &rhs.get();
	if (lhsPtr == rhsPtr) {
		return false;
	}
	if (!lhsPtr) {
		return true;
	}
	if (!rhsPtr) {
		return false;
	}
	return lhsPtr->id < rhsPtr->id;
}

std::ostream& operator<<(std::ostream& os, const recognizer & r) { return os << r.id; }

}