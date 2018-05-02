#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>

namespace parlex {
namespace detail {



//base class for terminal and acceptor
class recognizer {
public:
	explicit recognizer(std::string const & name);
	virtual ~recognizer() = default;
	virtual bool is_terminal() const;
	std::string const name;

	friend std::ostream& operator<<(std::ostream & os, const recognizer & r);
};

} // namespace detail
} // namespace parlex

#endif //RECOGNIZER_HPP
