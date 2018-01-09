#include "parlex/detail/producer_table.hpp"

#include "parlex/detail/match_class.hpp"

namespace parlex::detail {

producer_table::t const * producer_table::cend() const
{
	return storage + document_length * recognizer_count;
}

producer_table::t const * producer_table::cbegin() const
{
	return storage;
}

producer_table::t & producer_table::operator()(match_class const matchClass) const
{
	return operator()(matchClass.document_position, matchClass.recognizer_index);
}

producer_table::t & producer_table::operator()(uint32_t const id) const {
	return storage[id];
}

producer_table::t & producer_table::operator()(uint32_t const documentPosition, uint16_t const recognizerIndex) const
{
	return storage[compute_id(documentPosition, recognizerIndex)];
}

producer_table::~producer_table()
{
	auto const elementCount = document_length * recognizer_count;
	for (size_t i = 0; i < elementCount; ++i) {
		auto & element = storage[i];
		auto * recognizerPtr = element.load();
		delete recognizerPtr;
		element.~t();
	}
	free(storage);
}

producer_table::producer_table(uint32_t const documentLength, uint16_t const recognizerCount) : document_length(documentLength), recognizer_count(recognizerCount), storage(static_cast<t *>(malloc(sizeof(t) * documentLength * recognizerCount)))
{
	if (storage == nullptr) {
		throw "Unable to allocate";
	}
	auto const elementCount = document_length * recognizer_count;
	for (size_t i = 0; i < elementCount; ++i) {
		new (storage + i) t();
	}
}

uint32_t producer_table::compute_id(uint32_t const documentPosition, uint16_t const recognizerIndex) const
{
	throw_assert(documentPosition < document_length);
	throw_assert(recognizerIndex < recognizer_count);
	return uint32_t(documentPosition * recognizer_count + recognizerIndex);
}

uint32_t producer_table::compute_id(match_class const & matchClass) const {
	return compute_id(matchClass.document_position, matchClass.recognizer_index);
}

match_class producer_table::get_match_class(uint32_t const id) const {
	auto const divResult = std::div(intmax_t(id), intmax_t(recognizer_count));
	return {uint32_t(divResult.quot), uint16_t(divResult.rem)};
}

}
