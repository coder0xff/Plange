#ifndef PARSER_HPP
#define PARSER_HPP

#include <thread>
#include <condition_variable>
#include <atomic>
#include <queue>

#include "parlex/detail/abstract_syntax_semilattice.hpp"
#include "parlex/post_processor.hpp"
#include "coherent_queue.hpp"

namespace parlex {
namespace detail {

class grammar_base;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;
class context;
class job;
class producer;
class subjob;

class parser {
public:
	explicit parser(unsigned threadCount = std::thread::hardware_concurrency());
	~parser();
	abstract_syntax_semilattice parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar_base const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar_base const & g, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar_base const & g, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
private:
	friend class job;
	friend class subjob;
	friend class producer;

	bool const single_thread_mode;
	mutable std::mutex mutex;
	std::condition_variable halt_cv;
	std::atomic<int> active_count;
	bool terminating;
	std::vector<std::thread> workers;
	std::vector<std::tuple<context const*, int>> work;
	std::condition_variable work_cv;

	static void complete_progress_handler(job & j);
	static void update_progress(context const & context);
	static void apply_precedence_and_associativity(grammar_base const & g, abstract_syntax_semilattice & asg);
	void start_workers(int threadCount);
	abstract_syntax_semilattice single_thread_parse(grammar_base const & g, size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t progressHandler);
	abstract_syntax_semilattice multi_thread_parse(grammar_base const & g, size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t progressHandler);
	void schedule(context const & c, int nextDfaState);
};

} // namespace detail
} // namespace parlex

#endif //PARSER_HPP
