#ifndef CONTENT_HPP
#define CONTENT_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex::detail {

class content_t : public terminal {
public:
	content_t();
	bool test(std::u32string const & document, uint32_t documentPosition) const override final;
};

}

#endif //CONTENT_HPP