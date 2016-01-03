#ifndef PARSER_HPP
#define PARSER_HPP

#include <thread>
#include <condition_variable>
#include <atomic>
#include <queue>

#include "parlex/abstract_syntax_graph.hpp"
#include "grammar.hpp"

namespace parlex {
namespace details {

class job;
class subjob;
class producer;
class context_ref;

}

class parser {
public:
	parser(int thread_count = std::thread::hardware_concurrency());
	~parser();
	abstract_syntax_graph parse(recognizer const & g, std::u32string const & document);
private:
	friend class details::job;
	friend class details::subjob;
	friend class details::producer;
	std::mutex mutex;
	std::condition_variable halt_cv;
	std::atomic<int> activeCount;
	bool terminating;

	std::vector<std::thread> workers;
	std::queue<std::tuple<details::context_ref, int>> work;
	std::condition_variable work_cv;

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
	bool handle_deadlocks(details::job const & j);

	//Construct an ASG, and if a solution was found, prunes unreachable nodes
	abstract_syntax_graph construct_result(details::job const & j, match const & match);
};

}

#endif
