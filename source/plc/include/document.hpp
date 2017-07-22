#ifndef PLC_DOCUMENT_HPP
#define PLC_DOCUMENT_HPP

#include "parlex/details/grammar.hpp"

namespace plc {

#include "document/plange_grammar.hpp.inc"

parlex::details::grammar const & grammar();

}

#endif //PLC_DOCUMENT_HPP