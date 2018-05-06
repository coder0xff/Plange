#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <optional>
#include <vector>

#include "parlex/builder.hpp"
#include "parlex/detail/derivation.hpp"

namespace parlex {
namespace detail {

class subjob;

//the parse configuration for some acceptor's state during one of its executions
class configuration {
public:
	configuration const* const prior;
	uint32_t const current_document_position;
	std::optional<match> const from_transition;
	leaf const * const l;

	configuration(configuration const * const prior, uint32_t documentPosition, std::optional<match> const & fromTransition, leaf const * l);
	configuration(configuration const & other) = delete;
	configuration(configuration && move) = delete;
	~configuration();

	derivation result() const;
};

}
}

#endif
