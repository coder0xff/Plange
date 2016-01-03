#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>

#include "parlex/recognizer.hpp"

namespace parlex {
namespace details {
	class job;
	class token;
}

class terminal : public recognizer {
public:
	virtual ~terminal() = default;

	virtual bool test(std::u32string const & document, size_t documentPosition) const = 0;
	virtual size_t get_length() const = 0;
	inline bool is_terminal() const final { return true; }
protected:
	inline terminal() {}
private:
};

}

#endif
