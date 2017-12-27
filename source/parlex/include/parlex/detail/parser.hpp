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

	void start_workers(int threadCount);
	static abstract_syntax_semilattice construct_result(job & j, match const & m);
	static abstract_syntax_semilattice construct_result_and_postprocess(size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, job & j);
	static void complete_progress_handler(job & j);
	static void update_progress(context const & context);
	abstract_syntax_semilattice single_thread_parse(grammar_base const & g, size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t progressHandler);
	abstract_syntax_semilattice multi_thread_parse(grammar_base const & g, size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t progressHandler);
	void schedule(context const & c, int nextDfaState);

	//returns true if the job is complete
	//"Deadlock" has a negative connotation, which is not appropriate here.
	//Grammars with left recursion cause them to arise, and this "solves" them. It's a feature.
	//We detect their existence by watching for stalls in the parser loop;
	//no work is being done by the worker threads. To solve, we suspend further progress,
	//compile a listing of blocked subjobs via a dependency digraph, sequentially
	//halt the subjobs, and then resume. If stalling occurs and there
	//are no deadlocks in the dependency digraph (implying that it is also disconnected) then there is
	//no more work to be done. The job is finished.
	bool handle_deadlocks(job const & j) const;
};

} // namespace detail
} // namespace parlex

#endif //PARSER_HPP
