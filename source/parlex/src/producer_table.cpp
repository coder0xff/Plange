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

producer_table::t & producer_table::operator()(size_t const documentPosition, size_t const recognizerIndex) const
{
	return storage[compute_offset(documentPosition, recognizerIndex)];
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

producer_table::producer_table(size_t const documentLength, size_t const recognizerCount) : document_length(documentLength), recognizer_count(recognizerCount), storage(static_cast<t *>(malloc(sizeof(t) * documentLength * recognizerCount)))
{
	if (storage == nullptr) {
		throw "Unable to allocate";
	}
	auto const elementCount = document_length * recognizer_count;
	for (size_t i = 0; i < elementCount; ++i) {
		new (storage + i) t();
	}
}

size_t producer_table::compute_offset(size_t const documentPosition, size_t const recognizerIndex) const
{
	throw_assert(documentPosition < document_length);
	throw_assert(recognizerIndex < recognizer_count);
	return documentPosition * recognizer_count + recognizerIndex;
}

}
