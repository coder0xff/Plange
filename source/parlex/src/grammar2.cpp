#include "parlex/grammar2.hpp"
#include "parlex/builtins.hpp"

namespace parlex {

grammar2::production::production(std::string const & id, erased<behavior2::node> const & behavior, filter_function const & filter, associativity assoc) : behavior(behavior), state_machine(id, behavior2::compile(behavior), filter, assoc) {
}

grammar2::production::production(std::string const & id, erased<behavior2::node> const & behavior, associativity assoc) : production(id, behavior, filter_function(), assoc) {
}

grammar2::grammar2(builtins_t const & builtins, std::string const & mainProductionName) : builtins(builtins), main_production_name(mainProductionName) {
}

state_machine_base2 const& grammar2::get_main_production() const {
	auto i = productions.find(main_production_name);
	throw_assert(i != productions.end());
	return i->second.state_machine;
}

builtins_t::string_terminal& grammar2::get_or_add_literal(std::u32string const & contents) {
	auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
	return result.first->second;
}

}
