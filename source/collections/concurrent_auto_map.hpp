#ifndef CONCURRENT_AUTO_MAP_HPP
#define CONCURRENT_AUTO_MAP_HPP

#include <functional>
#include <map>
#include <mutex>

/* concurrent_auto_map wraps wraps a std::map, using a value factory to instantiate default values, and mutex-based synchronization */

template <typename TKey, typename TValue>
class concurrent_auto_map {
	std::function<TValue (TKey const &)> value_factory;
	std::map<TKey, TValue> storage;
	mutable std::mutex mutex;
public:
	explicit concurrent_auto_map(std::function<TValue (TKey const &)> valueFactory) : value_factory(valueFactory) {
	}

	concurrent_auto_map() : value_factory([](TKey) { return TValue(); }) {
	}

	TValue const & operator()(TKey key) {
		std::unique_lock<std::mutex> lock(mutex);
		// only run value_factory if not found, i.e. no emplace_back
		auto i = storage.find(key);
		if (i == storage.end()) {
			TValue value = value_factory(key); 
			i = storage.insert(std::pair<TKey, TValue>(key, value)).first;
		}
		return i->second;
	}

	void set(TKey key, TValue value) {
		std::unique_lock<std::mutex> lock(mutex);
		storage[key] = value;
	}

};

#endif // CONCURRENT_AUTO_MAP_HPP
