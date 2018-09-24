#ifndef INCLUDED_UTILITIES_VAL_HPP
#define INCLUDED_UTILITIES_VAL_HPP

#include <atomic>
#include <cassert>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>

template <typename T>
class ptr;

template <typename T, size_t SmallStorageSize>
class val;

namespace val_detail {

	enum operation {
		CLONE,
		MOVE,
		DELETE,
		DESTRUCT,
		SIZE,
		TYPE
	};

	class block {
		template <typename>
		friend class ptr;

		template <typename, size_t>
		friend class val;

		std::atomic<intptr_t> count;
		std::atomic<void *> data; // Ensure that propagation of this value to other threads is immediate

		block(void * d) : count(0), data(d) {}

		void increment() {
			count.fetch_add(1);
		}

		void decrement() {
			if (count.fetch_sub(1) == 1) {
				delete this;
			};
		}
	};

	typedef intptr_t(*op_sig)(operation, void const *, void *);

	struct descriptor_t {
		block * block_ptr;
		size_t upcast_offset;
		op_sig op_ptr;
	};

	template <typename T, typename U>
	size_t compute_upcast_offset = (size_t)((T*)((U*)1)) - 1;

	template <typename T, bool IsClonable>
	struct clone_impl {
		static_assert(IsClonable != IsClonable, "template specialization failed");
	};

	template <typename T>
	struct clone_impl<T, true> {
		static T * clone(T const * data, void * placement)  {
			if (placement == nullptr) {
				return new T(*data);
			}
			return new (placement) T(*data);
		}
	};

	template <typename T>
	struct clone_impl<T, false> {
		static T * clone(T const * data, void * placement) {
			abort();
		}
	};

	template <typename T, bool IsMovable>
	struct move_impl {
		static_assert(IsMovable != IsMovable, "template specialization failed");
	};

	template <typename T>
	struct move_impl<T, true> {
		static T * move(T const * data, void * placement) {
			if (placement == nullptr) {
				return new T(std::move(*data));
			}
			return new (placement) T(std::move(*data));
		}
	};

	template <typename T>
	struct move_impl<T, false> {
		static T * move(T const * data, void * placement) {
			abort();
		}
	};

	template <typename T>
	static intptr_t op(operation o, void const * value, void * placement) {
		auto const data = static_cast<T const *>(value);
		switch (o) {
		case CLONE:
			return reinterpret_cast<intptr_t>(clone_impl<T, std::is_copy_constructible<T>::value>::clone(data, placement));
		case MOVE:
			return reinterpret_cast<intptr_t>(move_impl<T, std::is_move_constructible<T>::value>::move(data, placement));
		case DELETE:
			delete data; // virtual destruction is unneeded and bypassed because we always work with the most-derived perspective
			return 0;
		case DESTRUCT:
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

	static void * move(op_sig const & op_ptr, void const * value, void * placement) {
		return reinterpret_cast<void *>(op_ptr(MOVE, value, placement));
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

	template <typename T, typename = void>
	struct is_defined_impl : std::false_type { };

	template <typename T>
	struct is_defined_impl<T, typename std::enable_if<(sizeof(T) - sizeof(T)) == 0>::type> : std::true_type {};

	template <typename T>
	constexpr bool is_defined = is_defined_impl<T>::value;

	template <typename DefaultSize, typename T, typename = void>
	struct small_storage_size_impl : DefaultSize { };

	template <typename DefaultSize, typename T>
	struct small_storage_size_impl<DefaultSize, T, typename std::enable_if<is_defined<T>>::type> : std::integral_constant<size_t, sizeof(T)> {};

	template <size_t DefaultSize, typename T>
	constexpr size_t small_storage_size = small_storage_size_impl<std::integral_constant<size_t, DefaultSize>, T>::value;

	template <typename T, typename = void>
	struct emit_heap_warning_imp {
		static void emit_heap_warning(char const * const u_name) {
#if !NDEBUG
			std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is unknown. Type U is " << u_name << ".\n";
#endif
		}
	};

	template <typename T>
	struct emit_heap_warning_imp<T, typename std::enable_if<is_defined<T>, T>::type> {
		static void emit_heap_warning(char const * const u_name) {
#if !NDEBUG
			std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is " << typeid(T).name() << ". Type U is " << u_name << ".\n";
#endif
		}
	};

	template <typename T>
	void emit_heap_warning(char const * const u_name) {
		emit_heap_warning_imp<T>::emit_heap_warning(u_name);
	}

	template <typename T, typename U>
	void emit_heap_warning2() {
#if !NDEBUG
		std::cerr << "Warning: a val allocated heap storage. Use the SmallStorageSize type parameter to improve locality. Type T is " << typeid(T).name() << ". Type U is " << typeid(U).name() << ".\n";
#endif
	}
}

// non-nullable weak pointer to val objects
template <typename T>
class ptr {  // NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
	template <typename, size_t>
	friend class val;

	template <typename>
	friend class ptr;

	using descriptor_t = val_detail::descriptor_t;
	using block = val_detail::block;
	using op_sig = val_detail::block;

public:
	typedef T type;

	// copy constructor
	ptr(ptr const & other) {
		const descriptor_t d = other.get_descriptor();
		descriptor_ = d;
		descriptor_.block_ptr->increment();
	}

	ptr& operator =(ptr other) {
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
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr(ptr<U> const & other) {
		descriptor_ = other.get_descriptor();
		descriptor_.block_ptr->increment();
		descriptor_.upcast_offset += val_detail::compute_upcast_offset<T, U>;
	}

	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr& operator =(ptr<U> other) {
		auto new_descriptor = other.get_descriptor();
		new_descriptor.block_ptr->increment();
		new_descriptor.upcast_offset += val_detail::compute_upcast_offset<T, U>;
		auto old_descriptor = exchange_descriptor(new_descriptor);
		old_descriptor.block_ptr->decrement();
		return *this;
	}

	template <typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	ptr(val<U, SmallStorageSizeU> const & other) {
		descriptor_ = other.data.get_descriptor();
		descriptor_.block_ptr->increment();
		descriptor_.upcast_offset += val_detail::compute_upcast_offset<T, U>;
	}

	template <typename U, size_t SmallStorageSizeU, typename std::enable_if<std::is_base_of<U, T>::value && !std::is_same<U, T>::value, int>::type = 0>
	explicit ptr(val<U, SmallStorageSizeU> const & other) {
		auto result = dynamic_cast<T*>(&*other);
		if (result == nullptr) {
			throw;
		}
		descriptor_ = other.data.get_descriptor();
		descriptor_.block_ptr->increment();
		descriptor_.upcast_offset -= val_detail::compute_upcast_offset<T, U>;
	}

	template <typename U, typename std::enable_if<std::is_base_of<U, T>::value, int>::type = 0>
	explicit ptr(ptr<U> const & other) {
		U * result = dynamic_cast<U*>(&*other);
		if (result == nullptr) {
			throw;
		}
		descriptor_ = other.get_descriptor();
		descriptor_.block_ptr->increment();
		descriptor_.upcast_offset -= val_detail::compute_upcast_offset<T, U>;
	}

	T* operator ->() const {
		auto const d = get_descriptor();
		auto const data = d.block_ptr->data.load();
		assert(data != nullptr);
		auto result = reinterpret_cast<T *>(reinterpret_cast<int8_t *>(data) + d.upcast_offset);
		return result;
	}

	T& operator *() const {
		return *operator ->();
	}

private:
	descriptor_t descriptor_;
	mutable std::mutex m;

	explicit ptr(descriptor_t const & d) : descriptor_(d) {
		d.block_ptr->increment();
	}

	ptr(val_detail::block * b, size_t upcast_offset, val_detail::op_sig op_ptr) : descriptor_{ b, upcast_offset, op_ptr } {
		b->increment();
	}

	descriptor_t get_descriptor() const {
		std::unique_lock<std::mutex> lock(m);
		return descriptor_;
	}

	descriptor_t exchange_descriptor(descriptor_t const & v) {
		std::unique_lock<std::mutex> lock(m);
		const auto saved = descriptor_;
		descriptor_ = v;
		return saved;
	}

	descriptor_t clone(size_t upcast_offset, void * placement) const {
		const auto d = get_descriptor();
		if (placement == nullptr) {
			char const * const uName = val_detail::type(d.op_ptr);
			val_detail::emit_heap_warning<T>(uName);
		}
		const auto cloned = val_detail::clone(d.op_ptr, static_cast<void *>(d.block_ptr->data), placement);
		return descriptor_t{ new block(cloned), d.upcast_offset + upcast_offset, d.op_ptr };
	}

	size_t get_size_of_data() const {
		const auto d = get_descriptor();
		return size(d.op_ptr);
	}

};

template<typename T>
using nptr = std::optional<ptr<T>>;

// value semantic type erasure via base types
template<typename T, size_t SmallStorageSize = val_detail::small_storage_size<16, T>>
class val {  // NOLINT(cppcoreguidelines-special-member-functions, cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
	template <typename>
	friend class ptr;

	template <typename, size_t>
	friend class val;

	using descriptor_t = val_detail::descriptor_t;
	using block = val_detail::block;
	using op_sig = val_detail::block;

	void * emplacement_ptr(size_t dataSize) {
		if (dataSize <= SmallStorageSize) {
			return reinterpret_cast<void *>(&small_storage);
		}
		return nullptr;
	}

	template <typename U>
	typename std::remove_const<U>::type * construct(U const & other) {
		const auto ptr = emplacement_ptr(sizeof(U));
		if (ptr == nullptr) {
			val_detail::emit_heap_warning2<T, U>();
			return new typename std::remove_const<U>::type(other);
		}
		return new (ptr) typename std::remove_const<U>::type(other);
	}

	template <typename U>
	typename std::remove_const<U>::type * construct(U && other) {
		const auto ptr = emplacement_ptr(sizeof(U));
		if (ptr == nullptr) {
			val_detail::emit_heap_warning2<T, U>();
			return new typename std::remove_const<U>::type(std::forward<U>(other));
		}
		return new (ptr) typename std::remove_const<U>::type(std::forward<U>(other));
	}

public:
	typedef T type;
	static constexpr size_t small_storage_size = SmallStorageSize;

	// ReSharper disable CppPossiblyUninitializedMember
	// ReSharper disable CppNonExplicitConvertingConstructor
	val(T const & v) : data(new val_detail::block(construct(v)), 0, &val_detail::op<T>) {}

	val(T && v) : data(new val_detail::block(construct(std::move(v))), 0, &val_detail::op<T>) {}

	val(val const & other) : data(other.data.clone(0, emplacement_ptr(val_detail::small_storage_size<SIZE_MAX, T>))) {}

	val(T * v) : data(new val_detail::block(v), 0, &val_detail::op<T>) {}
	// construct from type U that inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	val(U const & v) : data(new val_detail::block(construct(v)), val_detail::compute_upcast_offset<T, U>, &val_detail::op<U>) {}

	// construct from type U that inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	// ReSharper disable once CppNonExplicitConvertingConstructor
	val(U && v) : data(new val_detail::block(construct(v)), val_detail::compute_upcast_offset<T, U>, &val_detail::op<U>) {}  // NOLINT(misc-forwarding-reference-overload)

	// construct from val<U> where U inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	explicit val(val<U> const & other) : data(other.data.clone(val_detail::compute_upcast_offset<T, U>, emplacement_ptr(other.data.get_size_of_data()))) {}

	// ReSharper restore CppPossiblyUninitializedMember
	// ReSharper restore CppNonExplicitConvertingConstructor

	~val() {
		auto d = data.get_descriptor();
		data.~ptr();
		if (d.block_ptr->count > 0) {
			abort(); // ptr objects still point to this value
		}
		assert(d.block_ptr != nullptr);
		void * buffer = nullptr;
		d.block_ptr->data = nullptr;
		d.block_ptr->data.exchange(buffer);
		if (buffer == &small_storage) {
			val_detail::destruct(d.op_ptr, buffer);
		} else {
			val_detail::delete_(d.op_ptr, buffer);
		}
	}

	// assignment from U where U inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	val& operator =(U const & newValue) {
		*data = newValue;
		return *this;
	}

	// assignment operator from val<U> where U inherits T
	template <typename U, typename std::enable_if<std::is_base_of<T, U>::value, int>::type = 0>
	val& operator =(val<U> rhs) {
		*data = *rhs;
		return *this;
	}

	//val& operator =(typename std::enable_if<std::is_base_of<T, T>::value, val>::type rhs) {
	//	*data = *rhs;
	//	return *this;
	//}

	T& operator *() { return *data; }
	T* operator ->() {
		T * const result = &*data;
		return result;
	}
	T const& operator *() const { return *data; }
	T const* operator ->() const { return &*data; }

	operator ptr<T>() {
		return data;
	}

	std::unique_ptr<T> clone() const {
		auto d = data.clone(0, nullptr);
		return std::unique_ptr<T>(reinterpret_cast<T*>(static_cast<int8_t*>(static_cast<void*>(d.block_ptr->data)) + d.upcast_offset));
	}

private:
	int8_t small_storage[SmallStorageSize];
	ptr<T> data;

};

template <typename T, typename... ArgTs>
val<T> make_val(ArgTs &&... args) {
	return val<T>(T(std::forward<ArgTs>(args)...));
}

#endif // INCLUDED_UTILITIES_VAL_HPP
