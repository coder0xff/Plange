#ifndef DOCUMENT_REPRESENTATION_HPP
#define DOCUMENT_REPRESENTATION_HPP

#include <map>

#include "builder.hpp"

namespace parlex {
namespace representation {

// simplify builder nodes into struct-like representations
void simplify(std::list<builder::production> const & productions);

} // namespace representation
} // namespace parlex

#endif //DOCUMENT_REPRESENTATION_HPP
