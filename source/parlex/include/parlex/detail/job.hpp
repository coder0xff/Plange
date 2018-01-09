#ifndef JOB_HPP
#define JOB_HPP

#include <functional>

#include "parlex/post_processor.hpp"

#include "parlex/detail/abstract_syntax_semilattice.hpp"
#include "parlex/detail/producer_table.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

class correlated_grammar;
class grammar_base;
struct match_class;
class parser;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;
class raw_state_machine;


//holds the state of the parser during a parse
//making it a type makes it easy for the parser to reset its state
class job {
public:
	std::u32string const document;
	grammar_base const & g;
	std::atomic<int> progress;

	job(parser & owner, std::u32string const & document, grammar_base const & g, size_t const rootRecognizerIndex, progress_handler_t const & progressHandler);

	void connect(match_class const & matchClass, producer_id_t const subscriber, context const & c, size_t const nextState, leaf const * l);
	match_class get_match_class(producer_id_t const id) const; 
private:
	parser * owner;
	std::unique_ptr<producer_table> producer_table_ptr;
	progress_handler_t progress_handler;
	std::atomic<size_t> progress_counter;

	producer & optimized_get_producer(producer_id_t const & id, match_class const & matchClass);
	producer & get_producer(match_class const & matchClass);
	producer & get_producer(producer_id_t const & id);
	void update_progress(size_t completed);

	//returns true if the job is complete
	//"Deadlock" has a negative connotation, which is not appropriate here.
	//Grammars with left recursion cause them to arise, and this "solves" them. It's a feature.
	//We detect their existence by watching for stalls in the parser loop;
	//no work is being done by the worker threads. To solve, we suspend further progress,
	//compile a listing of blocked subjobs via a dependency digraph, sequentially
	//halt the subjobs, and then resume. If stalling occurs and there
	//are no deadlocks in the dependency digraph (implying that it is also disconnected) then there is
	//no more work to be done. The job is finished.
	bool handle_deadlocks();
	abstract_syntax_semilattice construct_result(match const & m);
	abstract_syntax_semilattice construct_result_and_postprocess(size_t const overrideRootRecognizerIndex, std::vector<post_processor> const & posts, std::u32string const & document);

	friend class parser;
	friend class producer;
};

} // namespace detail
} // namespace parlex

#endif //JOB_HPP
