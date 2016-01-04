#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>

namespace parlex {

class recognizer;

namespace details {
	class subjob;

	class recognizer_reference_comparer {
	public:
		inline bool operator()(recognizer const & lhs, recognizer const & rhs) { return &lhs < &rhs; }
	};
}

//base class for terminal and state_machine
class recognizer {
public:
	virtual ~recognizer() = default;
	inline virtual bool is_terminal() const { return false; }
	virtual std::string get_id() const = 0;

	inline friend std::ostream& operator<<(std::ostream& os, const recognizer & r) { return os << r.get_id(); };
};



}

#endif
