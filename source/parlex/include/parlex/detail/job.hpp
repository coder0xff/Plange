#ifndef JOB_HPP
#define JOB_HPP

#include <functional>

#include "parlex/detail/match_class.hpp"
#include "parlex/detail/subjob.hpp"
#include "parlex/detail/abstract_syntax_semilattice.hpp"

namespace parlex {
namespace detail {

class correlated_grammar;
class parser;
class raw_state_machine;
class grammar_base;
typedef std::function<void(size_t /*done*/, size_t /*total*/)> progress_handler_t;

class producer_table {
public:
	typedef std::unique_ptr<producer> t;

	size_t const document_length;
	size_t const recognizer_count;

private:
	t * const storage;
	size_t compute_offset(size_t const documentPosition, size_t const recognizerIndex) const {
		throw_assert(documentPosition < document_length);
		throw_assert(recognizerIndex < recognizer_count);
		return documentPosition * recognizer_count + recognizerIndex;
	}

public:
	producer_table(size_t const documentLength, size_t const recognizerCount) : document_length(documentLength), recognizer_count(recognizerCount), storage(static_cast<t *>(malloc(sizeof(t) * documentLength * recognizerCount))) {
		auto const elementCount = document_length * recognizer_count;
		for (size_t i = 0; i < elementCount; ++i) {
			new (storage + i) t();
		}
	}

	~producer_table() {
		auto const elementCount = document_length * recognizer_count;
		for (size_t i = 0; i < elementCount; ++i) {
			storage[i].~t();
		}
		free(storage);
	}

	t & operator()(size_t const documentPosition, size_t const recognizerIndex) const {
		return storage[compute_offset(documentPosition, recognizerIndex)];
	}

	t & operator()(match_class const matchClass) const {
		return operator()(matchClass.document_position, matchClass.recognizer_index);
	}
};

//holds the state of the parser during a parse
//making it a type makes it easy for the parser to reset its state
class job {
public:
	std::u32string const document;
	grammar_base const & g;
	std::unique_ptr<producer_table> producers;	
	mutable std::mutex producers_mutex;
	std::atomic<int> progress;

	job(parser & owner, std::u32string const & document, grammar_base const & g, size_t const rootRecognizerIndex, progress_handler_t const & progressHandler);
	void connect(match_class const & matchClass, context const & c, int nextState, leaf const * l);
private:
	parser * owner;
	progress_handler_t progress_handler;
	std::atomic<size_t> progress_counter;

	producer& get_producer(match_class const & matchClass);
	void update_progress(size_t completed);

	friend class parser;
	friend class producer;
};

} // namespace detail
} // namespace parlex

#endif //JOB_HPP
