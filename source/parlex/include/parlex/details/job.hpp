#ifndef JOB_H
#define JOB_H

#include <string>

#include "match_class.hpp"
#include "subjob.hpp"
#include "abstract_syntax_graph.hpp"

namespace parlex {

class parser;
class state_machine;

namespace details {

//holds the state of the parser during a parse
//making it a type makes it easy for the parser to reset its state
class job {
public:
	std::u32string const document;
	recognizer const & main;
	std::map<match_class, std::unique_ptr<producer>> producers;
	std::mutex producers_mutex;

	job(parser & owner, std::u32string const & document, recognizer const & main);
	void connect(match_class const & matchClass, context_ref const & c, int nextState);
private:
	producer & get_producer(match_class const & matchClass);
	parser & owner;
	friend class producer;
};

}
}

#endif
