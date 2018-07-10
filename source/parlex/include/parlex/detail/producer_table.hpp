#ifndef INCLUDED_PARLEX_PRODUCER_TABLE_HPP
#define INCLUDED_PARLEX_PRODUCER_TABLE_HPP

#include <map>
#include <memory>

#include "parlex/detail/producer.hpp"

namespace parlex::detail {

	using producer_collection = std::map<match_class, producer *>;

}

#endif // INCLUDED_PARLEX_PRODUCER_TABLE_HPP
