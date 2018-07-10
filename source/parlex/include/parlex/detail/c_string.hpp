#ifndef INCLUDED_PARLEX_C_STRING_HPP
#define INCLUDED_PARLEX_C_STRING_HPP

#include "parlex/builder.hpp"
#include "parlex/detail/abstract_syntax_semilattice.hpp"

namespace parlex {
namespace detail {

class c_string_t const & c_string();

class grammar;

class c_string_t : public sub_builder {
public:
	static std::u32string extract(grammar const & g, std::u32string const & document, ast_node const & n);
	static std::u32string extract(grammar const & g, std::u32string const & document, match const & m, abstract_syntax_semilattice const & asg);
private:
	friend c_string_t const & c_string();
	c_string_t();
	static void extract_step(std::u32string const & document, std::u32string * result, grammar const & g, size_t const recognizerIndex, size_t const documentPosition, size_t const consumedCharacterCount);
};


}

}

#endif // INCLUDED_PARLEX_C_STRING_HPP
