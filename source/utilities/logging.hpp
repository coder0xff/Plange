#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <string>
#include <sstream>
#include <thread>

#ifndef NDEBUG
#	define DBG(...) logging::log_impl("DBG", __FILE__, __LINE__, __VA_ARGS__)
#else
#   define DBG(...)
#endif

#define INF(...) logging::log_impl("INF", __FILE__, __LINE__, __VA_ARGS__)

namespace logging {

extern void log_enque(std::string const * const item);

//variadic stringify function
template<typename... Ts>
void stringify(std::stringstream & ss, Ts const & ...parameters);

template<typename T, typename... Us>
void stringify(std::stringstream & ss, const T & head, const Us & ...tail) {
	ss << head;
	stringify(ss, tail...);
}

template<>
void stringify(std::stringstream & ss);

template<typename... Ts>
void log_impl(char const * const cat, char const * const file, int line, Ts const & ...args) {
	std::stringstream ss;
	ss << cat << " t:" << std::this_thread::get_id() << " (" << file << ":" << line << "): ";
	stringify(ss, args...);
	ss << std::endl;
	log_enque(new std::string(ss.str()));
}

}

#endif
