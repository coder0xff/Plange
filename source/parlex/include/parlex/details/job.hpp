#ifndef JOB_HPP
#define JOB_HPP

#include <functional>

#include "parlex/details/match_class.hpp"
#include "parlex/details/subjob.hpp"
#include "parlex/details/abstract_syntax_semilattice.hpp"

namespace parlex {
namespace details {

class correlated_grammar;
class parser;
class raw_state_machine;
class grammar_base;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;

//holds the state of the parser during a parse
//making it a type makes it easy for the parser to reset its state
class job {
public:
	std::u32string const document;
	grammar_base const & g;
	recognizer const & main;
	std::map<match_class, std::unique_ptr<producer>> producers;
	mutable std::mutex producers_mutex;
	std::atomic<int> progress;

	job(parser & owner, std::u32string const & document, grammar_base const & g, recognizer const & main, progress_handler_t progressHandler);
	void connect(match_class const & matchClass, context const & c, int nextState, behavior::leaf const * leaf);
private:
	parser & owner;
	progress_handler_t progress_handler;
	std::atomic<size_t> progress_counter;

	producer& get_producer(match_class const & matchClass);
	void update_progress(size_t completed);

	friend class parser;
	friend class producer;
};

} // namespace details
} // namespace parlex

#endif //JOB_HPP
