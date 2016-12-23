#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>

namespace parlex {

class recognizer;

namespace details {
	class subjob;

	class recognizer_reference_comparer {
	public:
		bool operator()(std::reference_wrapper<recognizer const> const & lhs, std::reference_wrapper<recognizer const> const & rhs) const;
	};
}

//base class for terminal and state_machine
class recognizer {
public:
	recognizer(std::string const & id);
	virtual ~recognizer() = default;
	virtual bool is_terminal() const;
	std::string const id;

	friend std::ostream& operator<<(std::ostream& os, const recognizer & r);
};



}

#endif
