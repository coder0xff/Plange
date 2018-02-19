#ifndef PRODUCER_TABLE_HPP
#define PRODUCER_TABLE_HPP

#include <atomic>

#include "parlex/detail/producer.hpp"

namespace parlex::detail {

struct match_class;

class producer_table {
public:
	typedef std::atomic<producer *> t;

	uint32_t const document_length;
	uint16_t const recognizer_count;

private:
	t * const storage;

public:
	producer_table(uint32_t const documentLength, uint16_t const recognizerCount);
	~producer_table();
	uint32_t compute_id(uint32_t const documentPosition, uint16_t const recognizerIndex) const;
	uint32_t compute_id(match_class const & matchClass) const;
	match_class get_match_class(uint32_t const id) const;

	t & operator()(uint32_t const documentPosition, uint16_t const recognizerIndex) const;
	t & operator()(match_class const matchClass) const;
	t & operator()(uint32_t const id) const;
	t const * cbegin() const;
	t const * cend() const;
};


}

#endif