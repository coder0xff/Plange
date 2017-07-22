// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RELATIONAL_COLLECTION_OP_HPP
#define INCLUDED_RELATIONAL_COLLECTION_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct HAS;
struct IN;
struct NOT_HAS;
struct NOT_IN;

typedef std::variant<
	erased<HAS>,
	erased<IN>,
	erased<NOT_HAS>,
	erased<NOT_IN>
> RELATIONAL_COLLECTION_OP;

#endif //INCLUDED_RELATIONAL_COLLECTION_OP_HPP
