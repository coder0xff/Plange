#ifndef COHERENT_MAP_HPP
#define COHERENT_MAP_HPP

// coherent_map implements an associative collection with fast coherent find and iteration, but poor insert performance
// find is O(log n), iteration is O(1) for each step
// insert performance is improved by inserting many elements in one invocation

#include <algorithm>
#include <cassert>
#include <vector>

#include "mover.hpp"
#include <tuple>
#include "../mpl/mpl_apply_v.hpp"

namespace collections {

template <typename TKey, typename TValue, class TCompare = std::less<TKey>>
class coherent_map {

public:

	template<typename U>
	class iterator_template {
		friend class coherent_map;
		typedef std::random_access_iterator_tag iterator_category;
		typedef U value_type;
		typedef U & reference;
		typedef U * pointer;

		template<typename V>
		friend class iterator_template;

		coherent_map const * owner;
		size_t current;

	public:
		iterator_template() : owner(nullptr), current(0) {
		}

		explicit iterator_template(coherent_map const * owner, size_t const index) : owner(owner), current(index) {}

		iterator_template(iterator_template const & other) = default;
		iterator_template(iterator_template && other) = default;
		~iterator_template() = default;

		iterator_template & operator=(iterator_template const & rhs) {
			current = rhs.current;
			return *this;
		}

		template <typename V>
		iterator_template & operator=(iterator_template<V> const & rhs) {
			current = rhs.current;
			return *this;
		}

		U & operator*() const {
			assert(owner != nullptr);
			assert(current < owner->size_);
			return owner->storage[current];
		}

		U * operator->() const {
			return &operator*();
		}

		iterator_template & operator++() {
			assert(owner != nullptr);
			assert(current < owner->size_);
			++current;
			return *this;
		}

		iterator_template operator++(int) {
			iterator_template result = *this;
			++*this;
			return result;
		}

		iterator_template & operator--() {
			assert(owner != nullptr);
			assert(current != 0);
			--current;
			return *this;
		}

		iterator_template operator--(int) {
			iterator_template result = *this;
			--*this;
			return result;
		}

		iterator_template operator+(int const rhs) const {
			assert(owner != nullptr);
			if (rhs == 0) {
				return *this;
			} 
			if (rhs > 0) {
				if (current + rhs > owner->size_) {
					throw std::logic_error("Cannot move iterator past the end of the collection");
				}
				iterator_template result = *this;
				result.current += rhs;
				return result;
			}
			if (-rhs > int(current)) {
				throw std::logic_error("Cannot move iterator before the start of the collection");
			}
			iterator_template result = *this;
			result.current += rhs;
			return result;
		}

		iterator_template operator-(int const rhs) const {
			return *this + (-rhs);
		}

		ptrdiff_t operator-(iterator_template const & rhs) const {
			return current - ptrdiff_t(rhs.current);
		}

		explicit operator iterator_template<const value_type>() const {
			return iterator_template<const value_type>(owner, current);
		}

		template<typename V>
		bool operator==(iterator_template<V> const & rhs) const {
			return owner == rhs.owner && current == rhs.current;
		}

		template<typename V>
		bool operator!=(iterator_template<V> const & rhs) const {
			return !(*this == rhs);
		}

		friend void swap(iterator_template & lhs, iterator_template & rhs) noexcept {
			using std::swap; // bring in swap for built-in types
			swap(lhs.owner, rhs.owner);
			swap(lhs.current, rhs.current);
		}
	};

	typedef std::pair<TKey, TValue> value_type;
	typedef value_type & reference;
	typedef const value_type & const_reference;
	typedef value_type * pointer;
	typedef value_type const * const_pointer;
	typedef iterator_template<value_type> iterator;
	typedef iterator_template<const value_type> const_iterator;

	coherent_map() : capacity(0), storage(nullptr), size_(0) {}

	coherent_map(coherent_map const & other) : capacity(other.size_), storage(reinterpret_cast<value_type *>(malloc(sizeof(value_type) * capacity))), size_(other.size_) {
		for (size_t i = 0; i < size_; ++i) {
			new (storage + i) value_type(other.storage[i]);
		}
	}

	friend void swap(coherent_map & lhs, coherent_map & rhs) noexcept {
		std::swap(lhs.capacity, rhs.capacity);
		std::swap(lhs.storage, rhs.storage);
		std::swap(lhs.size_, rhs.size_);
	}

	coherent_map(coherent_map && move) noexcept : coherent_map() {
		swap(*this, move);
	}

	~coherent_map() {
		clear();
		if (storage != nullptr) {
			free(storage);
		}
	}

	void reserve(size_t const count) {
		if (count > capacity) {
			capacity = count * 2;
			if (storage == nullptr) {
				storage = reinterpret_cast<value_type *>(malloc(sizeof(value_type) * capacity));
			} else {
				auto newStorage = reinterpret_cast<value_type *>(malloc(sizeof(value_type) * capacity));
				for (size_t i = 0; i < size_; ++i) {
					detail::mover(newStorage + i, storage + i);
				}
				free(storage);
				storage = newStorage;
			}
		}
	}

	size_t size() const {
		return size_;
	}

	bool empty() const {
		return size_ == 0;
	}

	size_t clear() {
		auto const result = size_;
		for (size_t i = 0; i < size_; ++i) {
			storage[i].~value_type();
		}
		size_ = 0;
		return result;
	}

	const_iterator lower_bound(TKey const & key) const {
		size_t low = 0;
		auto high = size_;
		while (size_ > 0 && low < high) {
			auto mid = (low + high) / 2;
			TKey const & midKey = storage[mid].first;
			if (TCompare()(midKey, key)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return size_ == 0 || high == size_ ? cend() : const_iterator(this, high);
	}

	iterator lower_bound(TKey const & key) {
		const_iterator temp = const_cast<coherent_map const *>(this)->lower_bound(key);
		return iterator(temp.owner, temp.current);
	}

private:

	// Move all indices at and after the specified position to the following position.
	// This opens up a gap at the position that we can use for a new value.
	void shift_one(size_t const position) {
		assert(position < size_);
		reserve(size_ + 1);
		for (auto i = size_ - 1; i >= position; --i) {
			detail::mover(storage + i + 1, storage + i);
			if (i == 0) {
				break;
			}
		}
	}

	void unshift_one(size_t const position) {
		assert(position < size_);
		storage[position].~value_type();
		for (auto i = position; i < size_; ++i) {
			detail::mover(storage + i, storage + i + 1);
		}
	}

	struct less_than_predicate {
		bool operator()(value_type const & lhs, value_type const & rhs) const {
			return TCompare()(lhs.first, rhs.first);
		}
	};

	struct equals_predicate {
		bool operator()(value_type const & lhs, value_type const & rhs) const {
			return !TCompare()(lhs.first, rhs.first) && !TCompare()(rhs.first, lhs.first);
		}
	};

public:

	template<typename... U, typename... V>
	std::pair<iterator, bool> emplace(std::piecewise_construct_t const &, std::tuple<U...> && keyArgs, std::tuple<V...> && valueArgs) {
		std::remove_reference_t<TKey> key(std::move(mpl::apply_v_constructor<TKey, std::tuple<U...>>(std::forward<std::tuple<U...> &&>(keyArgs))));
		reserve(size_ + 1);
		auto position = lower_bound(key);
		if (position != end()) {
			bool const equalKeys = !(TCompare()(position->first, key)) && !(TCompare()(key, position->first));
			if (equalKeys) {
				return std::make_pair(position, false);
			}
			auto insertIndex = position.current;
			shift_one(insertIndex);
			std::remove_reference_t<TValue> value(std::move(mpl::apply_v_constructor<TValue, std::tuple<V...>>(std::forward<std::tuple<V...> &&>(valueArgs))));
			new (storage + position.current) value_type(std::move(key), std::move(value));
			++size_;
			return std::make_pair(position, true);
		}
		std::remove_reference_t<TValue> value(std::move(mpl::apply_v_constructor<TValue, std::tuple<V...>>(std::forward<std::tuple<V...> &&>(valueArgs))));
		new (storage + size_) value_type(std::move(key), std::move(value));
		++size_;
		return std::make_pair(iterator(this, size_ - 1), true);
	}

	std::pair<iterator, bool> emplace(TKey const & key, TValue const & value) {
		return emplace(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple(value));
	}

	std::pair<iterator, bool> insert(value_type && value) {
		return emplace(std::piecewise_construct, std::forward_as_tuple(value.first), std::forward_as_tuple(value.second));
	}

	template<typename TIterator>
	size_t insert_many(TIterator const & begin, TIterator const & end) {
		size_t const requestedCount = end - begin;
		reserve(size_ + requestedCount);
		size_t counter = 0;
		for (auto i = begin; i != end; ++i) {
			new (storage + size_ + counter++) value_type(*i);
		}
		std::stable_sort(storage, storage + size_ + requestedCount, less_than_predicate());
		auto const originalSize = size_;
		auto newEnd = std::unique(storage, storage + size_ + requestedCount, equals_predicate());
		for (size_t i = newEnd - storage; i < size_; ++i) {
			storage[i].~value_type();
		}
		size_ = newEnd - storage;
		return size_ - originalSize;
	}

	template<typename TIterator>
	size_t erase_many(TIterator const & beginParam, TIterator const & endParam) {
		TCompare compare;
		assert(std::is_sorted(beginParam, endParam, compare));
		size_t readIndex = 0;
		size_t writeIndex = 0;
		TIterator i = beginParam;
		while (i != endParam && readIndex < size_) {
			if (compare(*i, storage[readIndex].first)) {
				++i;
				continue;
			}
			if (compare(storage[readIndex].first, *i)) {
				if (writeIndex < readIndex) {
					detail::mover(storage + writeIndex, storage + readIndex);
				}
				++readIndex;
				++writeIndex;
				continue;
			}
			// elements are equal, so remove
			storage[readIndex++].~value_type();
			++i;
		}
		// if any elements were removed then shift any remaining elements
		if (writeIndex < readIndex) {
			while (readIndex < size_) {
				detail::mover(storage + writeIndex++, storage + readIndex++);
			}
		}
		auto const erasedCount = readIndex - writeIndex;
		size_ -= erasedCount;
		return erasedCount;
	}

	const_iterator find(TKey const & key) const {
		auto result = lower_bound(key);
		if (result == end() || TCompare()(key, result->first)) {
			return cend();
		}
		return result;
	}

	iterator find(TKey const & key) {
		const_iterator temp = const_cast<coherent_map const *>(this)->find(key);
		return iterator(this, temp.current);
	}

	TValue & operator[](TKey const & key)
	{
		auto i = lower_bound(key);
		if (i != end()) {
			if (!(TCompare()(key, i->first))) {
				return i->second;
			}
			auto insertPosition = i.current;
			shift_one(insertPosition);
			new (storage + insertPosition) value_type(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple());
			++size_;
			return i->second;
		}
		reserve(size_ + 1);
		new (storage + size_) value_type(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple());
		++size_;
		return storage[size_ - 1].second;
	}

	TValue & operator[](TKey && key)
	{
		auto i = lower_bound(key);
		if (i != end()) {
			if (!(TCompare()(key, i->first))) {
				return i->second;
			}
			auto insertPosition = i.current;
			shift_one(insertPosition);
			new (storage + insertPosition) value_type(std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::forward_as_tuple());
			++size_;
			return i->second;
		}
		reserve(size_ + 1);
		new (storage + size_) value_type(std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::forward_as_tuple());
		++size_;
		return storage[size_ - 1].second;
	}

	size_t erase(TKey const & key) {
		auto i = find(key);
		if (i != end()) {
			unshift_one(i.current);
			--size_;
			return 1;
		}
		return 0;
	}

	iterator begin() noexcept {
		return iterator(this, 0);
	}

	const_iterator begin() const noexcept {
		return const_iterator(this, 0);
	}

	const_iterator cbegin() const noexcept {
		return const_iterator(this, 0);
	}

	iterator end() const noexcept {
		return iterator(this, size_);
	}

	const_iterator cend() const noexcept {
		return const_iterator(this, size_);
	}

	size_t count(TKey const & key) const {
		return find(key) == end() ? 0 : 1;
	}

private:
	size_t capacity;
	value_type * storage;
	size_t size_;

	
};

}

#endif //COHERENT_MAP_HPP
