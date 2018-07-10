#ifndef INCLUDED_PARLEX_RECOGNIZER_HPP
#define INCLUDED_PARLEX_RECOGNIZER_HPP

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

#endif // INCLUDED_PARLEX_RECOGNIZER_HPP
