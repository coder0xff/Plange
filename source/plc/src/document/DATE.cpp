// This file was generated using Parlex's cpp_generator

#include "DATE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DATE_YEAR_DAY.hpp"
#include "DATE_YEAR_MONTH_DAY.hpp"
#include "DATE.hpp"

namespace plc {

DATE DATE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return DATE(parlex::details::document::element<DATE_base>::build(b, n));
}

} // namespace plc
