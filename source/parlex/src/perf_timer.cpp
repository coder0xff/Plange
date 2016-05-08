#include "parlex/details/perf_timer.hpp"
#include "parlex/details/logging.hpp"

perf_timer::perf_timer(std::string const & name) : start(std::chrono::steady_clock::now()), name(name) {
	DBG("Started timing: ", name);
}

perf_timer::~perf_timer() {
	DBG("Finished timing: ", name, " ", std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count(), "ms");
}