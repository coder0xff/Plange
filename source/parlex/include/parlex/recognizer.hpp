#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>

namespace parlex {

class recognizer;

namespace details {
	class subjob;

	class recognizer_reference_comparer {
	public:
		inline bool operator()(recognizer const & lhs, recognizer const & rhs) const { return &lhs < &rhs; }
	};
}

//base class for terminal and state_machine
class recognizer {
public:
	recognizer(std::string const & id);
	virtual ~recognizer() = default;
	virtual bool is_terminal() const;
	std::string const id;

	inline friend std::ostream& operator<<(std::ostream& os, const recognizer & r) { return os << r.id; };
};



}

#endif
