#ifndef PARSER_HPP
#define PARSER_HPP

#include <thread>
#include <condition_variable>
#include <atomic>
#include <queue>

#include "parlex/abstract_syntax_graph.hpp"
#include "parlex/post_processor.hpp"

#include "parlex/details/context.hpp"

#include "builtins.hpp"

namespace parlex {
class grammar_base;

namespace details {

class context_ref;
class job;
class producer;
class subjob;

}

class correlated_grammar;
class recognizer;

class parser {
public:
	void start_workers(int threadCount);
	parser(int threadCount = std::thread::hardware_concurrency());
	~parser();
	static abstract_syntax_graph construct_result_and_postprocess(recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document, details::job const & j);
	void complete_progress_handler(std::u32string const & document) const;
	abstract_syntax_graph single_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document);
	abstract_syntax_graph multi_thread_parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document);
	abstract_syntax_graph parse(grammar_base const & g, recognizer const & overrideMain, std::vector<post_processor> posts, std::u32string const & document);
	abstract_syntax_graph parse(grammar_base const & g, recognizer const & overrideMain, std::u32string const & document);
	abstract_syntax_graph parse(grammar_base const & g, std::vector<post_processor> posts, std::u32string const & document);
	abstract_syntax_graph parse(grammar_base const & g, std::u32string const & document);
	void set_update_progress_handler(std::function<void(int /*done*/, int /*total*/)>);
	builtins_t builtins;
private:
	friend class details::job;
	friend class details::subjob;
	friend class details::producer;
	mutable std::mutex mutex;
	std::condition_variable halt_cv;
	std::atomic<int> activeCount;
	bool terminating;

	std::vector<std::thread> workers;
	std::queue<std::tuple<details::context_ref, int>> work;
	std::condition_variable work_cv;
	std::function<void(int, int)> update_progress_handler;

	void schedule(details::context_ref const & c, int nextDfaState);

	//returns true if the job is complete
	//"Deadlock" has a negative connotation, which is not appropriate here.
	//Grammars with left recursion cause them to arise, and this "solves" them. It's a feature.
	//We detect their existence by watching for stalls in the parser loop;
	//no work is being done by the worker threads. To solve, we suspend further progress,
	//compile a listing of blocked subjobs via a dependency digraph, sequentially
	//halt the subjobs, and then resume. If stalling occurs and there
	//are no deadlocks in the dependency digraph (implying that it is also disconnected) then there is
	//no more work to be done. The job is finished.
	bool handle_deadlocks(details::job const & j) const;
};

} // namespace parlex

#endif //PARSER_HPP
