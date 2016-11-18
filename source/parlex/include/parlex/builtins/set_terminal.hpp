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
		size_t get_length() const override final;
		virtual std::string get_id() const final;
	private:
		std::set<char32_t> const s;
		std::string const id;
	};

}
}

#endif
