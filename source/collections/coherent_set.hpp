#ifndef COHERENT_SET_HPP
#define COHERENT_SET_HPP

// This collection is based on coherent_map. See it for more information

#include <cassert>
#include <iterator>

#include "coherent_map.hpp"

namespace collections {
	
	template<typename T, class TCompare = std::less<T>>
	class coherent_set {
		struct dummy {};

		typedef coherent_map<T, dummy, TCompare> storage_t;
		storage_t storage;

	public:
		template<typename U>
		class iterator_template {
			friend class coherent_set;
			typedef std::random_access_iterator_tag iterator_category;
			typedef U value_type;
			typedef U & reference;
			typedef U * pointer;
			template<typename V>
			friend class iterator_template;

			typedef std::conditional_t<std::is_const_v<U>, std::pair<T, dummy> const, std::pair<T, dummy>> underlying_element_t;
			typedef typename storage_t::template iterator_template<underlying_element_t> underlying_t;
			underlying_t underlying;

		public:
			iterator_template() = default;

			explicit iterator_template(underlying_t underlying) : underlying(underlying) {}

			iterator_template(iterator_template const & other) = default;
			iterator_template(iterator_template && other) = default;
			~iterator_template() = default;

			template<typename V>
			iterator_template& operator=(iterator_template<V> const & other) {
				underlying = other.underlying;
				return *this;
			}

			auto operator*() const {
				assert(underlying != underlying_t());
				return underlying->first;
			}

			auto operator->() const {
				return &operator*();
			}

			iterator_template& operator++() {
				++underlying;
				return *this;
			}

			iterator_template operator++(int) {
				iterator_template result = *this;
				++*this;
				return result;
			}

			iterator_template operator--() {
				--underlying;
				return *this;
			}

			iterator_template operator--(int) {
				iterator_template result = *this;
				--*this;
				return result;
			}

			iterator_template operator+(ptrdiff_t const rhs) const {
				iterator_template result;
				result.underlying = underlying + rhs;
				return result;
			}

			iterator_template operator-(ptrdiff_t const rhs) const {
				return *this + (-rhs);
			}

			ptrdiff_t operator-(iterator_template const & rhs) const {
				return underlying - rhs.underlying;
			}

			explicit operator iterator_template<const value_type>() const {
				return iterator_template<const value_type>(underlying);
			}

			template<typename V>
			bool operator==(iterator_template<V> const & rhs) {
				return underlying == rhs.underlying;
			}

			template<typename V>
			bool operator!=(iterator_template<V> const & rhs) {
				return !(*this == rhs);
			}

			friend void swap(iterator_template & lhs, iterator_template & rhs) noexcept {
				using std::swap; // bring in swap for built-in types
				swap(lhs.underlying, rhs.underlying);
			}
		};

		typedef T value_type;
		typedef value_type & reference;
		typedef const value_type & const_reference;
		typedef value_type * pointer;
		typedef value_type const * const_pointer;
		typedef iterator_template<value_type> iterator;
		typedef iterator_template<const value_type> const_iterator;

		coherent_set() = default;
		coherent_set(coherent_set const & other) = default;

		friend void swap(coherent_set & lhs, coherent_set & rhs) noexcept {
			using namespace std;
			swap(lhs.storage, rhs.storage);
		}

		void reserve(size_t count) {
			storage.reserve(count);
		}

		size_t size() const {
			return storage.size();
		}

		bool empty() const {
			return storage.empty();
		}

		size_t clear() {
			return storage.clear();			
		}

		std::pair<iterator, bool> insert(T const & v) {
			auto mapResult = storage.insert(std::make_pair(v, dummy()));
			return std::make_pair(iterator(mapResult.first), mapResult.second);
		}

		template<typename TIterator>
		size_t insert_many(TIterator const & begin, TIterator const & end) {
			std::vector<std::pair<T, dummy>> temp;
			temp.reserve(end - begin);
			for (auto i = begin; i != end; ++i) {
				temp.push_back(std::make_pair(*i, dummy()));
			}
			return storage.insert_many(temp.begin(), temp.end());
		}

		template<typename TIterator>
		size_t erase_many(TIterator const & begin, TIterator const & end) {
			return storage.erase_many(begin, end);
		}

		size_t erase(T const & key) {
			return storage.erase(key);
		}

		iterator begin() noexcept {
			return iterator(storage.begin());
		}

		const_iterator begin() const noexcept {
			return const_iterator(storage.cbegin());
		}

		const_iterator cbegin() const noexcept {
			return const_iterator(storage.cbegin());
		}

		iterator end() const noexcept {
			return iterator(storage.end());
		}

		size_t count(T const & v) const {
			return storage.count(v);
		}

	};
}

#endif //COHERENT_SET_HPP