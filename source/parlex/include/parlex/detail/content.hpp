#ifndef INCLUDED_PARLEX_CONTENT_HPP
#define INCLUDED_PARLEX_CONTENT_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex::detail {

class content_t : public terminal {
public:
	content_t();
	bool test(std::u32string const & document, uint32_t documentPosition) const override final;
};

}

#endif // INCLUDED_PARLEX_CONTENT_HPP