#ifndef SET_TERMINAL_HPP
#define SET_TERMINAL_HPP

#include <set>
#include <string>

namespace parlex {
namespace builtins {
	
	class set_terminal : public terminal {
	public:
		set_terminal(std::set<char32_t> const & s, std::string id);
		virtual ~set_terminal() = default;
		bool test(std::u32string const & document, size_t documentPosition) const override final;
	private:
		std::set<char32_t> const s;
	};

}
}

#endif
