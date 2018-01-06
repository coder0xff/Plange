#ifndef PRODUCER_TABLE_HPP
#define PRODUCER_TABLE_HPP

#include <atomic>
#include <cstdlib>

#include "parlex/detail/producer.hpp"

namespace parlex::detail {

struct match_class;

class producer_table {
public:
	typedef std::atomic<producer *> t;

	size_t const document_length;
	size_t const recognizer_count;

private:
	t * const storage;
	size_t compute_offset(size_t const documentPosition, size_t const recognizerIndex) const;

public:
	producer_table(size_t const documentLength, size_t const recognizerCount);
	~producer_table();

	t & operator()(size_t const documentPosition, size_t const recognizerIndex) const;
	t & operator()(match_class const matchClass) const;
	t const * cbegin() const;
	t const * cend() const;
};


}

#endif