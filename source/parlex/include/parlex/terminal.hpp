#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>

#include "recognizer.hpp"

namespace parlex {
namespace details {
	class job;
	class token;
}

class terminal : public recognizer {
public:
	virtual ~terminal() = default;

	virtual bool test(std::u32string const & document, int documentPosition) const = 0;
	virtual int get_length() const = 0;
	inline bool is_terminal() const final { return true; }
protected:
	inline terminal() {}
private:
};

}

#endif
