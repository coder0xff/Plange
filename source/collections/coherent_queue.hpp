#ifndef COHERENT_QUEUE_HPP
#define COHERENT_QUEUE_HPP

/* coherent_queue provides push and pop with coherence */

#include <cstdlib>

#include "mover.hpp"

namespace collections {

template<typename T>
class coherent_queue {
	size_t capacity;
	T* storage;
	size_t push_index;
	size_t pop_index;

public:
	coherent_queue() : capacity(2), storage(static_cast<T*>(malloc(sizeof(T) * capacity))), push_index(0), pop_index(0) {}

	~coherent_queue() {
		while (pop_index != push_index) {
			pop();
		}
		free(storage);
	}

	size_t size() const {
		if (pop_index <= push_index) {
			return push_index - pop_index;
		}
		return capacity - pop_index + push_index;
	}

	bool empty() const {
		return size() == 0;
	}

	void reserve(size_t const count) {
		if (count > capacity) {
			auto const savedSize = size();
			auto const newCapacity = count * 2;
			T* newStorage = static_cast<T*>(malloc(sizeof(T) * newCapacity));
			size_t counter = 0;
			while (pop_index != push_index) {
				detail::mover(newStorage + counter++, storage + pop_index++);
				if (pop_index == capacity) {
					pop_index = 0;
				}
			}
			free(storage);
			capacity = newCapacity;
			storage = newStorage;
			pop_index = 0;
			push_index = pop_index + savedSize;
		}
	}

	void push(T const & v) {
		reserve(size() + 2); // +2 for the element about to be pushed, and to prevent push_index == pop_index, which indicates 0 size()
		storage[push_index++] = v;
		if (push_index == capacity) {
			push_index = 0;
		}
	}

	template<typename... U>
	void emplace(U&&... args) {
		reserve(size() + 2); // +2 for the element about to be pushed, and to prevent push_index == pop_index, which indicates 0 size()
		new (storage + push_index++) T(std::forward<U>(args)...);
		if (push_index == capacity) {
			push_index = 0;
		}
	}

	T pop() {
		if (pop_index == push_index) {
			throw;
		}
		T & temp = storage[pop_index];
		T result = temp;
		temp.~T();
		++pop_index;
		if (pop_index == capacity) {
			pop_index = 0;
		}
		return result;
	}
};

}
#endif //COHERENT_QUEUE_HPP