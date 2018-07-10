#ifndef INCLUDED_UTILITIES_PERF_TIMER_HPP
#define INCLUDED_UTILITIES_PERF_TIMER_HPP

#include <chrono>
#include <string>

class perf_timer {
public:
	explicit perf_timer(std::string const & name);
	~perf_timer();
private:
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::string name;
	perf_timer(perf_timer const & other) = delete;
	perf_timer(perf_timer &&other) = delete;
	perf_timer const & operator =(perf_timer const & lhs) = delete;
};

#endif // INCLUDED_UTILITIES_PERF_TIMER_HPP
