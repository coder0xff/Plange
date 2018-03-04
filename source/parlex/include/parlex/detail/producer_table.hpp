#ifndef PRODUCER_TABLE_HPP
#define PRODUCER_TABLE_HPP

#include <map>
#include <memory>

#include "producer.hpp"

namespace parlex::detail {

	using producer_collection = std::map<match_class, producer *>;

}

#endif