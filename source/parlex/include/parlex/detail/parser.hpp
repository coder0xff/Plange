#ifndef PARSER_HPP
#define PARSER_HPP

#include <thread>
#include <condition_variable>
#include <atomic>
#include <queue>

#include "coherent_queue.hpp"

#include "parlex/post_processor.hpp"
#include "parlex/detail/abstract_syntax_semilattice.hpp"
#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class context;
class grammar;
class job;
class producer;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;
class recognizer;
class subjob;

class parser {
public:
	explicit parser(unsigned threadCount = std::thread::hardware_concurrency());
	~parser();
	abstract_syntax_semilattice parse(grammar const & g, recognizer const & overrideMain, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar const & g, recognizer const & overrideMain, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar const & g, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
	abstract_syntax_semilattice parse(grammar const & g, std::u32string const & document, progress_handler_t const & progressHandler = progress_handler_t());
private:
	struct work_item {
		work_item(uint32_t const producerId, context const * const dfaContext, uint8_t const dfaState)
			: producer_id(producerId),
			dfa_context(dfaContext),
			dfa_state(dfaState) {}

		uint32_t const producer_id;
		context const * const dfa_context;
		uint8_t const dfa_state;
	};
	
	friend class job;
	friend class subjob;
	friend class producer;

	bool const single_thread_mode;
	mutable std::mutex mutex;
	std::condition_variable halt_cv;
	std::atomic<size_t> active_count;
	bool terminating;
	std::vector<std::thread> workers;
	std::vector<work_item> work;
	std::condition_variable work_cv;
	job * current_job;

	static void apply_precedence_and_associativity(grammar const & g, abstract_syntax_semilattice & asg);
	static void complete_progress_handler(job & j);

	void process(work_item const & item) const;
	void start_workers(int threadCount);
	abstract_syntax_semilattice single_thread_parse(grammar const & g, uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler);
	abstract_syntax_semilattice multi_thread_parse(grammar const & g, uint16_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document, progress_handler_t const & progressHandler);
	void schedule(uint32_t const producerId, context const & c, int nextDfaState);
	void update_progress(context const & context) const;
};

} // namespace detail
} // namespace parlex

#endif //PARSER_HPP
