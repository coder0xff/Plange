#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <sstream>
#include <thread>

// When RELEASE_LOGGING is defined, INF and DBG, macros will produce logging output code
//#define RELEASE_LOGGING

#ifdef RELEASE_LOGGING
#   define LOGGING_AVAILABLE 1
#else
#	ifndef NDEBUG
#       define LOGGING_AVAILABLE 1
#	endif
#endif

#ifdef LOGGING_AVAILABLE
#	define INF(...) logging::log_impl("INF", __FILE__, __LINE__, __VA_ARGS__)
#	define DBG(...) logging::log_impl("DBG", __FILE__, __LINE__, __VA_ARGS__)
#else
#	define INF(...)
#	define DBG(...)
#endif


namespace logging {

extern void log_enque(std::string const * const item);

void stringify(std::stringstream & ss);

//variadic stringify function
template<typename T, typename... Us>
void stringify(std::stringstream & ss, const T & head, const Us & ...tail) {
	ss << head;
	stringify(ss, tail...);
}

template<typename... Ts>
void log_impl(char const * const cat, char const * const file, int const line, Ts const & ...args) {
	std::stringstream ss;
	ss << cat << " t:" << std::this_thread::get_id() << " (" << file << ":" << line << "): ";
	stringify(ss, args...);
	ss << std::endl;
	log_enque(new std::string(ss.str()));
}

}

#endif
