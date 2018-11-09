#ifndef INCLUDED_UTILITIES_VAL_HPP
#define INCLUDED_UTILITIES_VAL_HPP

#include <atomic>
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>

template<typename T>
class ptr;

template<typename T, size_t SmallStorageSize>
class val;

namespace val_detail {

	enum operation {
		CLONE,
		DELETE,
		DESTRUCT,
		SIZE,
		TYPE
	};

	struct block {
		std::atomic<intptr_t> count;
		std::atomic<void *> data; // Ensure that propagation of this value to other threads is immediate

		block(void * d) : count(0), data(d) {
			assert(d);
		}

		void increment() {
			count.fetch_add(1);
		}

		void decrement() {
			if (count.fetch_sub(1) == 1) {
				delete this;
			}
		}
	};

	typedef intptr_t (*op_sig)(operation, void const *, void *);

	struct descriptor_t {
		block * block_ptr;
		size_t upcast_offset;
		op_sig op_ptr;
	};

	template<typename T, typename U>
	size_t compute_upcast_offset = (size_t)((T*)((U*)1)) - 1;

	template<typename T, typename = void>
	struct is_defined_impl : std::false_type { };

	template<typename T>
	struct is_defined_impl<T, typename std::enable_if<(sizeof(T) - sizeof(T)) == 0>::type> : std::true_type {};

	template<typename T>
	constexpr bool is_defined = is_defined_impl<T>::value;

	template<typename DefaultSize, typename T, typename = void>
	struct helper_impl {
		static constexpr size_t small_storage_size = DefaultSize::value;
		static constexpr bool allow_copy = true;
		static constexpr bool allow_move = true;

	};

	template<typename DefaultSize, typename T>
	struct helper_impl<DefaultSize, T, typename std::enable_if<is_defined<T>>::type> {
		static constexpr size_t small_storage_size = sizeof T;
		static constexpr bool allow_copy = std::is_copy_constructible<T>::value;
		static constexpr bool allow_move = std::is_constructible<T, T&&>::value; //is_move_constructible is broken in VS 2017
	};

	template<size_t DefaultSize, typename T>
	constexpr size_t small_storage_size = helper_impl<std::integral_constant<size_t, DefaultSize>, T>::small_storage_size;

	template<typename T>
	constexpr bool allow_copy = helper_impl<std::integral_constant<size_t, 0>, T>::allow_copy;

	template<typename T>
	constexpr bool allow_move = helper_impl<std::integral_constant<size_t, 0>, T>::allow_move;


	template<typename T, bool IsClonable>
	struct clone_impl {
		static_assert(IsClonable != IsClonable, "template specialization failed");
	};

	template<typename T>
	struct clone_impl<T, true> {
		static T * clone(T const * data, void * placement) {
			if (placement == nullptr) {
				return new T(*data);
			}
			return new(placement) T(*data);
		}
	};

	template<typename T>
	struct clone_impl<T, false> {
		static T * clone(T const * data, void * placement) {
			abort();
		}
	};

	template<typename T>
	static intptr_t op(operation o, void const * value, void * placement) {
		auto const data = static_cast<T const *>(value);
		switch (o) {
		case CLONE:
			assert(data);
			return reinterpret_cast<intptr_t>(clone_impl<T, val_detail::allow_copy<T>>::clone(data, placement));
		case DELETE:
			assert(data);
			delete data; // virtual destruction is unneeded and bypassed because we always work with the most-derived perspective
			return 0;
		case DESTRUCT:
			assert(data);
			data->~T(); // virtual destruction is unneeded and bypassed because we always work with the most-derived perspective
			return 0;
		case SIZE:
			return sizeof(T);
		case TYPE:
			return reinterpret_cast<intptr_t>(typeid(T).name());
		}
		throw;
	}

	static void * clone(op_sig const & op_ptr, void const * value, void * placement) {
		return reinterpret_cast<void *>(op_ptr(CLONE, value, placement));
	}

	static void delete_(op_sig const & op_ptr, void const * value) {
		op_ptr(DELETE, value, nullptr);
	}

	static void destruct(op_sig const & op_ptr, void const * value) {
		op_ptr(DESTRUCT, value, nullptr);
	}

	static size_t size(op_sig const & op_ptr) {
		return static_cast<size_t>(op_ptr(SIZE, nullptr, nullptr));
	}

	static char const * type(op_sig const & op_ptr) {
		return reinterpret_cast<char const *>(op_ptr(TYPE, nullptr, nullptr));
	}

	template<typename T, typename = void>
	struct emit_heap_warning_imp {
		static void emit_heap_warning(char const * const u_name) {
#if !NDEBUG
			//std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is unknown. Type U is " << u_name << ".\n";
#endif
		}
	};

	template<typename T>
	struct emit_heap_warning_imp<T, typename std::enable_if<is_defined<T>, T>::type> {
		static void emit_heap_warning(char const * const u_name) {
#if !NDEBUG
			//std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is " << typeid(T).name() << ". Type U is " << u_name << ".\n";
#endif
		}
	};

	template<typename T>
	void emit_heap_warning(char const * const u_name) {
		emit_heap_warning_imp<T>::emit_heap_warning(u_name);
	}

	template<typename T, typename U>
	void emit_heap_warning2() {
#if !NDEBUG
		//std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is " << typeid(T).name() << ". Type U is " << typeid(U).name() << ".\n";
#endif
	}

	template<typename U, typename V>
	using is_same_ignore_const = std::is_same<typename std::remove_const<U>::type, typename std::remove_const<V>::type>;

}

template<typename T>
class enable_ptr_from_this {
public:
	enable_ptr_from_this() {
		memset(&descriptor_, 0, sizeof descriptor_);
	}

	ptr<T> ptr_from_this() {
		return ptr<T>(descriptor_);
	}

	ptr<T const> ptr_from_this() const {
		return ptr<T>(descriptor_);
	}

private:
	template<typename, size_t>
	friend class val;

	explicit enable_ptr_from_this(val_detail::descriptor_t const & descriptor)
		: descriptor_(descriptor) {}

	val_detail::descriptor_t descriptor_;
};


// non-nullable weak pointer to val objects
template<typename T>
class ptr {
	// NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
	template<typename>
	friend class ptr;

	template<typename, size_t>
	friend class val;

	using descriptor_t = val_detail::descriptor_t;
	using block = val_detail::block;
	using op_sig = val_detail::block;

public:
	typedef T type;

	// copy constructor
	ptr(ptr const & other) {
		const descriptor_t d = other.get_descriptor();
		descriptor = d;
		descriptor.block_ptr->increment();
	}

	//template<typename U, typename std::enable_if<std::is_const<T>::value, int>::type = 0>
	//ptr(ptr<typename std::remove_const<T>::type> const & other) {
	//	const descriptor_t d = other.get_descriptor();
	//	descriptor = d;
	//	descriptor.block_ptr->increment();
	//}

	ptr & operator =(ptr other) {
		auto new_descriptor = other.get_descriptor();
		new_descriptor.block_ptr->increment();
		auto old_descriptor = exchange_descriptor(new_descriptor);
		old_descriptor.block_ptr->decrement();
		return *this;
	}

	~ptr() {
		auto d = get_descriptor();
		d.block_ptr->decrement();
	}

	// construct from ptr<U> where U inherits T
	template<typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr(ptr<U> const & other) {
		descriptor = other.get_descriptor();
		descriptor.block_ptr->increment();
		descriptor.upcast_offset += val_detail::compute_upcast_offset<T, U>;
	}

	template<typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr & operator =(ptr<U> other) {
		auto new_descriptor = other.get_descriptor();
		new_descriptor.block_ptr->increment();
		new_descriptor.upcast_offset += val_detail::compute_upcast_offset<T, U>;
		auto old_descriptor = exchange_descriptor(new_descriptor);
		old_descriptor.block_ptr->decrement();
		return *this;
	}

	template<typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr(val<U, SmallStorageSizeU> const & other) {
		descriptor = other.data.get_descriptor();
		descriptor.block_ptr->increment();
		descriptor.upcast_offset += val_detail::compute_upcast_offset<T, U>;
	}


	template<typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<U, T>::value && !std::is_same<U, T>::value, int>::type = 0>
	explicit ptr(val<U, SmallStorageSizeU> const & other) {
		auto result = dynamic_cast<T*>(&*other);
		if (result == nullptr) {
			throw;
		}
		descriptor = other.data.get_descriptor();
		descriptor.block_ptr->increment();
		descriptor.upcast_offset -= val_detail::compute_upcast_offset<T, U>;
	}

	template<typename U, typename std::enable_if<std::is_base_of<U, T>::value && !val_detail::is_same_ignore_const<T, U>::value, int>::type = 0>
	explicit ptr(ptr<U> const & other) {
		U * result = dynamic_cast<U*>(&*other);
		if (result == nullptr) {
			throw;
		}
		descriptor = other.get_descriptor();
		descriptor.block_ptr->increment();
		descriptor.upcast_offset -= val_detail::compute_upcast_offset<T, U>;
	}

	T * operator ->() const {
		auto const d = get_descriptor();
		auto const data = d.block_ptr->data.load();
		assert(data != nullptr);
		auto result = reinterpret_cast<T *>(reinterpret_cast<int8_t *>(data) + d.upcast_offset);
		return result;
	}

	T & operator *() const {
		return *operator ->();
	}

private:
	template<typename U>
	friend class enable_ptr_from_this;

	descriptor_t descriptor;
	mutable std::mutex m;

	explicit ptr(descriptor_t const & d) : descriptor(d) {
		d.block_ptr->increment();
	}

	ptr(val_detail::block * b, size_t upcast_offset, val_detail::op_sig op_ptr) : descriptor{b, upcast_offset, op_ptr} {
		b->increment();
	}

	descriptor_t get_descriptor() const {
		std::unique_lock<std::mutex> lock(m);
		return descriptor;
	}

	descriptor_t exchange_descriptor(descriptor_t const & v) {
		std::unique_lock<std::mutex> lock(m);
		const auto saved = descriptor;
		descriptor = v;
		return saved;
	}

	descriptor_t clone(size_t upcast_offset, void * placement) const {
		const auto d = get_descriptor();
		if (placement == nullptr) {
			char const * const uName = val_detail::type(d.op_ptr);
			val_detail::emit_heap_warning<T>(uName);
		}
		const auto cloned = val_detail::clone(d.op_ptr, d.block_ptr->data.load(), placement);
		return descriptor_t{new block(cloned), d.upcast_offset + upcast_offset, d.op_ptr};
	}

	size_t get_size_of_data() const {
		const auto d = get_descriptor();
		return size(d.op_ptr);
	}

};

template<typename T>
using nptr = std::optional<ptr<T>>;

// value semantic polymorphic type erasure
template<typename T, size_t SmallStorageSize = val_detail::small_storage_size<16, T>>
class val {
	// NOLINT(cppcoreguidelines-special-member-functions, cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
	template<typename>
	friend class ptr;

	template<typename, size_t>
	friend class val;

	using descriptor_t = val_detail::descriptor_t;
	using block = val_detail::block;
	using op_sig = val_detail::block;

	void * emplacement_ptr(size_t dataSize) {
		return nullptr; //TODO: turn small storage back on
		if (dataSize <= SmallStorageSize) {
			return reinterpret_cast<void *>(&small_storage);
		}
		return nullptr;
	}

	template<typename U>
	typename std::remove_const<U>::type * construct(U const & other) {
		const auto ptr = emplacement_ptr(sizeof(U));
		if (ptr == nullptr) {
			val_detail::emit_heap_warning2<T, U>();
			return new typename std::remove_const<U>::type(other);
		}
		return new(ptr) typename std::remove_const<U>::type(other);
	}

	template<typename U>
	typename std::remove_const<U>::type * construct(U && other) {
		const auto ptr = emplacement_ptr(sizeof(U));
		if (ptr == nullptr) {
			val_detail::emit_heap_warning2<T, U>();
			return new typename std::remove_const<U>::type(std::forward<U>(other));
		}
		return new(ptr) typename std::remove_const<U>::type(std::forward<U>(other));
	}

	void init_ptr_from_this() {
		if constexpr (std::is_base_of<enable_ptr_from_this<T>, T>::value) {
			enable_ptr_from_this<T> & base = *static_cast<enable_ptr_from_this<T> *>(&**this);
			base.descriptor_ = data.get_descriptor();
		}	
	}

public:
	typedef T value_type;
	static constexpr size_t small_storage_size = SmallStorageSize;

	// ReSharper disable CppPossiblyUninitializedMember
	// ReSharper disable CppNonExplicitConvertingConstructor
	template<typename = typename std::enable_if<val_detail::allow_copy<T>>::type>
	val(T const & v) : small_storage{0}, data(new val_detail::block(construct(v)), 0, &val_detail::op<T>) {
		init_ptr_from_this();
	}

	template<typename = typename std::enable_if<val_detail::allow_move<T>>::type>
	val(T && v) : small_storage{0}, data(new val_detail::block(construct(std::forward<T>(v))), 0, &val_detail::op<T>) {
		init_ptr_from_this();
	}

	template<typename = typename std::enable_if<val_detail::allow_copy<T>>::type>
	val(val const & other) : small_storage{0}, data(other.data.clone(0, emplacement_ptr(val_detail::small_storage_size<SIZE_MAX, T>))) {
		init_ptr_from_this();
	}

	// construct from type U that inherits T
	template<typename U, typename std::enable_if<std::is_base_of<T, U>::value && val_detail::allow_copy<U>, int>::type = 0>
	val(U const & v) : small_storage{0}, data(new val_detail::block(construct(v)), val_detail::compute_upcast_offset<T, U>, &val_detail::op<U>) {
		init_ptr_from_this();
	}

	// construct from type U that inherits T
	template<typename U, typename std::enable_if<std::is_base_of<T, U>::value && val_detail::allow_copy<U>, int>::type = 0>
	// ReSharper disable once CppNonExplicitConvertingConstructor
	val(U && v) : small_storage{0}, data(new val_detail::block(construct(v)), val_detail::compute_upcast_offset<T, U>, &val_detail::op<U>) {
		init_ptr_from_this();
	} // NOLINT(misc-forwarding-reference-overload)

	// construct from val<U> where U inherits T
	template<typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<T, U>::value && val_detail::allow_copy<U>, int>::type = 0>
	val(val<U, SmallStorageSizeU> const & other) : small_storage{0}, data(other.data.clone(val_detail::compute_upcast_offset<T, U>, emplacement_ptr(other.data.get_size_of_data()))) {
		init_ptr_from_this();
	}

	// construct from val<U> where U inherits T
	template<typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<U, T>::value && !val_detail::is_same_ignore_const<T, U>::value && val_detail::allow_copy<U>, int>::type = 0>
	val(val<U, SmallStorageSizeU> const & other) : small_storage{0}, data(other.data.clone(val_detail::compute_upcast_offset<T, U>, emplacement_ptr(other.data.get_size_of_data()))) {
		init_ptr_from_this();
	}

	// ReSharper restore CppPossiblyUninitializedMember
	// ReSharper restore CppNonExplicitConvertingConstructor

	~val() {
		auto d = data.get_descriptor();
		auto & b = *d.block_ptr;
		// b.data and b.count are sequentially consistent
		void * buffer = b.data.exchange(nullptr);
		assert(buffer);
		assert(b.count == 1); // this->data should be the only ptr
		if (buffer == &small_storage) {
			val_detail::destruct(d.op_ptr, buffer);
		} else {
			val_detail::delete_(d.op_ptr, buffer);
		}
	}

	T & operator *() { return *data; }

	T * operator ->() {
		T * const result = &*data;
		return result;
	}

	T const & operator *() const { return *data; }
	T const * operator ->() const { return &*data; }

	operator ptr<T>() {
		return data;
	}

	std::unique_ptr<T> clone() const {
		auto d = data.clone(0, nullptr);
		return std::unique_ptr<T>(reinterpret_cast<T*>(static_cast<int8_t*>(d.block_ptr->data.load()) + d.upcast_offset));
	}

private:
	int8_t small_storage[SmallStorageSize];
	ptr<T> data;

};

template<typename T, typename... ArgTs>
val<T> make_val(ArgTs &&... args) {
	return val<T>(T(std::forward<ArgTs>(args)...));
}

#endif // INCLUDED_UTILITIES_VAL_HPP
