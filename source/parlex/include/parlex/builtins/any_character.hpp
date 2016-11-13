#ifndef ANY_CHARACTER_HPP
#define ANY_CHARACTER_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class any_character_t : public terminal {
public:
	any_character_t();
	virtual ~any_character_t() = default;
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;
	virtual size_t get_length() const final;
};

}

namespace builtins {
	extern details::any_character_t any_character;
}

}


#endif
