#ifndef JOB_HPP
#define JOB_HPP

#include "parlex/match_class.hpp"
#include "parlex/details/subjob.hpp"
#include "parlex/abstract_syntax_graph.hpp"

namespace parlex {

class correlated_grammar;
class parser;
class state_machine;
class grammar_base;

namespace details {

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

	job(parser & owner, std::u32string const & document, grammar_base const & g, recognizer const & main);
	void connect(match_class const & matchClass, context_ref const & c, int nextState, behavior::leaf const * leaf);
private:
	producer& get_producer(match_class const & matchClass);
	parser & owner;
	friend class producer;
};

} // namespace details
} // namespace parlex

#endif //JOB_HPP
