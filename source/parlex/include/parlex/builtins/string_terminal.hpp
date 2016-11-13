#ifndef STRING_TERMINAL_HPP
#define STRING_TERMINAL_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace builtins {

	class string_terminal : public terminal {
	public:
		string_terminal(std::u32string const & s);
		virtual ~string_terminal() = default;
		bool test(std::u32string const & document, size_t documentPosition) const override final;
		size_t get_length() const override final;
		virtual std::string get_id() const final;
		std::u32string get_content() const;
	private:
		std::u32string const s;
		int const length;
		std::string const id;
	};

}
}

#endif
