#ifndef INCLUDED_UTILITIES_POINTER_HPP
#define INCLUDED_UTILITIES_POINTER_HPP

#include <cstdlib>
#include <memory>

// Like unique_ptr but non-nullable, and immovable. swap is supported.
template<typename T, typename Deleter = std::default_delete<T>>
class pointer {
	T * underlying;

public:
	explicit pointer(T * underlying) : underlying(underlying) {
		if (underlying == nullptr) {
			abort();
		}
	}

	pointer(pointer const & other) = delete;

	~pointer() {
		 Deleter()(underlying);
	}

	T & operator *() const {
		return *underlying;
	}

	T * operator ->() const {
		return underlying;
	}

	friend void swap(pointer &, pointer &) noexcept;
};

template<typename T>
void swap(pointer<T> & left, pointer<T> & right) noexcept {
	using std::swap;
	swap(left.underlying, right.underlying);
}

#endif // INCLUDED_UTILITIES_POINTER_HPP