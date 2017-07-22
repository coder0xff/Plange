#ifndef PARSER_HPP
#define PARSER_HPP

#include <thread>
#include <condition_variable>
#include <atomic>
#include <queue>

#include "parlex/details/abstract_syntax_graph.hpp"
#include "parlex/post_processor.hpp"
#include "erased.hpp"

namespace parlex {
namespace details {

class grammar_base;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;
class context_ref;
class job;
class producer;
class subjob;

class parser {
public:
	parser(unsigned threadCount = std::thread::hardware_concurrency());
	~parser();
	abstract_syntax_graph parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler = progress_handler_t());
	abstract_syntax_graph parse(grammar_base const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t progressHandler = progress_handler_t());
	abstract_syntax_graph parse(grammar_base const & g, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler = progress_handler_t());
	abstract_syntax_graph parse(grammar_base const & g, std::u32string const & document, progress_handler_t progressHandler = progress_handler_t());
private:
	friend class job;
	friend class subjob;
	friend class producer;
	bool const single_thread_mode;
	mutable std::mutex mutex;
	std::condition_variable halt_cv;
	std::atomic<int> activeCount;
	bool terminating;

	std::vector<std::thread> workers;
	std::queue<std::tuple<erased<context_ref>, int>> work;
	std::condition_variable work_cv;

	void start_workers(int threadCount);
	static abstract_syntax_graph construct_result(job const & j, fast_match const & m);
	static abstract_syntax_graph construct_result_and_postprocess(recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, job const & j);
	static void complete_progress_handler(job & j);
	static void update_progress(context_ref const & context);
	std::tuple<erased<context_ref>, int> get_work_item();
	abstract_syntax_graph single_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler);
	abstract_syntax_graph multi_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, progress_handler_t progressHandler);
	void schedule(context_ref const & c, int nextDfaState);

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

} // namespace details
} // namespace parlex

#endif //PARSER_HPP
