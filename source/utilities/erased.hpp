#ifndef ERASED_HPP
#define ERASED_HPP

#include <functional>
#include <memory>

// value semantic type erasure via base types
template<typename T>
class erased final {
public:
	// alias for unique_ptr with a deleter function
	template<typename U>
	using ptr = std::unique_ptr<U, std::function<void (U*)>>;

	// construct with perfect forwarding to T
	template<typename... Args>
	erased(Args... args) : cloner(create_cloner<T>()), deleter(create_deleter<T>()), value(new T(std::forward<Args>(args)...), deleter) {}

	// construct from type that inherits T
	template<typename U>
	erased(U const & value) : cloner(create_cloner<U>()), deleter(create_deleter<U>()), value(new U(value), deleter) {
		static_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
		static_assert(std::is_copy_constructible<U>::value, "the given value is not copy constructible");
	}

	// copy constructor
	erased(erased const & other) : cloner(other.cloner), deleter(other.deleter), value(cloner(&*other.value), deleter) {}

	// construct from erased<U> where U inherits T
	template<typename U>
	erased(erased<U> const & other) : cloner(create_cloner<U>(other.cloner)), deleter(create_deleter<U>(other.deleter)), value(other.cloner(&*other.value), deleter)  {
		static_throw_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
	}

	// assignment operator
	erased & operator =(erased const & other) {
		cloner = other.cloner;
		deleter = other.deleter;
		ptr<T> newPtr(cloner(&*other.value), deleter);
		value.swap(newPtr);
		return *this;
	}

	// assignment operator from erased<U> where U inherits T
	template<typename U>
	erased & operator =(erased<U> const & other) {
		static_throw_assert(std::is_base_of<T, U>::value, "the given value does not inherit the erasure type");
		cloner = create_cloner<U>(other.cloner);
		deleter = create_deleter<U>(other.deleter);
		ptr<T> newu_p(other.cloner(&*other.value), deleter);
		value.swap(std::move(newu_p));
		return *this;
	}

	// assignment from U where U inherits T, and U is not erased<U>
	template<typename U, typename std::enable_if_t<std::is_base_of_v<T, U>, int> = 0>
	erased & operator =(U const & newValue) {
		cloner = create_cloner<U>();
		deleter = create_deleter<U>();
		ptr<T> newu_p(new U(newValue), deleter);
		value.swap(std::move(newu_p));
		return *this;
	}

	// assignment from U where T can be assigned by U, and U is not an inheritor of T
	template<typename U, typename std::enable_if_t<!std::is_base_of_v<T, U> && !std::is_same_v<U, erased>, int> = 0>
	erased & operator =(U const & newValue) {
		*value = newValue;
		return *this;
	}

	std::unique_ptr<T> clone() const { return std::unique_ptr<T>(cloner(value.get())); }

	T & operator *() { return *value; }
	T * operator ->() { return &*value; }
	T const & operator *() const { return *value; }
	T const * operator ->() const { return &*value; }

private:
	template<typename U>
	std::function<T* (T*)> create_cloner() {
		return [](T * original) {
			return (T*)new U(*static_cast<U*>(original));
		};
	}

	// create a cloner function of a multiply-erased value by wrapping the cloner of the source erased<U>
	template<typename U>
	std::function<T* (T*)> create_cloner(std::function<U* (U*)> underlying) {
		return [underlying](T * original) {
			return (T*)underlying(static_cast<U*>(original));
		};
	}

	template<typename U>
	std::function<void (T*)> create_deleter() {
		return [](T * p) {
			delete (U*)p;
		};
	}

	// create a deleter function of a multiply-erased value by wrapping the cloner of the source erased<U>
	template<typename U>
	std::function<void (T*)> create_deleter(std::function<void (U*)> underlying) {
		return [underlying](T * p) {
			underlying(static_cast<U*>(p));
		};
	}

	template<typename U>
	friend class erased;

	std::function<T* (T*)> cloner;
	std::function<void(T*)> deleter;
	ptr<T> value;
};

#endif //ERASED_HPP
