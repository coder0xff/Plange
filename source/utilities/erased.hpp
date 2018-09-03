#ifndef INCLUDED_UTILITIES_ERASED_HPP
#define INCLUDED_UTILITIES_ERASED_HPP

#include <functional>
#include <memory>

// value semantic type erasure via base types
template <typename T>
class erased {

public:
	typedef T type;

	erased(type const & v) : op_ptr(&op<T>), downcast_offset(0), value(new type(v)) {}
	erased(type && v) : op_ptr(&op<T>), downcast_offset(0), value(new type(std::move(v))) {}

	// construct from type U that inherits T
	template <typename U>
	// ReSharper disable once CppNonExplicitConvertingConstructor
	erased(U const & value) : op_ptr(&op<U>), downcast_offset(compute_downcast_offset<U>()), value(new U(value)) {
		static_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
		static_assert(std::is_copy_constructible<U>::value, "the given value is not copy constructible");
	}

	// copy constructor
	erased(erased const & other) : op_ptr(other.op_ptr), downcast_offset(other.downcast_offset), value(other.do_clone()) {}

	// construct from erased<U> where U inherits T
	template <typename U>
	explicit erased(erased<U> const & other) : op_ptr(other.op_ptr), downcast_offset(other.downcast_offset + compute_downcast_offset<U>()), value(other.do_clone()) {
		static_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
	}

	~erased() {
		do_delete();
	}

	// assignment operator
	erased & operator =(erased const & other) {
		do_delete();
		op_ptr = other.op_ptr;
		downcast_offset = other.downcast_offset;
		value = other.do_clone();
		return *this;
	}

	// assignment operator from erased<U> where U inherits T
	template <typename U>
	erased & operator =(erased<U> const & other) {
		static_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
		do_delete();
		op_ptr = other.op_ptr;
		downcast_offset = other.downcast_offset + compute_downcast_offset<U>();
		value = other.do_clone();
		return *this;
	}

	// assignment from U where U inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	erased & operator =(U const & newValue) {
		do_delete();
		op_ptr = &op<U>;
		downcast_offset = compute_downcast_offset<U>();
		value = new U(newValue);
		return *this;
	}

	// assignment from U where T can be assigned by U, and U is not an inheritor of T
	template <typename U, typename std::enable_if<!std::is_base_of<T, U>::value && !std::is_same<U, erased>::value, int>::type = 0>
	erased & operator =(U const & newValue) {
		*value = newValue;
		return *this;
	}

	std::unique_ptr<T> clone() const {
		T * temp = do_clone();
		return std::unique_ptr<T>(temp);
	}

	T & operator *() { return *value; }
	T * operator ->() { return &*value; }
	T const & operator *() const { return *value; }
	T const * operator ->() const { return &*value; }

private:
	template <typename U>
	static intptr_t compute_downcast_offset() {
		return reinterpret_cast<intptr_t>(static_cast<U*>(reinterpret_cast<T*>(1))) - 1; // strange behavior with nullptr, perhaps undefined behavior?
	}

	template <typename U>
	static void * op(void const * value, bool const doDelete) {
		if (doDelete) {
			delete reinterpret_cast<U*>(const_cast<void *>(value));
			return nullptr;
		}
		return reinterpret_cast<void *>(new U(*reinterpret_cast<U const *>(value)));
	}

	void * downcast(void * p) const {
		return reinterpret_cast<int8_t *>(p) + downcast_offset;
	}

	void * upcast(void * p) const {
		return reinterpret_cast<int8_t *>(p) - downcast_offset;
	}

	T * do_clone() const {
		return reinterpret_cast<T*>(upcast(op_ptr(downcast(value), false)));
	}

	void do_delete() {
		op_ptr(downcast(value), true);
	}

	template <typename U>
	friend class erased;

	void * (*op_ptr)(void const *, bool);
	intptr_t downcast_offset;
	T * value;
};

template<typename T, typename... ArgTs>
erased<T> make_erased(ArgTs&&... args) {
	return erased<T>(T(std::forward<ArgTs>(args)...));
}

#endif // INCLUDED_UTILITIES_ERASED_HPP
